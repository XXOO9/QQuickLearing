#ifndef CTESTSHARDLIBRARY_GLOBAL_H
#define CTESTSHARDLIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CTESTSHARDLIBRARY_LIBRARY)
#  define CTESTSHARDLIBRARYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CTESTSHARDLIBRARYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CTESTSHARDLIBRARY_GLOBAL_H
