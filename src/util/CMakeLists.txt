include(ExportDirectory)
set(BASE_SOURCE_FILES
	circle-buffer.cpp
	configuration.cpp
	crc32.cpp
	formatting.cpp
	gbk-table.cpp
	hash.cpp
	md5.cpp
	sha1.cpp
	string.cpp
	table.cpp
	vector.cpp
	vfs.cpp)

set(SOURCE_FILES
	${BASE_SOURCE_FILES}
	audio-buffer.cpp
	audio-resampler.cpp
	convolve.cpp
	elf-read.cpp
	geometry.cpp
	image.cpp
	image/export.cpp
	image/font.cpp
	image/png-io.cpp
	interpolator.cpp
	patch.cpp
	patch-fast.cpp
	patch-ips.cpp
	patch-ups.cpp
	ring-fifo.cpp
	sfo.cpp
	text-codec.cpp)

set(GUI_FILES
	gui.cpp
	gui/file-select.cpp
	gui/font.cpp
	gui/font-metrics.cpp
	gui/menu.cpp)

set(TEST_FILES
	test/circle-buffer.cpp
	test/color.cpp
	test/geometry.cpp
	test/hash.cpp
	test/image.cpp
	test/sfo.cpp
	test/string-parser.cpp
	test/string-utf8.cpp
	test/table.cpp
	test/text-codec.cpp
	test/vfs.cpp)

if(NOT DEFINED OS_SRC)
	set(OS_FILES memory.cpp)
	export_directory(OS OS_FILES)
endif()

source_group("Utilities" FILES ${SOURCE_FILES})
source_group("GUI source" FILES ${GUI_FILES})
source_group("Utilities tests" FILES ${TEST_FILES})

export_directory(UTIL_BASE BASE_SOURCE_FILES)
export_directory(UTIL SOURCE_FILES)
export_directory(GUI GUI_FILES)
export_directory(UTIL_TEST TEST_FILES)
