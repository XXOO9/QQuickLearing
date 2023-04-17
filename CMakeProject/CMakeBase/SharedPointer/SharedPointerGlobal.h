#ifndef SHAREDPOINTERGLOBAL_H
#define SHAREDPOINTERGLOBAL_H

#if defined( LIBRARYEXPORT )
#define DLLEXPORT __declspec( dllexport )
#else
#define DLLEXPORT __declspec( dllimport )
#endif

#endif // SHAREDPOINTERGLOBAL_H
