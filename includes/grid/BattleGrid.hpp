#pragma once

#include <optional>

#include "util/Coordinate.hpp"
#include "Grid.hpp"

class BattleGrid final : public Grid {
public:
	explicit BattleGrid();
	~BattleGrid() override;


private:
	[[nodiscard]] static bool IsValidPlacement(Coordinate const& start, Coordinate const& end,
	                                           size_t size);
	[[nodiscard]] bool IsOccupied(Coordinate const& start, Coordinate const& end) const;


public:
	[[nodiscard]] std::optional<std::vector<ConstCharRef>> PlaceShip(
		std::string_view start, std::string_view end,
		size_t size);
	[[nodiscard]] std::optional<bool> IsAlreadyHit(std::string_view coordinate) const;
	[[nodiscard]] std::optional<bool> Attack(std::string_view coordinate);
};
