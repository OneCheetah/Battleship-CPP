#include "grid/ShadowGrid.hpp"
#include "util/Coordinate.hpp"

ShadowGrid::ShadowGrid() = default;
ShadowGrid::~ShadowGrid() = default;


std::optional<bool> ShadowGrid::Mark(const std::string_view coordinate, const char mark) {
	const std::unique_ptr<Coordinate> coord = Coordinate::FromString(coordinate);
	//
	// if (!coord) {
	// 	return std::nullopt;
	// }

	grid_.at(coord->GetRow()).at(coord->GetColumn()) = mark;

	return true; // Return true if the mark was successful
}
