/*                                                                -*-c++-*-
#----------------------------------------------------------------------------
#  Copyright (C) 2006  IRISA-INRIA Rennes Lagadic Project
#  All Rights Reserved.
#
#
#    Contact:
#       Alexandre Krupa
#       IRISA-INRIA Rennes
#       Campus Universitaire de Beaulieu
#       35042 Rennes Cedex
#       France
#
#    email: krupa@irisa.fr
#    www  : http://www.irisa.fr/lagadic
#
#----------------------------------------------------------------------------
*/

/*!
  \file usSimulator.h
  \brief Declaration of the usSimulator class.


*/

#ifndef usSimulator_hh
#define usSimulator_hh

#include <UsSimulator/usSimulatorConfig.h>

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkCellPicker.h"
#include "vtkImagePlaneWidget.h"
#include "vtkImageReader.h"
#include "vtkOutlineFilter.h"
#include "vtkPolyDataMapper.h"
#include "vtkProperty.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkPNMReader.h"
#include "vtkImageViewer.h"
#include "vtkPlaneSource.h"
#include "vtkTexture.h"
#include "vtkImageReslice.h"
#include "vtkTransform.h"
#include "vtkRenderLargeImage.h"
#include "vtkBMPWriter.h"
#include "vtkImageData.h"

#include <visp/vpHomogeneousMatrix.h>
#include <visp/vpVelocityTwistMatrix.h>
#include <visp/vpColVector.h>
#include <visp/vpRotationMatrix.h>
#include <visp/vpThetaUVector.h>
#include <visp/vpImage.h>
#include <visp/vpPoseVector.h>
#include <visp/vpIoTools.h>

/*!
  \class usSimulator

  Class that simulate a virtual ultrasound probe interaction with a 3D
  ultrasound volume.

*/

class USSIMULATOR_EXPORT usSimulator
{
public:

  // 3DUS data
  int sizeX;
  int sizeY;
  int sizeZ;

  double spacingX;
  double spacingY;
  double spacingZ;

  int minX;
  int minY;
  int minZ;
  int boxsizeX;
  int boxsizeY;
  int boxsizeZ;

  vpImage<unsigned char> Image; // current image (needed for ViSP connexion)


private:
  ////////////////////////////////////////////////////////////////////////////
  // Define homogeneous matrix of the virtual US probe
  //
  // Probe frame p is attached to the center of the 2D US image
  // Base frame b is attached to the origin of the fixed world frame (volume frame at time = 0)
  // Current image frame i is attached to the upper-left corner of the image
  // Object frame o is attached to the origin of the moving volume (can move during task)
  // Camera frame c is attached to the origin of the fixed camera
  // Centered object frame oc is attached to the center of the volume
  vpHomogeneousMatrix bMo, oMb; // transformation from fixed base frame to object frame
  vpHomogeneousMatrix bMp; // transformation from fixed base frame to probe frame
  vpHomogeneousMatrix iMp; // transformation from current image frame to probe frame (cst)
  vpHomogeneousMatrix bMoc; // transformation from base frame to centered object frame
  vpHomogeneousMatrix oMoc; // transformation from object base frame to centered object frame
  vpHomogeneousMatrix bMi; // transformation from base frame to image frame
  vpHomogeneousMatrix oMi; // transformation from object frame to current image frame
  vpHomogeneousMatrix bMc; // transformation from base frame to camera frame (cst)
  vpHomogeneousMatrix cMo, oMc; // transformation from camera frame to object frame cMo
  vpVelocityTwistMatrix oVoc; // Twix matrix for velocity transformation between frame o and frame oc
  double CameraViewUp[3];
  double pos_camera[3];
  double focal_point[3];
  vpColVector focal_point_o; // camera focal position expressed in frame o
  vpColVector focal_point_b; // camera focal position expressed in frame b


  unsigned char *ptr; // current image pointer (needed for ViSP connexion)


  // vtk classes
private:
  bool wxflag;
  vtkRenderWindowInteractor *vtkWindow;
  //wxVTKRenderWindowInteractor *wxWindow;
  vtkRenderWindow       *renWin;
  vtkRenderer           *ren1;
  vtkPNMReader		*v16;
  vtkOutlineFilter	*outline;
  vtkPolyDataMapper	*outlineMapper;
  vtkActor		*outlineActor;
  vtkCellPicker		*picker;
  vtkProperty		*ipwProp;
  vtkImagePlaneWidget	*planeWidgetX;
  vtkImagePlaneWidget	*planeWidgetY;
  vtkImagePlaneWidget	*planeWidgetZ;
  vtkImageReslice	*reslice;
  vtkMatrix4x4		*vtk_oMi; // define homogeneous matrix use for VTK
  vtkTransform		*transform; // define position transformation for current image
  vtkPlaneSource	*plane;
  vtkPolyDataMapper	*planeMapper;
  vtkActor		*planeActor;
  vtkTexture		*atext;
  vtkImageData		*image; // define the current image connected to ViSP
  vtkMatrix4x4		*vtk_cMo; // transformation from camera frame to object frame cMo

private:
  void init(const char *filename, unsigned int width,  unsigned int height);
  
  // for volumes sequence
  bool volumesSeq_flag;
  void initVolseq(const char *path_volseq, unsigned int width,  unsigned int height);
  
  unsigned char * load_vols; // loaded mutiple volumes
 
  int volumeSize; // volume size
  unsigned char * volData; // Current Volume memory
  int numVolumes; // total number of volumes in the sequence
  int m_iD[3]; // image dimensions
  vtkImageData *Image3D; // Current volume 
  int volume_index; // volumes sequence index

public:
  usSimulator(); //do not use this default constructor
 ~usSimulator();

  // constructor for linkink VTK with vtkWindowInteractor
  usSimulator(const char *filename, vtkRenderWindowInteractor *mVTKWindow, unsigned int width,  unsigned int height);

 // constructor for linkink VTK with vtkWindowInteractor and volumes sequence reading
  usSimulator(vtkRenderWindowInteractor * mVTKWindow, unsigned int width,  unsigned int height, const char *path_volseq);

  // constructor for linkink VTK with wxWindowInteractor
  //usSimulator(const char *filename, wxVTKRenderWindowInteractor *mVTKWindow, unsigned int width,  unsigned int height);



  // Simulator commands

  //! render the simulator view process
  void render();

  //! send control velocity to the probe and object frame (mm/s and rad/s)
  void sendControlVelocity(vpColVector probeVelocity, vpColVector objectVelocity, double controlPeriode);

  //! get the pose of the probe frame with respect to the fixed base frame (mm and rad)
  void getProbePosition(vpPoseVector & probePose);

  //! set the pose of the probe frame with respect to the fixed base frame (mm and rad)
  void setProbePosition(vpPoseVector & probePose);

  //! get the pose of the object frame with respect to the fixed base frame (mm and rad)
  void getObjectPosition(vpPoseVector & objectPose);

  //! set the pose of the object frame with respect to the fixed base frame (mm and rad)
  void setObjectPosition(vpPoseVector & objectPose);

  //! save the PPM image of the current 3D view
  void save3DImageview(const char *filename);

  //! set the centered object reference frame oc pose with respect to object frame o
  void setObjectFrame(vpPoseVector & objectFramePose);

  //! load next volume from the sequence
  void nextVolume();

  //! load previous volume from the sequence
  void previousVolume();

  //! get current volume index 
  int getCurrentVolumeIndex();
    
  //! get number of volumes
  int getVolumesNumber();

  vpHomogeneousMatrix getBMi();


};

#endif

