#ifndef usSimulatorConfig_h
#define usSimulatorConfig_h


// UsSimulator major version.
#define USSIMULATOR_VERSION_MAJOR 1

// UsSimulator minor version.
#define USSIMULATOR_VERSION_MINOR 0

// UsSimulator patch version.
#define USSIMULATOR_VERSION_PATCH 0

// UsSimulator version.
#define USSIMULATOR_VERSION_FULL 1.0.0

// Defined if MSVC is the compiler
/* #undef USSIMULATOR_USE_MSVC */

// UsSimulator library is either compiled static or shared
// Used to set declspec(import, export) in headers if required under Windows
/* #undef USSIMULATOR_BUILD_SHARED_LIBS */

// Defined if ViSP library available.
#define USSIMULATOR_HAVE_VISP

// Defined if VTK library available.
#define USSIMULATOR_HAVE_VTK

// Defined if wxWidgets library available.
/* #undef USSIMULATOR_HAVE_WXWIDGETS */

// Under Windows, for shared libraries (DLL) we need to define export on
// compilation or import on use (like a third party project).
// We exploit here the fact that cmake auto set xxx_EXPORTS (with S) on
// compilation.
#if defined (WIN32) && defined(USSIMULATOR_BUILD_SHARED_LIBS)
#  ifdef ussimulator_2_EXPORTS
#    define USSIMULATOR_EXPORT __declspec(dllexport)
#  else
#    define USSIMULATOR_EXPORT __declspec(dllimport)
#  endif
#else
#  define USSIMULATOR_EXPORT
#endif

#endif
