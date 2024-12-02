#pragma once

#include <array>
#include <iostream>

#include "Ship.hpp"
#include "grid/CellState.hpp"

class Grid {
public:
	static constexpr size_t kGridSize = 10;

protected:
	std::array<std::array<char, kGridSize>, kGridSize> grid_{{}};
	Grid();

public:
	friend std::ostream& operator<<(std::ostream& os, const Grid& grid) {
		os << "  1 2 3 4 5 6 7 8 9 10\n";
		for (int i = 0; i < kGridSize; ++i) {
			os << static_cast<char>('A' + i) << ' ';
			for (int j = 0; i < kGridSize; ++j) {
				if (j == kGridSize - 1) {
					os << grid.grid_.at(i).at(j);
					break;
				}
				os << grid.grid_.at(i).at(j) << ' ';
			}
			os << '\n';
		}
		return os;
	}

	virtual ~Grid() = default;
};
