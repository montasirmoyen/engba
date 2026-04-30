#include <sys/iosupport.h>
#include <gba_types.h>

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <mgba.h>

#define REG_DEBUG_ENABLE (vu16*) 0x4FFF780
#define REG_DEBUG_FLAGS (vu16*) 0x4FFF700
#define REG_DEBUG_STRING (char*) 0x4FFF600

ssize_t mgba_stdout_write(struct _reent* r __attribute__((unused)), void* fd __attribute__((unused)), const char* ptr, size_t len) {
	if (len > 0x100) {
		len = 0x100;
	}
	strncpy(REG_DEBUG_STRING, ptr, len);
	*REG_DEBUG_FLAGS = MGBA_LOG_INFO | 0x100;
	return len;
}

ssize_t mgba_stderr_write(struct _reent* r __attribute__((unused)), void* fd __attribute__((unused)), const char* ptr, size_t len) {
	if (len > 0x100) {
		len = 0x100;
	}
	strncpy(REG_DEBUG_STRING, ptr, len);
	*REG_DEBUG_FLAGS = MGBA_LOG_ERROR | 0x100;
	return len;
}

void mgba_printf(int level, const char* ptr, ...) {
	level &= 0x7;
	va_list args;
	va_start(args, ptr);
	vsnprintf(REG_DEBUG_STRING, 0x100, ptr, args);
	va_end(args);
	*REG_DEBUG_FLAGS = level | 0x100;
}

static const devoptab_t dotab_mgba_stdout = {
	"mgba_stdout",
	0,
	NULL,
	NULL,
	mgba_stdout_write
};

static const devoptab_t dotab_mgba_stderr = {
	"mgba_stderr",
	0,
	NULL,
	NULL,
	mgba_stderr_write
};

bool mgba_console_open(void) {
	if (!mgba_open()) {
		return false;
	}
	devoptab_list[STD_OUT] = &dotab_mgba_stdout;
	devoptab_list[STD_ERR] = &dotab_mgba_stderr;
	return true;
}

bool mgba_open(void) {
	*REG_DEBUG_ENABLE = 0xC0DE;
	return *REG_DEBUG_ENABLE == 0x1DEA;
}

void mgba_close(void) {
	*REG_DEBUG_ENABLE = 0;
}
