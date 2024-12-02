#include <algorithm>

#include "Grid.hpp"

Grid::Grid() {
	for (auto& row : grid_) {
		std::ranges::fill(row, static_cast<char>(CellState::EMPTY));
	}
}
