#pragma once

#include "../Ship.hpp"

class Battleship final : public Ship  {
public:
    explicit Battleship();
	~Battleship() override = default;
};