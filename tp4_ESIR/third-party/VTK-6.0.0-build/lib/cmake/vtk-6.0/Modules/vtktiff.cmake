set(vtktiff_LOADED 1)
set(vtktiff_DEPENDS "vtkjpeg;vtkzlib")
set(vtktiff_LIBRARIES "vtktiff")
set(vtktiff_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-6.0")
set(vtktiff_LIBRARY_DIRS "")
set(vtktiff_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtktiffHierarchy.txt")
set(vtktiff_EXCLUDE_FROM_WRAPPING 1)

