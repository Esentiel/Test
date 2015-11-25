cmake_minimum_required (VERSION 2.6)
project (Test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g")
#versions
set (Test_VERSION_MAJOR 1)
set (Test_VERSION_MINOR 0)

#binary tree
include_directories ("${PROJECT_BINARY_DIR}")

#executable
#add_executable (Test Source.cpp)

#headers
set(SOURCES Cell.cpp Factory.cpp FormulaCell.cpp NoneCell.cpp NumberCell.cpp Parser.cpp ReversePolandNotation.cpp StringCell.cpp UserInterface.cpp Source.cpp Variant.cpp Cell.h Factory.h FormulaCell.h NoneCell.h NumberCell.h Parser.h ReversePolandNotation.h StringCell.h UserInterface.h Variant.h)
add_executable(Test ${SOURCES})
