include_directories(
	Console_Functions
	Game
	Snake
	Infos
	Map
	Functions
	Food
	Block
	Animation
	Printer
	Types
	Log
	Utilities
	)

set(Utilities
	Utilities/Utilities.hpp
	Utilities/Utilities.cpp
	)
	
set (Types
	Types/Types.h
	Types/Types.cpp
	)
	
set (ConsoleFunc
	Console_Functions/Console_Functions.h
	Console_Functions/Console_Functions.cpp
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
	Infos/Information.h
	Infos/Information.cpp
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
	
set(Functions
	Functions/Functions.h
	Functions/Functions.cpp
	)
	
set(Block
	Block/Block.cpp
	Block/Block.hpp
	Block/SquareBlock.h
	Block/SquareBlock.cpp
	)

set(Animation
	Animation/Animation.cpp
	Animation/Animation.h
	)

set (Printer
	Printer/Printer.cpp
	Printer/Printer.h
	)
	
set (Log
	Log/Log.cpp
	Log/Log.hpp
	)
	
set(Include_Dir
	${ConsoleFunc}
	${Game}
	${Snake}
	${Map}
	${Infos}
	${Food}
	${Functions}
	${Block}
	${Object}
	${Animation}
	${Printer}
	${Types}
	${Log}
	${Utilities}
	)	
	
set(Main
	Main/main.cpp
	${Include_Dir}
	)
	
source_group ("Main" FILES ${Main})
source_group ("Block" FILES ${Block})
source_group ("Console Functions" FILES ${ConsoleFunc})
source_group ("Game" FILES ${Game})
source_group ("Snake" FILES ${Snake})
source_group ("Infos" FILES ${Infos})
source_group ("Map" FILES ${Map})
source_group ("Food" FILES ${Food})
source_group ("Functions" FILES ${Functions})
source_group ("Animation" FILES ${Animation})
source_group ("Printer" FILES ${Printer})
source_group ("Types" FILES ${Types})
source_group ("Log" FILES ${Log})
source_group ("Utilities" FILES ${Utilities})

add_executable (Snake_Game ${Main})

install (TARGETS Snake_Game DESTINATION Snake_Game)
#install (FILES "${CMAKE_CURRENT_SOURCE_DIR}/Main/main.cpp" DESTINATION Headers)
#install (FILES "${CMAKE_CURRENT_SOURCE_DIR}/Console_Functions/Console_Functions.h" DESTINATION Headers)
	
set_property (DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Snake_Game)