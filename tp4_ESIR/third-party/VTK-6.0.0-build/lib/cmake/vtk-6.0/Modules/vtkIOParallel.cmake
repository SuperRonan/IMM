set(vtkIOParallel_LOADED 1)
set(vtkIOParallel_DEPENDS "vtkFiltersParallel;vtkIONetCDF;vtkIOXML;vtkParallelCore;vtkexodusII")
set(vtkIOParallel_LIBRARIES "vtkIOParallel")
set(vtkIOParallel_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-6.0")
set(vtkIOParallel_LIBRARY_DIRS "")
set(vtkIOParallel_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIOParallelHierarchy.txt")

