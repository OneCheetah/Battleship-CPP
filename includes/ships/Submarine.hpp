#pragma once

#include "../Ship.hpp"

class Submarine final : public Ship {
 public:
  explicit Submarine();
	~Submarine() override = default;
};