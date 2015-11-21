#include "HOD.h"
#include <math.h>
#include <string.h>

HOD::HOD(void)
{
	mDenoiseProcessor = DenoiseProcessor::getInstance();
	//初始化去噪策咯
//	mDenoiseProcessor->setDenoiseStrategy(DefaultDenosieStrategy::getInstance());
	mDenoiseProcessor->setDenoiseStrategy(LateralInhibition::getInstance());

	mSegmentProcessor = SegmentProcessor::getInstance();
	//初始化分割策咯
//	mSegmentProcessor->setSegmentStrategy(DefaultSegmentStrategy::getInstance());
	mSegmentProcessor->setSegmentStrategy(KswSegment::getInstance());
}


HOD::~HOD(void)
{
}

void HOD::RealtimeAlgorithm(Byte* inputImg ,  Byte* visibleImg, 
	int iCol ,  int iRow, int vCol,  int vRow,  bool &result, 
	Byte*& outputImg,  Byte*& fusionImg )
{
	
}

void HOD::RealtimeAlgorithm(Byte* inputImg , int iCol , int iRow,  bool &result, Byte*& outputImg)
{
	//注意传进来的是彩色图
	Mat input(iRow, iCol, CV_8UC3, inputImg);
	mInputMat = input;	
	mDenoiseProcessor->process(mInputMat, mDenoiseMat);
	mSegmentProcessor->process(mDenoiseMat, mSegmentMat, mMorphMat, mCoordinates, mRotatedRects);
	outputImg = mMorphMat.data;

	result = (mCoordinates.size() > 0);
}


void HOD::PeriodAlgorithm(	float * inputImg ,	float * visibleImg,	int iCol ,int iRow,int vCol,int vRow,
											bool needReturn,Byte*& outputImg,Byte*& fusionImg)
{

}

void HOD::PeriodAlgorithm(	Byte* inputImg ,	Byte* visibleImg,	int iCol ,int iRow,int vCol,int vRow,
											bool needReturn,Byte*& outputImg,Byte*& fusionImg)
{

}

void HOD::PeriodAlgorithm(Byte * inputImg ,int iCol ,int iRow,bool needReturn,Byte*& outputImg	)
{

}