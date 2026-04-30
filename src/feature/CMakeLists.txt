include(ExportDirectory)
set(SOURCE_FILES
	commandline.cpp
	proxy-backend.cpp
	thread-proxy.cpp
	video-backend.cpp
	video-logger.cpp)

if(ENABLE_VFS)
	list(APPEND SOURCE_FILES
		updater.cpp)
endif()

set(GUI_FILES
	gui/cheats.c
	gui/gui-config.c
	gui/gui-runner.c
	gui/remap.c)

source_group("Extra features" FILES ${SOURCE_FILES})
source_group("Extra GUI source" FILES ${GUI_FILES})

export_directory(EXTRA SOURCE_FILES)
export_directory(EXTRA_GUI GUI_FILES)
