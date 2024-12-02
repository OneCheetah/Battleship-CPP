#pragma once

class Console {
public:
	Console() = delete;
	~Console() = delete;

	static void Clear() noexcept;
	static void Pass() noexcept;
};