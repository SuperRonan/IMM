/*!
  \file usImageGradient.cpp
  \brief Process images
*/

#include "usImageGradient.h"

#define TO_COMPLETE

/*!
  \brief Compute the gradient images along x, y and z directions from a thin volume composed of 3 2D slices
  \param imga, img0, imgb: parallel images captured
  \param ip0,ipf: upper left and lower right corners of the ROI (in pixels) inside the gradient is computed
  \param dIdx,dIdy,dIdz: gradient images along x,y and z directions to compute
*/
void usImageGradient::Grad3DF3x3x3 (
	vpImage<unsigned char> &imga, 
	vpImage<unsigned char> &img0, 
	vpImage<unsigned char> &imgb, 
	vpImage<double> &dIdx, 
	vpImage<double> &dIdy, 
	vpImage<double> &dIdz, 
	vpImagePoint ip0, 
	vpImagePoint ipf 
	)
{

    int Wmin = (int)ip0.get_u(); // pixel u coordinate of the ROI left-top corner
    int Wmax = (int)ipf.get_u(); // pixel u coordinate of the ROI right-bottom corner
    int Hmin = (int)ip0.get_v(); // pixel v coordinate of the ROI left-top corner
    int Hmax = (int)ipf.get_v(); // pixel v coordinate of the ROI right-bottom corner
    
    vpImage<double> * grad[] = {&dIdx, &dIdy, &dIdz};
    const vpImage<unsigned char> * img[] = {&imgb, &img0, &imga};

#ifdef TO_COMPLETE
    // Question 3
    // Compute the gradient images along x, y and z directions from a thin volume composed of three 2D slices
    // corresponding to images imga, img0, imgb
    // Note that dIdx, dIdy and dIdz have the same size that the whole 2D ultrasound image but the gradient could
    // be computed only for the pixels contained in the ROI
	vpMatrix kernel = vpMatrix(3, 3);
	kernel[0][0] = -1;	kernel[0][1] = 0;	kernel[0][2] = 1;
	kernel[1][0] = -2;	kernel[1][1] = 0;	kernel[1][2] = 2;
	kernel[2][0] = -1;	kernel[2][1] = 0;	kernel[2][2] = 1;
	
	vpMatrix kernelz = vpMatrix(3, 3);
	kernelz[0][0] = 1;	kernelz[0][1] = 2;	kernelz[0][2] = 1;
	kernelz[1][0] = 2;	kernelz[1][1] = 4;	kernelz[1][2] = 2; 
	kernelz[2][0] = 1;	kernelz[2][1] = 2;	kernelz[2][2] = 1;
	int w = (Wmax-Wmin+1), h = (Hmax-Hmin+1);
	for(int i=Hmin; i<=Hmax; ++i)
	{
		for(int j=Wmin; j<=Wmax;++j)
		{
			for(int id=0; id<3; ++id)	(*grad[id])[i][j]=0;

			for(int ki=-1; ki<=1; ++ki)
			{
				for(int kj=-1; kj<=1; ++kj)
				{
					dIdx[i][j] += (*img[0])[i+ki][j+kj] * kernel[ki+1][kj+1] + 2 * (*img[1])[i+ki][j+kj] * kernel[ki+1][kj+1] + (*img[2])[i+ki][j+kj] * kernel[ki+1][kj+1];
					dIdy[i][j] += (*img[0])[i+ki][j+kj] * kernel[kj+1][ki+1] + 2 * (*img[1])[i+ki][j+kj] * kernel[kj+1][ki+1] + (*img[2])[i+ki][j+kj] * kernel[kj+1][ki+1];
					dIdz[i][j] += (*img[0])[i+ki][j+kj] * kernelz[ki+1][kj+1] - (*img[2])[i+ki][j+kj] * kernelz[ki+1][kj+1];
				}
			}
		}
	}

#endif

}


