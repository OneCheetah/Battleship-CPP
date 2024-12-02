#include "GameController.hpp"

#include "ships/AircraftCarrier.hpp"
#include "ships/Battleship.hpp"
#include "ships/Cruiser.hpp"
#include "ships/Destroyer.hpp"
#include "ships/Submarine.hpp"

#include <memory>

int main() {
	const std::vector<std::shared_ptr<Ship>> player1_ships = {
		std::make_shared<AircraftCarrier>(),
		std::make_shared<Battleship>(),
		std::make_shared<Submarine>(),
		std::make_shared<Cruiser>(),
		std::make_shared<Destroyer>(),
	};

	const std::vector<std::shared_ptr<Ship>> player2_ships = {
		std::make_shared<AircraftCarrier>(),
		std::make_shared<Battleship>(),
		std::make_shared<Submarine>(),
		std::make_shared<Cruiser>(),
		std::make_shared<Destroyer>(),
	};


	GameController game_controller(player1_ships, player2_ships);
	game_controller.Start();
}
