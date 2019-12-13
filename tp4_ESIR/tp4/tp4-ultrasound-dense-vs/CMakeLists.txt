project(UltrasoundDense)

# ccmake version that works
cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 11)

#-----------------------------------------------------------------------------

# the third party include directories we depend on
set(UltrasoundDense_EXTERN_INCLUDE_DIR "")
# the third party libraries we depend on
set(UltrasoundDense_EXTERN_LIBS "")
# the third party libraries we depend on
set(UltrasoundDense_DEFS "")

# Get the OS
set(OS ${CMAKE_SYSTEM_NAME})

## where are user-specific cmake modules
set(CMAKE_MODULE_PATH ${UltrasoundDense_SOURCE_DIR}/CMakeModules)

include(CheckLibraryExists)


#--------------------------------------------------------------------
# By default set release configuration
#--------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE String "Choose the type of build, options are: None Debug Release" FORCE)
endif()


#----------------------------------------------------------------------
# Third party libraries
#----------------------------------------------------------------------
# ViSP
find_package(VISP REQUIRED)
if(VISP_FOUND)
  include(${VISP_USE_FILE})
endif(VISP_FOUND)

# VTK libraries
find_package(VTK REQUIRED)
if(VTK_FOUND)
  include(${VTK_USE_FILE})
  set(UltrasoundDense_EXTERN_LIBS  ${VTK_LIBRARIES} ${UltrasoundDense_EXTERN_LIBS})
endif(VTK_FOUND)

# UsSimulator
find_package(UsSimulator REQUIRED)
if(UsSimulator_FOUND)
  set(UltrasoundDense_EXTERN_INCLUDE_DIR ${UsSimulator_INCLUDE_DIR} ${UltrasoundDense_EXTERN_INCLUDE_DIR})
  set(UltrasoundDense_EXTERN_LIBS ${UsSimulator_LIBRARIES} ${UltrasoundDense_EXTERN_LIBS})
endif(UsSimulator_FOUND)

#----------------------------------------------------------------------
# Concatenate intern and third party include dirs
#----------------------------------------------------------------------
include_directories(${UltrasoundDense_EXTERN_INCLUDE_DIR})

#----------------------------------------------------------------------
# Add definitions
#----------------------------------------------------------------------
add_definitions(${UltrasoundDense_DEFS})

#----------------------------------------------------------------------
# Propagation in sub dirs
#----------------------------------------------------------------------
subdirs(tp)
