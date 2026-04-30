#ifndef VERSION_H
#define VERSION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <mgba-util/dllexports.h>

extern MGBA_EXPORT const char* const gitCommit;
extern MGBA_EXPORT const char* const gitCommitShort;
extern MGBA_EXPORT const char* const gitBranch;
extern MGBA_EXPORT const int gitRevision;
extern MGBA_EXPORT const char* const binaryName;
extern MGBA_EXPORT const char* const projectName;
extern MGBA_EXPORT const char* const projectVersion;

#ifdef __cplusplus
}
#endif

#endif
