include_directories(
	Console_Functions
	Controls
	Game
	Snake
	Infos
	Map
	Functions
	Food
	Block
	)

set(ConsoleFunc
	Console_Functions/Console_Functions.h
	Console_Functions/Console_Functions.cpp
	)
	
set (Controls
	Controls/Controls.h
	Controls/Controls.cpp
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
	Infos/Informations.h
	Infos/Informations.cpp
	)
	
set (Map
	Map/Map.h
	Map/Map.cpp
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
	Block/Block.h
	)
	
set(Include_Dir
	${ConsoleFunc}
	${Controls}
	${Game}
	${Snake}
	${Map}
	${Infos}
	${Food}
	${Functions}
	${Block}
	)	
	
set(Main
	Main/main.h
	Main/main.cpp
	${Include_Dir}
	)
	
source_group ("Main" FILES ${Main})
source_group ("Block" FILES ${Block})
source_group ("Console Functions" FILES ${ConsoleFunc})
source_group ("Controls" FILES ${Controls})
source_group ("Game" FILES ${Game})
source_group ("Snake" FILES ${Snake})
source_group ("Infos" FILES ${Infos})
source_group ("Map" FILES ${Map})
source_group ("Food" FILES ${Food})
source_group ("Functions" FILES ${Functions})

add_executable (Snake_Game ${Main})

install (TARGETS Snake_Game DESTINATION Snake_Game)
#install (FILES "${CMAKE_CURRENT_SOURCE_DIR}/Main/main.cpp" DESTINATION Headers)
#install (FILES "${CMAKE_CURRENT_SOURCE_DIR}/Console_Functions/Console_Functions.h" DESTINATION Headers)
	
set_property (DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Snake_Game)