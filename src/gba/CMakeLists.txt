include(ExportDirectory)
set(SOURCE_FILES
	gb-audio.cpp
	audio.cpp
	bios.cpp
	cart/ereader.cpp
	cart/gpio.cpp
	cart/matrix.cpp
	cart/unlicensed.cpp
	cart/vfame.cpp
	cheats.cpp
	cheats/codebreaker.cpp
	cheats/gameshark.cpp
	cheats/parv3.c
	core.cpp
	dma.cpp
	gba.cpp
	hle-bios.cpp
	input.cpp
	io.cpp
	memory.cpp
	overrides.cpp
	renderers/cache-set.cpp
	renderers/common.cpp
	renderers/gl.cpp
	renderers/software-bg.cpp
	renderers/software-mode0.cpp
	renderers/software-obj.cpp
	renderers/video-software.cpp
	savedata.cpp
	serialize.cpp
	sharkport.cpp
	sio.cpp
	sio/gbp.cpp
	timer.cpp
	video.cpp)

set(SIO_FILES
	sio/dolphin.cpp
	sio/lockstep.c)

set(EXTRA_FILES
	extra/battlechip.cpp
	extra/proxy.cpp)

set(DEBUGGER_FILES
	debugger/cli.cpp)

set(TEST_FILES
	test/cheats.cpp
	test/core.cpp)

source_group("GBA board" FILES ${SOURCE_FILES})
source_group("GBA extras" FILES ${EXTRA_FILES} ${SIO_FILES})
source_group("GBA debugger" FILES ${DEBUGGER_FILES})
source_group("GBA tests" FILES ${TEST_FILES})

export_directory(GBA SOURCE_FILES)
export_directory(GBA_SIO SIO_FILES)
export_directory(GBA_EXTRA EXTRA_FILES)
export_directory(GBA_DEBUGGER DEBUGGER_FILES)
export_directory(GBA_TEST TEST_FILES)
