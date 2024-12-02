#include "grid/BattleGrid.hpp"

BattleGrid::BattleGrid() = default;
BattleGrid::~BattleGrid() = default;

bool BattleGrid::IsValidPlacement(Coordinate const& start, Coordinate const& end,
                                  const size_t size) {
	if (!Coordinate::IsHorizontal(start, end) && !Coordinate::IsVertical(start, end)) {
		std::cout << "Error! Wrong ship location! Try again:\n";
		return false;
	}

	if (const auto dist = Coordinate::Distance(start, end); dist != static_cast<double>(size)) {
		std::cout << "Error: Invalid ship size! Expected: " << size << ", Got: " << dist <<
			".  Please check the ship dimensions.\n";
		return false;
	}

	return true;
}

bool BattleGrid::IsOccupied(Coordinate const& start, Coordinate const& end) const {
	if (Coordinate::IsHorizontal(start, end)) {
		for (int i = start.GetRow() - 1; i <= start.GetRow() + 1; ++i) {
			for (int j = start.GetColumn() - 1; j <= end.GetColumn() + 1; ++j) {
				if (i < 0 || i >= kGridSize || j < 0 || j >= kGridSize) {
					continue;
				}
				if (grid_[i][j] == static_cast<char>(CellState::SHIP)) {
					std::cout << "Error! You placed it too close to another one. Try again:\n";
					return true;
				}
			}
		}

		return false;
	}
	if (Coordinate::IsVertical(start, end)) {
		for (int i = start.GetRow() - 1; i <= end.GetRow() + 1; ++i) {
			for (int j = start.GetColumn() - 1; j <= start.GetColumn() + 1; ++j) {
				if (i < 0 || i >= kGridSize || j < 0 || j >= kGridSize) {
					continue;
				}
				if (grid_[i][j] == static_cast<char>(CellState::SHIP)) {
					std::cout << "Error! You placed it too close to another one. Try again:\n";
					return true;
				}
			}
		}

		return false;
	}

	// The ship is diagonal and not aligned correctly
	return true;
}


std::optional<std::vector<ConstCharRef>> BattleGrid::PlaceShip(const std::string_view start,
                                                               const std::string_view end,
                                                               const size_t size) {
	std::unique_ptr<Coordinate> start_pos = Coordinate::FromString(start);
	std::unique_ptr<Coordinate> end_pos = Coordinate::FromString(end);


	if (!start_pos || !end_pos) {
		return std::nullopt;
	}

	if (*start_pos > *end_pos) {
		std::swap(start_pos, end_pos);
	}

	if (!IsValidPlacement(*start_pos, *end_pos, size) || IsOccupied(*start_pos, *end_pos)) {
		return std::nullopt;
	}

	std::vector<ConstCharRef> coordinates{};
	if (Coordinate::IsHorizontal(*start_pos, *end_pos)) {
		for (int col = start_pos->GetColumn(); col <= end_pos->GetColumn(); ++col) {
			coordinates.emplace_back(
				grid_.at(start_pos->GetRow()).at(col) = static_cast<char>(CellState::SHIP));
		}
	} else if (Coordinate::IsVertical(*start_pos, *end_pos)) {
		for (int row = start_pos->GetRow(); row <= end_pos->GetRow(); ++row) {
			coordinates.emplace_back(
				grid_.at(row).at(start_pos->GetColumn()) = static_cast<char>(CellState::SHIP));
		}
	} else {
		return std::nullopt;
	}
	return std::make_optional(coordinates);
}

std::optional<bool> BattleGrid::IsAlreadyHit(const std::string_view coordinate) const {
	const std::unique_ptr<Coordinate> pos = Coordinate::FromString(coordinate);
	if (!pos) {
		return std::nullopt;
	}
	return grid_.at(pos->GetRow()).at(pos->GetColumn()) == static_cast<char>(CellState::HIT)
	 || grid_.at(pos->GetRow()).at(pos->GetColumn()) == static_cast<char>(CellState::MISS);
}

std::optional<bool> BattleGrid::Attack(const std::string_view coordinate) {
	const std::unique_ptr<Coordinate> pos = Coordinate::FromString(coordinate);

	if (!pos) {
		return std::nullopt;
	}

	if (IsAlreadyHit(coordinate).value()) {
		std::cout << "You've already guessed this cell. Try again:\n";
		return std::nullopt;
	}

	bool is_hit = grid_.at(pos->GetRow()).at(pos->GetColumn()) == static_cast<char>(
		CellState::SHIP);
	if (is_hit) {
		grid_.at(pos->GetRow()).at(pos->GetColumn()) = static_cast<char>(CellState::HIT);
	} else {
		grid_.at(pos->GetRow()).at(pos->GetColumn()) = static_cast<char>(CellState::MISS);
	}

	return is_hit;
}
