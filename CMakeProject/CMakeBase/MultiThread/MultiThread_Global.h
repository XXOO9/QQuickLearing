#ifndef MULTITHREAD_GLOBAL_H
#define MULTITHREAD_GLOBAL_H

#include <iostream>

#if defined LIBRARYEXPORT
#define SHARED_EXPORT __declspec( dllexport )
#else
#define SHARED_EXPORT __declspec( dllimport )
#endif

#endif // MULTITHREAD_GLOBAL_H
