# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget visp_core visp_gui visp_imgproc visp_io visp_klt visp_me visp_sensor visp_ar visp_blob visp_robot visp_visual_features visp_vs visp_vision visp_detection visp_mbt visp_tt visp_tt_mi)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target visp_core
add_library(visp_core SHARED IMPORTED)

set_target_properties(visp_core PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/usr/include/eigen3;/usr/include/libxml2;/usr/include"
  INTERFACE_LINK_LIBRARIES "/usr/lib64/liblapack.so;/usr/lib64/libblas.so;/usr/lib64/libxml2.so;/usr/lib64/libpthread.so;/usr/lib64/libz.so;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_gui
add_library(visp_gui SHARED IMPORTED)

set_target_properties(visp_gui PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
  INTERFACE_LINK_LIBRARIES "visp_core;/usr/lib64/libSM.so;/usr/lib64/libICE.so;/usr/lib64/libX11.so;/usr/lib64/libXext.so;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_imgproc
add_library(visp_imgproc SHARED IMPORTED)

set_target_properties(visp_imgproc PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_io
add_library(visp_io SHARED IMPORTED)

set_target_properties(visp_io PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
  INTERFACE_LINK_LIBRARIES "visp_core;/usr/lib64/libjpeg.so;/usr/lib64/libpng.so;/usr/lib64/libz.so;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_klt
add_library(visp_klt SHARED IMPORTED)

set_target_properties(visp_klt PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_me
add_library(visp_me SHARED IMPORTED)

set_target_properties(visp_me PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_sensor
add_library(visp_sensor SHARED IMPORTED)

set_target_properties(visp_sensor PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
  INTERFACE_LINK_LIBRARIES "visp_core;/usr/lib64/libv4l2.so;/usr/lib64/libv4lconvert.so;/usr/lib64/libdc1394.so;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_ar
add_library(visp_ar SHARED IMPORTED)

set_target_properties(visp_ar PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;visp_io;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_blob
add_library(visp_blob SHARED IMPORTED)

set_target_properties(visp_blob PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_robot
add_library(visp_robot SHARED IMPORTED)

set_target_properties(visp_robot PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;visp_gui;visp_io;visp_sensor;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_visual_features
add_library(visp_visual_features SHARED IMPORTED)

set_target_properties(visp_visual_features PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;visp_me;visp_blob;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_vs
add_library(visp_vs SHARED IMPORTED)

set_target_properties(visp_vs PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;visp_gui;visp_io;visp_me;visp_sensor;visp_blob;visp_robot;visp_visual_features;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_vision
add_library(visp_vision SHARED IMPORTED)

set_target_properties(visp_vision PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;visp_io;visp_me;visp_blob;visp_visual_features;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_detection
add_library(visp_detection SHARED IMPORTED)

set_target_properties(visp_detection PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;visp_io;visp_me;visp_blob;visp_visual_features;visp_vision;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_mbt
add_library(visp_mbt SHARED IMPORTED)

set_target_properties(visp_mbt PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;visp_gui;visp_io;visp_klt;visp_me;visp_ar;visp_blob;visp_visual_features;visp_vision;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_tt
add_library(visp_tt SHARED IMPORTED)

set_target_properties(visp_tt PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;visp_io;visp_me;visp_blob;visp_visual_features;visp_vision;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

# Create imported target visp_tt_mi
add_library(visp_tt_mi SHARED IMPORTED)

set_target_properties(visp_tt_mi PROPERTIES
  INTERFACE_LINK_LIBRARIES "visp_core;visp_io;visp_me;visp_blob;visp_visual_features;visp_vision;visp_tt;/usr/lib64/libm.so;/usr/lib64/libnsl.so"
)

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  message(FATAL_ERROR "This file relies on consumers using CMake 2.8.12 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/VISPModules-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
