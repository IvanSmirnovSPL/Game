include_directories(${HEADER_DIR})

set(source
	main.cpp
	classes/game.cpp
)

add_executable(game ${source})