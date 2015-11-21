#pragma once
#define PI 3.1415926535

typedef unsigned char Byte;

#include "DenoiseProcessor.h"
#include "SegmentProcessor.h"
#include "./Processors/DenoiseStrategy.h"
#include "./Processors/SegmentStrategy.h"

#include <vector>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using std::vector; using std::string;
using cv::Mat;  using cv::RotatedRect;

class HOD
{
public:
	HOD(void);
	HOD(string backgroundImgPath);
	~HOD(void);

	void init();

	//实时处理模式下的单帧处理算法接口
	//实时处理每帧图像，同时将结果图像与可见光融合
	void RealtimeAlgorithm(
		float * inputImg ,		//原始图像
		float * visibleImg,		//可见光图像
		int iCol ,					//原始图像列数
		int iRow,					//原始图像行数
		int vCol,					//可见光图像列数
		int vRow,					//可见光图像行数
		bool &result,				//是否发现目标
		Byte*& outputImg,		//结果图像
		Byte*& fusionImg		//可见光与结果图像的融合图像
		);

	//重载的实时处理函数，输入图像为unsigned char*
	void RealtimeAlgorithm(
		Byte* inputImg ,		
		Byte* visibleImg,		
		int iCol ,					
		int iRow,					
		int vCol,					
		int vRow,					
		bool &result,				
		Byte*& outputImg,		
		Byte*& fusionImg		
		);

	//重载的实时处理函数，没有包括可见光和融合部分
	void RealtimeAlgorithm(
		Byte* inputImg ,		//原始图像
		int iCol ,					//原始图像列数
		int iRow,					//原始图像行数
		bool &result,				//是否发现目标
		Byte*& outputImg		//结果图像
		);

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
	Mat mBackgroundMat;
	//各个阶段的图像
	Mat mInputMat;
	Mat mDenoiseMat;
	Mat mSegmentMat;
	Mat mMorphMat;
	Mat mOutputMat;

	//去噪处理器
	DenoiseProcessor* mDenoiseProcessor;
	//分割处理器
	SegmentProcessor* mSegmentProcessor;

	//保存输出目标的质心坐标
	vector<Coordinate> mCoordinates;
	//保存输出目标的外围旋转矩形
	vector<RotatedRect> mRotatedRects;


	void setDenoiseStrategy(int index);
	void setSegmentStrategy(int index);
};

