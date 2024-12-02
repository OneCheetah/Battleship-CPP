#pragma once
#include "Grid.hpp"

class ShadowGrid final : public Grid  {
public:
	explicit ShadowGrid();
	~ShadowGrid() override;

	std::optional<bool> Mark(std::string_view coordinate, char mark);
};