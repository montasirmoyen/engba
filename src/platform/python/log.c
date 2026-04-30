#include "log.h"

static void _pyLogShim(struct mLogger* logger, int category, enum mLogLevel level, const char* format, va_list args) {
	struct mLoggerPy* pylogger = (struct mLoggerPy*) logger;
	char message[256] = {0};
	vsnprintf(message, sizeof(message) - 1, format, args);
	_pyLog(pylogger, category, level, message);
}

struct mLogger* mLoggerPythonCreate(void* pyobj) {
	struct mLoggerPy* logger = malloc(sizeof(*logger));
	logger->d.log = _pyLogShim;
	logger->d.filter = NULL;
	logger->pyobj = pyobj;
	return &logger->d;
}
