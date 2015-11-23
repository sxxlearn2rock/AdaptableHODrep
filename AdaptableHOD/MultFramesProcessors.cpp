#include "MultFramesProcessors.h"


MultFramesProcessors::MultFramesProcessors(void) : mThreshold(36)
{
}


MultFramesProcessors::~MultFramesProcessors(void)
{
}

void MultFramesProcessors::adaSegment(const Mat& Src, Mat& Dst)
{
	double maxValue=255;
	//int adaptiveMethod=ADAPTIVE_THRESH_MEAN_C;   //均值
	int adaptiveMethod=cv::ADAPTIVE_THRESH_GAUSSIAN_C;//高斯
	//int thresholdType=THRESH_BINARY;
	int thresholdType=cv::THRESH_BINARY_INV;
	int blockSize=5;
	double C=10;
	adaptiveThreshold(Src,Dst,maxValue,adaptiveMethod,thresholdType,blockSize,C);
}

int MultFramesProcessors::bSums(Mat& src)
{
	int counter = 0;
	//迭代器访问像素点
	cv::Mat_<uchar>::iterator it = src.begin<uchar>();
	cv::Mat_<uchar>::iterator itend = src.end<uchar>();  
	for (; it!=itend; ++it)
	{
		if((*it)>0) counter+=1;//二值化后，像素点是0或者255
	}			
	return counter;
}

bool MultFramesProcessors::isSuspicious(const Mat& img)
{
	adaSegment(img, mAdaSegedMat);
	return bSums(mAdaSegedMat) > mThreshold;
}

void MultFramesProcessors::PeriodAlgorithm(Byte * inputImg , int iCol , int iRow, bool needReturn, Byte*& outputImg)
{

}

void MultFramesProcessors::PeriodAlgorithm(Byte * inputImg , Byte * visibleImg, int iCol , int iRow, int vCol, int vRow,
																	  bool needReturn, Byte*& outputImg, Byte*& fusionImg)
{
	Mat input(iRow, iCol, CV_8UC3, inputImg);
	if ( needReturn && isSuspicious(input))
	{

	}
}
