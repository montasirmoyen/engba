#ifndef MGBA_H
#define MGBA_H

#ifdef __cplusplus
extern "C" {
#endif

#define MGBA_LOG_FATAL 0
#define MGBA_LOG_ERROR 1
#define MGBA_LOG_WARN 2
#define MGBA_LOG_INFO 3
#define MGBA_LOG_DEBUG 4

bool mgba_open(void);
void mgba_close(void);

void mgba_printf(int level, const char* string, ...);
bool mgba_console_open(void);

#ifdef __cplusplus
}
#endif

#endif
