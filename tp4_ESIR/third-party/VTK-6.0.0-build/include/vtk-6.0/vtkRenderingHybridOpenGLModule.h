
#ifndef VTKRENDERINGHYBRIDOPENGL_EXPORT_H
#define VTKRENDERINGHYBRIDOPENGL_EXPORT_H

#ifdef VTKRENDERINGHYBRIDOPENGL_STATIC_DEFINE
#  define VTKRENDERINGHYBRIDOPENGL_EXPORT
#  define VTKRENDERINGHYBRIDOPENGL_NO_EXPORT
#else
#  ifndef VTKRENDERINGHYBRIDOPENGL_EXPORT
#    ifdef vtkRenderingHybridOpenGL_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGHYBRIDOPENGL_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKRENDERINGHYBRIDOPENGL_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKRENDERINGHYBRIDOPENGL_NO_EXPORT
#    define VTKRENDERINGHYBRIDOPENGL_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKRENDERINGHYBRIDOPENGL_DEPRECATED
#  define VTKRENDERINGHYBRIDOPENGL_DEPRECATED __attribute__ ((__deprecated__))
#  define VTKRENDERINGHYBRIDOPENGL_DEPRECATED_EXPORT VTKRENDERINGHYBRIDOPENGL_EXPORT __attribute__ ((__deprecated__))
#  define VTKRENDERINGHYBRIDOPENGL_DEPRECATED_NO_EXPORT VTKRENDERINGHYBRIDOPENGL_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGHYBRIDOPENGL_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkImagingHybridModule.h"
#include "vtkRenderingOpenGLModule.h"

#endif
