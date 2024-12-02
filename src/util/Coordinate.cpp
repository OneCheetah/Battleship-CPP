#include "util/Coordinate.hpp"

#include <cmath>

Coordinate::Coordinate(const long row, const long col) : row_(row), col_(col) {
}

std::unique_ptr<Coordinate> Coordinate::FromString(const std::string_view str) {
	// The coordinate should be in the format of a letter followed by a number between 1 and 10
	// Example: A1, B2, C3, D4, E5, F6, G7, H8, I9, J10
	if (str.size() > 3 or str.size() < 2) {
		return nullptr;
	}

	try {
		// The column is the first character of the coordinate
		const char kCol = str.at(0);
		// The row is the rest of the characters in the coordinate
		const long kRow = std::stol(str.substr(1).data());

		// The column should be a letter between A and J and the row should be a number between 1 and 10
		if (kRow < 1 || kRow > 10 || kCol < 'A' || kCol > 'J') {
			return nullptr;
		}

		return std::make_unique<Coordinate>(kCol - 'A', kRow - 1);
	} catch ([[maybe_unused]] std::invalid_argument const& e) {
		// The row is not a number
		return nullptr;
	}
}

long Coordinate::GetRow() const noexcept {
	return this->row_;
}

long Coordinate::GetColumn() const noexcept {
	return this->col_;
}

double Coordinate::Distance(Coordinate const& start, Coordinate const& end) noexcept {
	return std::sqrt(std::pow(end.row_ - start.row_, 2) + std::pow(end.col_ - start.col_, 2)) + 1;
}

double Coordinate::Displacement() const noexcept {
	return std::sqrt(std::pow(this->row_, 2) + std::pow(this->col_, 2));
}

bool Coordinate::IsHorizontal(Coordinate const& start, Coordinate const& end) noexcept {
	return start.row_ == end.row_ && start.col_ != end.col_;
}

bool Coordinate::IsVertical(Coordinate const& start, Coordinate const& end) noexcept {
	return start.col_ == end.col_ && start.row_ != end.row_;
}
