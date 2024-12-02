#pragma once
#include "Player.hpp"
#include "ships/Battleship.hpp"

class GameController {
private:
	using Fleet = std::vector<std::shared_ptr<Ship>>;
	Player player1_;
	Player player2_;
	Fleet ships_;


	static void PlaceShips(Player& player);
	void Fight();
	[[nodiscard]] static bool SunkShips(Player& player);
	static void HandleAttackResult(Player& attacker, Player& defender);


public:
	explicit GameController(Fleet player1_ships, Fleet player2_ships);
	void Start();
};
