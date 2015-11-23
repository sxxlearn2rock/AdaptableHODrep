#pragma once
#define PI 3.1415926535

typedef unsigned char Byte;

#include "DenoiseProcessor.h"
#include "SegmentProcessor.h"
#include "./Processors/DenoiseStrategy.h"
#include "./Processors/SegmentStrategy.h"
#include "ImageFushion.h"

#include <vector>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using std::vector; using std::string;
using cv::Mat;  using cv::RotatedRect;

class SingleFramesProcessor
{
public:
	SingleFramesProcessor(void);
	SingleFramesProcessor(string backgroundImgPath);
	~SingleFramesProcessor(void);

	void init();

	//ʵʱ����ģʽ�µĵ�֡�����㷨�ӿ�
	//ʵʱ����ÿ֡ͼ��ͬʱ�����ͼ����ɼ����ں�
	void RealtimeAlgorithm(
		float * inputImg ,		//ԭʼͼ��
		float * visibleImg,		//�ɼ���ͼ��
		int iCol ,					//ԭʼͼ������
		int iRow,					//ԭʼͼ������
		int vCol,					//�ɼ���ͼ������
		int vRow,					//�ɼ���ͼ������
		bool &result,				//�Ƿ���Ŀ��
		Byte*& outputImg,	//���ͼ��
		Byte*& fusionImg		//�ɼ�������ͼ����ں�ͼ��
		);

	//���ص�ʵʱ��������������ͼ��Ϊunsigned char*
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

	//���ص�ʵʱ����������û�а����ɼ�����ںϲ���
	void RealtimeAlgorithm(
		Byte* inputImg ,		//ԭʼͼ��
		int iCol ,					//ԭʼͼ������
		int iRow,					//ԭʼͼ������
		bool &result,				//�Ƿ���Ŀ��
		Byte*& outputImg		//���ͼ��
		);

private:
	Mat mBackgroundMat;
	//�����׶ε�ͼ��
	Mat mInputMat;
	Mat mDenoiseMat;
	Mat mSegmentMat;
	Mat mMorphMat;
	Mat mOutputMat;

	//ȥ�봦����
	DenoiseProcessor* mDenoiseProcessor;
	//�ָ����
	SegmentProcessor* mSegmentProcessor;
	//����ͼ���ں�
	ImageFushion* mFushion;

	//�������Ŀ�����������
	vector<Coordinate> mCoordinates;
	//�������Ŀ�����Χ��ת����
	vector<RotatedRect> mRotatedRects;

	void setDenoiseStrategy(int index);
	void setSegmentStrategy(int index);
};
