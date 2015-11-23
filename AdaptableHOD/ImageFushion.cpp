#include "ImageFushion.h"


ImageFushion::ImageFushion(void)
{
}


ImageFushion::~ImageFushion(void)
{
}


cv::Mat ImageFushion::fusionGray( cv::Mat & image_mmw, cv::Mat & image_visible)
{
	int scale=4;
	if (image_mmw.channels() == 3)
	{
		cv::cvtColor(image_mmw, image_mmw,CV_BGR2GRAY);
	}
	//ע��Ϊ�����Ч�ʣ��˴�����������ǳ�������ƻ�������Ŀɼ���ͼ������
	cv::Mat image_fusion = image_visible;
	cv::Size size=cv::Size(image_mmw.cols*scale, image_mmw.rows*scale);
	cv::Mat image2 = cv::Mat(size,CV_8U);
	cv::resize(image_mmw, image2, size, 0, 0, 0);
	cv::Mat image3=image2(cv::Range(0, 504), cv::Range(0, 255));
	int a = 0, sum = 0;
	for(int i = 0; i < image3.rows; i++)
	{
		for(int j=0;j<image3.cols;j++)
		{
			if (image3.at<uchar>(i,j)!=0)
			{
				a=a+1;
			}
			sum=sum+image3.at<uchar>(i,j);
		}
	}
	int c=sum/a;
	for(int i=69;i<573;i++)
	{
		for(int j=275;j<530;j++)//��������6������
		{
			if(image3.at<uchar>(i-69,j-275)>7*c)
			{
				cv::Vec3b pixel;
				pixel[0]=255;
				pixel[1]=0;
				pixel[2]=0;
				image_fusion.at<cv::Vec3b>(i,j)=pixel;
			}
		}
	}
	return image_fusion;
}


cv::Mat ImageFushion::fusionBinary( cv::Mat & image_mmw,cv::Mat & image_visible)
{
	int scale=4;
	if (image_mmw.channels() == 3)
	{
		cv::cvtColor(image_mmw, image_mmw,CV_BGR2GRAY);
	}
	//ע��Ϊ�����Ч�ʣ��˴�����������ǳ�������ƻ�������Ŀɼ���ͼ������
	cv::Mat image_fusion = image_visible;
	cv::Size size=cv::Size(image_mmw.cols*scale, image_mmw.rows*scale);
	cv::Mat image2 = cv::Mat(size,CV_8U);
	cv::resize(image_mmw, image2,size,0,0,0);
	cv::Mat image3=image2(cv::Range(0,504),cv::Range(0,255));

	for(int i=69;i<573;i++)
	{
		for(int j=275;j<530;j++)//��������6������
		{
			if(image3.at<uchar>(i-69,j-275) == 255)
			{
				cv::Vec3b pixel;
				pixel[0]=255;
				pixel[1]=0;
				pixel[2]=0;
				image_fusion.at<cv::Vec3b>(i,j)=pixel;
			}
		}
	}
	return image_fusion;
}
