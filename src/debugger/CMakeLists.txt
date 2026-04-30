include(ExportDirectory)
set(SOURCE_FILES
	access-logger.cpp
	cli-debugger.cpp
	debugger.cpp
	parser.cpp
	symbols.cpp
	stack-trace.cpp)

if(ENABLE_SCRIPTING)
	list(APPEND SOURCE_FILES cli-debugger-scripting.cpp)
endif()

if(USE_EDITLINE)
	list(APPEND SOURCE_FILES cli-el-backend.cpp)
endif()

if(ENABLE_GDB_STUB)
	list(APPEND SOURCE_FILES gdb-stub.cpp)
endif()

set(TEST_FILES
	test/lexer.cpp
	test/parser.cpp)

source_group("Debugger" FILES ${SOURCE_FILES})
source_group("Debugger tests" FILES ${TEST_FILES})

export_directory(DEBUGGER SOURCE_FILES)
export_directory(DEBUGGER_TEST TEST_FILES)
