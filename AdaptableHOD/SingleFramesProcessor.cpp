#include "SingleFramesProcessor.h"
#include <math.h>
#include <string.h>

SingleFramesProcessor::SingleFramesProcessor(void)
{
	init();
}

SingleFramesProcessor::SingleFramesProcessor(string backgroundImgPath)
{
	mBackgroundMat = cv::imread(backgroundImgPath);
	init();
}


void SingleFramesProcessor::init()
{
	mDenoiseProcessor = DenoiseProcessor::getInstance();
	//初始化去噪策咯
	//	mDenoiseProcessor->setDenoiseStrategy(DefaultDenosieStrategy::getInstance());
	mDenoiseProcessor->setDenoiseStrategy(LateralInhibition::getInstance());

	mSegmentProcessor = SegmentProcessor::getInstance();
	//初始化分割策咯
	//	mSegmentProcessor->setSegmentStrategy(DefaultSegmentStrategy::getInstance());
	mSegmentProcessor->setSegmentStrategy(KswSegment::getInstance());

	mFushion = new ImageFushion;
}


SingleFramesProcessor::~SingleFramesProcessor(void)
{
}

void SingleFramesProcessor::RealtimeAlgorithm(Byte* inputImg ,  Byte* visibleImg, 
	int iCol ,  int iRow, int vCol,  int vRow,  bool &result, 
	Byte*& outputImg,  Byte*& fusionImg )
{
	//注意传进来的是彩色图
	Mat visibleMat(vRow, vCol, CV_8UC3, visibleImg);
	Mat input(iRow, iCol, CV_8UC3, inputImg);
	if (mBackgroundMat.data)
	{	
		//消除固定背景噪声
		cv::addWeighted(input, 1, mBackgroundMat, -1, 0, input);	
	}
	mInputMat = input;	
	mDenoiseProcessor->process(mInputMat, mDenoiseMat);
	mSegmentProcessor->process(mDenoiseMat, mSegmentMat, mMorphMat, mCoordinates, mRotatedRects);
	outputImg = mMorphMat.data;
	
	result = (mCoordinates.size() > 0);
	if (result)
	{
		//若无目标则不进行融合
		//fusionImg = (mFushion->fusionBinary(mMorphMat, visibleMat)).data;
		fusionImg = (mFushion->fusionGray(mInputMat, visibleMat)).data;
	}

}

void SingleFramesProcessor::RealtimeAlgorithm(Byte* inputImg , int iCol , int iRow,  bool &result, Byte*& outputImg)
{
	//注意传进来的是彩色图
	Mat input(iRow, iCol, CV_8UC3, inputImg);
	if (mBackgroundMat.data)
	{	
		//消除固定背景噪声
		cv::addWeighted(input, 1, mBackgroundMat, -1, 0, input);	
	}
	mInputMat = input;	
	mDenoiseProcessor->process(mInputMat, mDenoiseMat);
	mSegmentProcessor->process(mDenoiseMat, mSegmentMat, mMorphMat, mCoordinates, mRotatedRects);
	outputImg = mMorphMat.data;

	result = (mCoordinates.size() > 0);
}


//void HOD::PeriodAlgorithm(	float * inputImg ,	float * visibleImg,	int iCol ,int iRow,int vCol,int vRow,
//											bool needReturn,Byte*& outputImg,Byte*& fusionImg)
//{
//
//}
//
//void HOD::PeriodAlgorithm(	Byte* inputImg ,	Byte* visibleImg,	int iCol ,int iRow,int vCol,int vRow,
//											bool needReturn,Byte*& outputImg,Byte*& fusionImg)
//{
//
//}
//
//void HOD::PeriodAlgorithm(Byte * inputImg ,int iCol ,int iRow,bool needReturn,Byte*& outputImg	)
//{
//
//}