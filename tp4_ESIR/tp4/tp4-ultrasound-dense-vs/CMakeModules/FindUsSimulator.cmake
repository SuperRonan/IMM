#############################################################################
#
# $Id: FindUsSimulator.cmake,v 1.3 2008-12-19 14:24:13 fspindle Exp $
#
# Copyright (C) 2008 Inria. All rights reserved.
#
# This software was developed at:
# IRISA/INRIA Rennes
# Projet Lagadic
# Campus Universitaire de Beaulieu
# 35042 Rennes Cedex
# http://www.irisa.fr/lagadic
#
# This file is part of the ViSP toolkit
#
# This file may be distributed under the terms of the Q Public License
# as defined by Trolltech AS of Norway and appearing in the file
# LICENSE included in the packaging of this file.
#
# Licensees holding valid ViSP Professional Edition licenses may
# use this file in accordance with the ViSP Commercial License
# Agreement provided with the Software.
#
# This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
# WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#
# Contact visp@irisa.fr if any conditions of this licensing are
# not clear to you.
#
# Description:
# Try to find UsSimulator library.
#
# UsSimulator_FOUND
# UsSimulator_INCLUDE_DIR
# UsSimulator_LIBRARIES
#
#############################################################################

  
  FIND_PATH(UsSimulator_INCLUDE_DIR UsSimulator/usSimulatorConfig.h
    $ENV{USSIMULATOR_HOME}/include
    )
  #MESSAGE("DBG UsSimulator_INCLUDE_DIR=${UsSimulator_INCLUDE_DIR}")  
  
  FIND_LIBRARY(UsSimulator_LIBRARY
    NAMES UsSimulator
    PATHS 
    $ENV{USSIMULATOR_HOME}/lib
    )

  #MESSAGE("DBG UsSimulator_LIBRARY=${UsSimulator_LIBRARY}")
  
  ## --------------------------------
  
  IF(UsSimulator_LIBRARY)
    SET(UsSimulator_LIBRARIES ${UsSimulator_LIBRARY})
  ELSE(UsSimulator_LIBRARY)
#    MESSAGE(SEND_ERROR "UsSimulator library not found.")
  ENDIF(UsSimulator_LIBRARY)
  
  IF(NOT UsSimulator_INCLUDE_DIR)
#    MESSAGE(SEND_ERROR "UsSimulator include dir not found.")
  ENDIF(NOT UsSimulator_INCLUDE_DIR)
  
  IF(UsSimulator_LIBRARIES AND UsSimulator_INCLUDE_DIR)
    SET(UsSimulator_FOUND TRUE)
  ELSE(UsSimulator_LIBRARIES AND UsSimulator_INCLUDE_DIR)
    SET(UsSimulator_FOUND FALSE)
  ENDIF(UsSimulator_LIBRARIES AND UsSimulator_INCLUDE_DIR)
  
  MARK_AS_ADVANCED(
    UsSimulator_INCLUDE_DIR
    UsSimulator_LIBRARIES
    UsSimulator_LIBRARY
    )
