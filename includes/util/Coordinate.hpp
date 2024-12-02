#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <stdexcept>

class Coordinate {
private:
	long row_;
	long col_;

	[[nodiscard]] double Displacement() const noexcept;

public:
	explicit Coordinate(long row, long col);

	[[nodiscard]] static std::unique_ptr<Coordinate> FromString(std::string_view str);
	[[nodiscard]] static double Distance(Coordinate const& start, Coordinate const& end) noexcept;
	[[nodiscard]] static bool IsHorizontal(Coordinate const& start, Coordinate const& end) noexcept;
	[[nodiscard]] static bool IsVertical(Coordinate const& start, Coordinate const& end) noexcept;

	[[nodiscard]] long GetRow() const noexcept;
	[[nodiscard]] long GetColumn() const noexcept;

	[[nodiscard]] friend bool operator==(Coordinate const& lhs, Coordinate const& rhs) {
		return lhs.row_ == rhs.row_ && lhs.col_ == rhs.col_;
	}

	[[nodiscard]] friend bool operator!=(Coordinate const& lhs, Coordinate const& rhs) {
		return !(lhs == rhs);
	}

	[[nodiscard]] friend bool operator<(Coordinate const& lhs, Coordinate const& rhs) {
		return lhs.Displacement() < rhs.Displacement();
	}

	[[nodiscard]] friend bool operator>(Coordinate const& lhs, Coordinate const& rhs) {
		return rhs < lhs;
	}

	[[nodiscard]] friend bool operator<=(Coordinate const& lhs, Coordinate const& rhs) {
		return !(lhs > rhs);
	}

	[[nodiscard]] friend bool operator>=(Coordinate const& lhs, Coordinate const& rhs) {
		return !(lhs < rhs);
	}

};
