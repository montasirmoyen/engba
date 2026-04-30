#ifndef MGBA_EXPORT_H
#define MGBA_EXPORT_H

#if defined(BUILD_STATIC) || !defined(_MSC_VER) || defined(MGBA_STANDALONE)
#define MGBA_EXPORT
#else
#ifdef MGBA_DLL
#define MGBA_EXPORT __declspec(dllexport)
#else
#define MGBA_EXPORT __declspec(dllimport)
#endif
#endif

#endif
