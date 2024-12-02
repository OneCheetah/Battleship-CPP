#pragma once

#include <string>
#include "grid/BattleGrid.hpp"
#include "Grid.hpp"
#include "grid/ShadowGrid.hpp"

class Player {
private:
	std::string name_;
	BattleGrid player_grid_;
	ShadowGrid opponent_grid_;
	std::vector<std::shared_ptr<Ship>> ships_;
	int ships_sunk_{};

public:
	explicit Player(std::string name, std::vector<std::shared_ptr<Ship>> ships) noexcept;

	[[nodiscard]] std::string GetName() const noexcept;

	void PlaceShips() noexcept;
	bool Attack(Player& opponent) noexcept;
	[[nodiscard]] bool IsDefeated() const noexcept;
	void IncreaseSunkShips() noexcept;

	[[nodiscard]] int GetSunkShips() const noexcept;
	[[nodiscard]] std::vector<std::shared_ptr<Ship>> GetShips() const noexcept;
};

