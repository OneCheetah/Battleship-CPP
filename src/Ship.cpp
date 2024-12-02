#include "Ship.hpp"

#include <algorithm>
#include <iostream>
#include "grid/CellState.hpp"

Ship::Ship(std::string name, const size_t size) noexcept
	: name_(std::move(name)), size_(size) {
}

bool Ship::IsSunk() const noexcept {
	if (!coordinates_.has_value()) {
		return false;
	}

	return std::ranges::all_of(coordinates_.value(), [](auto const& coordinate) {
		return coordinate.get() == static_cast<char>(CellState::HIT);
	});
}

std::string Ship::GetName() const noexcept {
	return name_;
}

size_t Ship::GetSize() const noexcept {
	return size_;
}

void Ship::SetCoordinates(std::vector<ConstCharRef>&& coordinates) {
	coordinates_ = std::move(coordinates);
}