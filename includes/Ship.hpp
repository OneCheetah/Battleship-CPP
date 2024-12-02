#pragma once

#include <functional>
#include <optional>
#include <string>
#include <vector>

using ConstCharRef = std::reference_wrapper<const char>;

class Ship {

	std::string name_;
	size_t size_;
	std::optional<std::vector<ConstCharRef>> coordinates_ = std::nullopt;


protected:
	explicit Ship(std::string name, size_t size) noexcept;


public:
	[[nodiscard]] bool IsSunk() const noexcept;
	[[nodiscard]] std::string GetName() const noexcept;
	[[nodiscard]] size_t GetSize() const noexcept;

	void SetCoordinates(std::vector<ConstCharRef>&& coordinates);

	virtual ~Ship() = default;
};
