cmake_minimum_required(VERSION 3.30)
project(Battleship)

set(CMAKE_CXX_STANDARD 20)

include_directories("includes")

set(BATTLESHIP_INCLUDES
        "includes/ships/AircraftCarrier.hpp"
        "includes/ships/Battleship.hpp"
        "includes/ships/Cruiser.hpp"
        "includes/ships/Destroyer.hpp"
        "includes/ships/Submarine.hpp"
        "includes/Grid.hpp"
        "includes/Ship.hpp"
        "includes/util/Coordinate.hpp"
        "includes/Player.hpp"
        "includes/grid/ShadowGrid.hpp"
        "includes/grid/BattleGrid.hpp"
        "includes/grid/CellState.hpp"
        "includes/util/Console.hpp"
        "includes/GameController.hpp"
)

set(BATTLESHIP_SOURCES
        "src/ships/AircraftCarrier.cpp"
        "src/ships/Battleship.cpp"
        "src/ships/Cruiser.cpp"
        "src/ships/Destroyer.cpp"
        "src/ships/Submarine.cpp"
        "src/Grid.cpp"
        "src/Ship.cpp"
        "src/util/Coordinate.cpp"
        "src/Player.cpp"
        "src/grid/ShadowGrid.cpp"
        "src/grid/BattleGrid.cpp"
        "src/util/Console.cpp"
        "src/GameController.cpp"
)

if (MSVC)
    add_compile_options("/EHs")
endif ()

add_executable(Battleship "src/main.cpp" ${BATTLESHIP_INCLUDES} ${BATTLESHIP_SOURCES})
