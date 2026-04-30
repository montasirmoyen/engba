include(ExportDirectory)
set(SOURCE_FILES
	arm.cpp
	decoder-arm.cpp
	decoder.cpp
	decoder-thumb.cpp
	isa-arm.cpp
	isa-thumb.cpp)

set(DEBUGGER_FILES
	debugger/cli-debugger.cpp
	debugger/debugger.cpp
	debugger/memory-debugger.cpp)

source_group("ARM core" FILES ${SOURCE_FILES})
source_group("ARM debugger" FILES ${DEBUGGER_FILES})

export_directory(ARM SOURCE_FILES)
export_directory(ARM_DEBUGGER DEBUGGER_FILES)