#pragma once
typedef unsigned char Byte;
#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
using cv::Mat;
using std::cout; using std::endl;

//辅助类，用以存储传入帧的索引和处理后的像素点数目
class IndexPixel
{
public:
	IndexPixel(){}
	IndexPixel(int index, int pixel)
	{
		mIndex = index;
		mPixel = pixel;
	}

	static bool comparepixel( IndexPixel& a, IndexPixel& b)
	{
		return a.getPixel() > b.getPixel();
	}

	static bool compareindex(IndexPixel& a, IndexPixel& b)
	{
		return a.getIndex() < b.getIndex();
	}

	void setIndex(int index) { mIndex = index; }
	void setPixel(int pixel) { mPixel = pixel; }
	int getIndex() { return mIndex; }
	int getPixel() { return mPixel; }

private:
	int mIndex;
	int mPixel;
};

class MultFramesProcessors
{
public:
	MultFramesProcessors(void);
	~MultFramesProcessors(void);
	void adaSegment(const Mat& Src, Mat& Dst);
	int bSums(Mat& src);
	bool isSuspicious(const Mat& img);

	void setThreshold(int t) { mThreshold = t; }
	int getThreshold() { return mThreshold; }

	//周期处理模式下的单帧处理接口
	//在周期处理模块启动命令之后，开始向算法处理模块传送每帧数据
	void PeriodAlgorithm(
		float * inputImg ,		//原始图像
		float * visibleImg,		//可见光图像
		int iCol ,					//原始图像列数
		int iRow,					//原始图像行数
		int vCol,					//可见光图像列数
		int vRow,					//可见光图像行数
		bool needReturn,		//由上层设定是否需要返回每帧的处理结构，如果needReturn为true则需要返回下面的参数
		Byte* outputImg,		//结果图像
		Byte* fusionImg		//可见光与结果图像的融合图像
		);

	//重载的周期处理函数，输入图像为unsigned char*
	void PeriodAlgorithm(
		Byte * inputImg ,		
		Byte * visibleImg,		
		int iCol ,
		int iRow,
		int vCol,
		int vRow,
		bool needReturn,
		Byte*& outputImg,
		Byte*& fusionImg
		);

	//重载的周期处理函数，没有包括可见光和融合部分
	void PeriodAlgorithm(
		Byte * inputImg ,		
		int iCol ,
		int iRow,
		bool needReturn,
		Byte*& outputImg
		);

private:
	int mThreshold;
	Mat mAdaSegedMat;
};

