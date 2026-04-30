include(ExportDirectory)
set(SOURCE_FILES
	bitmap-cache.cpp
	cache-set.cpp
	cheats.cpp
	config.cpp
	core.cpp
	directories.cpp
	input.cpp
	interface.cpp
	lockstep.cpp
	log.cpp
	map-cache.cpp
	mem-search.cpp
	rewind.cpp
	serialize.cpp
	sync.cpp
	thread.cpp
	tile-cache.cpp
	timing.cpp)

set(TEST_FILES
	test/core.cpp)

if(ENABLE_VFS)
		list(APPEND SOURCE_FILES
			library.cpp)
endif()

if(ENABLE_SCRIPTING)
	set(SCRIPTING_FILES
		scripting.c)

	if(USE_LUA)
		list(APPEND TEST_FILES
			test/scripting.c)
	endif()
endif()

source_group("mCore" FILES ${SOURCE_FILES})
source_group("mCore scripting" FILES ${SCRIPTING_FILES})
source_group("mCore tests" FILES ${TEST_FILES})

export_directory(CORE SOURCE_FILES)
export_directory(CORE_SCRIPT SCRIPTING_FILES)
export_directory(CORE_TEST TEST_FILES)
