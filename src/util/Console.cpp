#include "util/Console.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

void Console::Clear() noexcept {
	std::system("cls");
}

void Console::Pass() noexcept {
	std::cout << "Press Enter and pass the move to another player\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	Clear();
}
