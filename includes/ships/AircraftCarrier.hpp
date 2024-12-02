#pragma once

#include "../Ship.hpp"

class AircraftCarrier final : public Ship {
public:
    explicit AircraftCarrier();
	~AircraftCarrier() override = default;
};