/****************************************************************************
 *
 * This file is part of the ViSP software.
 * Copyright (C) 2005 - 2017 by Inria. All rights reserved.
 *
 * This software is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ViSP with software that can not be combined with the GNU
 * GPL, please contact Inria about acquiring a ViSP Professional
 * Edition License.
 *
 * See http://visp.inria.fr for more information.
 *
 * This software was developed at:
 * Inria Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 *
 * If you have questions regarding the use of this file, please contact
 * Inria at visp@inria.fr
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Description:
 * Example of template tracking.
 *
 * Authors:
 * Amaury Dame
 * Aurelien Yol
 * Fabien Spindler
 *
 *****************************************************************************/
#ifndef vpTemplateTrackerMIForwardAdditional_hh
#define vpTemplateTrackerMIForwardAdditional_hh

#include <visp3/core/vpConfig.h>

#include <visp3/core/vpImageFilter.h>
#include <visp3/tt/vpTemplateTracker.h>
#include <visp3/tt/vpTemplateTrackerHeader.h>

#include <visp3/tt_mi/vpTemplateTrackerMI.h>
#include <visp3/tt_mi/vpTemplateTrackerMIBSpline.h>

/*!
  \class vpTemplateTrackerMIForwardAdditional
  \ingroup group_tt_mi_tracker
  The algorithm implemented in this class is described in \cite Dame12a and
  \cite Marchand16a.
*/
class VISP_EXPORT vpTemplateTrackerMIForwardAdditional : public vpTemplateTrackerMI
{
public:
  /*! Minimization method. */
  typedef enum { USE_NEWTON, USE_LMA, USE_GRADIENT, USE_QUASINEWTON } vpMinimizationTypeMIForwardAdditional;

private:
  vpMinimizationTypeMIForwardAdditional minimizationMethod;
  // pour eval evolRMS
  double evolRMS;
  double *x_pos;
  double *y_pos;
  double threshold_RMS;
  // valeur pour calculer Quasi_Newton
  vpColVector p_prec;
  vpColVector G_prec;
  vpMatrix KQuasiNewton;

protected:
  void initHessienDesired(const vpImage<unsigned char> &I);
  void trackNoPyr(const vpImage<unsigned char> &I);
  void deletePosEvalRMS();
  void computeEvalRMS(const vpColVector &p);
  void initPosEvalRMS(const vpColVector &p);

  // private:
  //#ifndef DOXYGEN_SHOULD_SKIP_THIS
  //  vpTemplateTrackerMIForwardAdditional(const
  //  vpTemplateTrackerMIForwardAdditional &)
  //    : vpTemplateTrackerMI(), minimizationMethod(USE_NEWTON), evolRMS(0),
  //    x_pos(NULL), y_pos(NULL),
  //      threshold_RMS(0), p_prec(), G_prec(), KQuasiNewton()
  //  {
  //    throw vpException(vpException::functionNotImplementedError, "Not
  //    implemented!");
  //  }
  //  vpTemplateTrackerMIForwardAdditional &operator=(const
  //  vpTemplateTrackerMIForwardAdditional &){
  //    throw vpException(vpException::functionNotImplementedError, "Not
  //    implemented!"); return *this;
  //  }
  //#endif

public:
  //! Default constructor.
  vpTemplateTrackerMIForwardAdditional()
    : vpTemplateTrackerMI(), minimizationMethod(USE_NEWTON), evolRMS(0), x_pos(NULL), y_pos(NULL), threshold_RMS(0),
      p_prec(), G_prec(), KQuasiNewton()
  {
  }
  explicit vpTemplateTrackerMIForwardAdditional(vpTemplateTrackerWarp *_warp);
  void setThresholdRMS(double threshold) { threshold_RMS = threshold; }
  void setMinimizationMethod(vpMinimizationTypeMIForwardAdditional method) { minimizationMethod = method; }
};

#endif