include_directories(
	Animation
	Block
	Console
	Food
	Game
	Infos
	Main
	Map
	Printer
	Snake	
	Types
	Utilities
	)

set (Utilities
	Utilities/Utilities.hpp
	Utilities/Utilities.cpp
	)

set (Types
	Types/Types.h
	Types/Types.cpp
	)
	
set (Console
	Console/Console.hpp
	Console/Console.cpp
	)

set (Game
	Game/Game.h
	Game/Game.cpp
	)

set (Snake
	Snake/Snake.h
	Snake/Snake.cpp
	)

set (Infos
	Infos/Highscore.hpp
	Infos/Highscore.cpp
	Infos/MenuItem.hpp
	Infos/MenuItem.cpp
	)

set (Map
	Map/Map.h
	Map/Map.cpp
	Map/Playground.hpp
	Map/Playground.cpp
	Map/Wall.hpp
	Map/Wall.cpp
	)

set (Food
	Food/Food.h
	Food/Food.cpp
	)

set (Block
	Block/Block.cpp
	Block/Block.hpp
	Block/SquareBlock.h
	Block/SquareBlock.cpp
	)

set (Animation
	Animation/Animation.cpp
	Animation/Animation.h
	)

set (Printer
	Printer/Printer.cpp
	Printer/Printer.h
	)

set(Include_Dir
	${Console}
	${Game}
	${Snake}
	${Map}
	${Infos}
	${Food}
	${Block}
	${Animation}
	${Printer}
	${Types}
	${Utilities}
	)

set(Main
	Main/main.cpp
	${Include_Dir}
	)

#open the c++ files from VS
source_group ("Main" FILES ${Main})
source_group ("Block" FILES ${Block})
source_group ("Console" FILES ${Console})
source_group ("Game" FILES ${Game})
source_group ("Snake" FILES ${Snake})
source_group ("Infos" FILES ${Infos})
source_group ("Map" FILES ${Map})
source_group ("Food" FILES ${Food})
source_group ("Animation" FILES ${Animation})
source_group ("Printer" FILES ${Printer})
source_group ("Types" FILES ${Types})
source_group ("Utilities" FILES ${Utilities})

add_executable (SnakeGame ${Main})

install (TARGETS SnakeGame DESTINATION SnakeGame)

set_property (DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SnakeGame)
 
