#include "Player.hpp"

#include <ranges>
#include <utility>

Player::Player(std::string name, std::vector<std::shared_ptr<Ship>> ships) noexcept :
	name_(std::move(name)), ships_(std::move(ships)) {
}

std::string Player::GetName() const noexcept {
	return name_;
}

void Player::PlaceShips() noexcept {
	for (int i = 0; i < ships_.size(); ++i) {
		std::string first_coordinate{};
		std::string second_coordinate{};
		std::cout << "Enter the coordinates of the " << ships_.at(i)->GetName() << " (" << ships_.
			at(i)->GetSize()
			<< " cells):\n";
		std::getline(std::cin, first_coordinate, ' ');
		std::getline(std::cin, second_coordinate);
		auto result = player_grid_.PlaceShip(first_coordinate, second_coordinate,
		                                     ships_.at(i)->GetSize());
		if (!result.has_value()) {
			--i;
			continue;
		}
		ships_[i]->SetCoordinates(std::move(result.value()));
		std::cout << "\n" << player_grid_ << "\n";
	}
}

bool Player::Attack(Player& opponent) noexcept {
	std::cout << opponent_grid_ << "---------------------\n" << player_grid_ << "\n";

	std::cout << name_ << ", it's your turn!\n";

	std::optional<bool> result;
	std::string coordinate{};
	do {
		std::getline(std::cin, coordinate);
		result = opponent.player_grid_.Attack(coordinate);
		if (!result.has_value()) {
			std::cout << "Invalid coordinate! Try again\n";
		}
	} while (!result.has_value());

	if (result.value()) {
		opponent_grid_.Mark(coordinate, static_cast<char>(CellState::HIT));
		return true;
	}
	opponent_grid_.Mark(coordinate, static_cast<char>(CellState::MISS));
	return false;
}

bool Player::IsDefeated() const noexcept {
	return std::ranges::all_of(ships_, [](auto const& ship) {
		return ship->IsSunk();
	});
}

std::vector<std::shared_ptr<Ship>> Player::GetShips() const noexcept {
	return ships_;
}

void Player::IncreaseSunkShips() noexcept {
	++this->ships_sunk_;
}

int Player::GetSunkShips() const noexcept {
	return ships_sunk_;
}
