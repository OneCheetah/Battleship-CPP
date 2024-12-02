#pragma once

#include "../Ship.hpp"

class Destroyer final : public Ship {
 public:
    explicit Destroyer();
	~Destroyer() override = default;
};