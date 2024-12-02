#include "GameController.hpp"
#include "util/Console.hpp"

GameController::GameController(Fleet player1_ships, Fleet player2_ships) :
	player1_("Player 1", std::move(player1_ships)), player2_("Player 2", std::move(player2_ships)) {
}

void GameController::PlaceShips(Player& player) {
	std::cout << player.GetName() << ", place your ships on the game field\n";
	player.PlaceShips();
}

bool GameController::SunkShips(Player& player) {
	int counter{};

	for (auto const ship : player.GetShips()) {
		if (ship->IsSunk()) {
			++counter;
		}
	}
	if (counter > player.GetSunkShips()) {
		player.IncreaseSunkShips();
		return true;
	}
	return false;
}

void GameController::HandleAttackResult(Player& attacker, Player& defender) {
	if (const bool result = attacker.Attack(defender); result && SunkShips(defender)) {
		std::cout << attacker.GetName() << " sunk a ship!\n";
	} else if (result) {
		std::cout << attacker.GetName() << " hit a ship!\n";
	} else {
		std::cout << attacker.GetName() << " missed!\n";
	}
}

void GameController::Fight() {
	int rounds = 0;
	while (true) {
		// Alternate players using rounds % 2 to decide which player attacks
		Player& attacker = rounds % 2 == 0 ? player1_ : player2_;
		Player& defender = rounds % 2 == 0 ? player2_ : player1_;

		HandleAttackResult(attacker, defender);

		if (player1_.IsDefeated()) {
			std::cout << player2_.GetName() << " wins!";
			break;
		}
		if (player2_.IsDefeated()) {
			std::cout << player1_.GetName() << " wins!";
			break;
		}

		++rounds;
		Console::Pass();
	}
}

void GameController::Start() {
	PlaceShips(this->player1_);
	Console::Pass();
	PlaceShips(this->player2_);
	Console::Pass();
	Fight();
}
