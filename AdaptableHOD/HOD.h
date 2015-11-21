#pragma once
#define PI 3.1415926535

typedef unsigned char Byte;

#include "DenoiseProcessor.h"
#include "SegmentProcessor.h"
#include "./Processors/DenoiseStrategy.h"
#include "./Processors/SegmentStrategy.h"

#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using std::vector;
using cv::Mat;  using cv::RotatedRect;

class HOD
{
public:
	HOD(void);
	~HOD(void);

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
		Byte*& outputImg,		//���ͼ��
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

	//���ڴ���ģʽ�µĵ�֡�����ӿ�
	//�����ڴ���ģ����������֮�󣬿�ʼ���㷨����ģ�鴫��ÿ֡����
	void PeriodAlgorithm(
		float * inputImg ,		//ԭʼͼ��
		float * visibleImg,		//�ɼ���ͼ��
		int iCol ,					//ԭʼͼ������
		int iRow,					//ԭʼͼ������
		int vCol,					//�ɼ���ͼ������
		int vRow,					//�ɼ���ͼ������
		bool needReturn,		//���ϲ��趨�Ƿ���Ҫ����ÿ֡�Ĵ����ṹ�����needReturnΪtrue����Ҫ��������Ĳ���
		Byte* outputImg,		//���ͼ��
		Byte* fusionImg		//�ɼ�������ͼ����ں�ͼ��
		)

		//���ص����ڴ�������������ͼ��Ϊunsigned char*
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
		)

		//���ص����ڴ���������û�а����ɼ�����ںϲ���
		void PeriodAlgorithm(
		Byte * inputImg ,		
		int iCol ,
		int iRow,
		bool needReturn,
		Byte*& outputImg
		)


private:
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

	//�������Ŀ�����������
	vector<Coordinate> mCoordinates;
	//�������Ŀ�����Χ��ת����
	vector<RotatedRect> mRotatedRects;


	void setDenoiseStrategy(int index);
	void setSegmentStrategy(int index);
};
