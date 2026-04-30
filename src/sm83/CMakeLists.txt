include(ExportDirectory)
set(SOURCE_FILES
	decoder.cpp
	isa-sm83.cpp
	sm83.cpp)

set(DEBUGGER_FILES
	debugger/cli-debugger.cpp
	debugger/debugger.cpp
	debugger/memory-debugger.cpp)

source_group("SM83 core" FILES ${SOURCE_FILES})
source_group("SM83 debugger" FILES ${DEBUGGER_FILES})

export_directory(SM83 SOURCE_FILES)
export_directory(SM83_DEBUGGER DEBUGGER_FILES)
