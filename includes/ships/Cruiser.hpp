#pragma once

#include "../Ship.hpp"

class Cruiser final : public Ship {
public:
    explicit Cruiser();
	~Cruiser() override = default;
};