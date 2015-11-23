#include "SingleFramesProcessor.h"
#include "ImageFushion.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	SingleFramesProcessor hod("D:\\SXX\\Projects\\HOD资料\\背景图像及背景减除\\毫米波_背景.jpg");
	Mat input = imread("D:\\SXX\\Projects\\HOD资料\\2015.11.6样品\\24fps-大扳手\\毫米波_49.jpg");
	Mat visual = imread("D:\\SXX\\Projects\\HOD资料\\2015.11.6样品\\24fps-大扳手\\可见光_49.jpg");

//	imshow("f", f.fusionGray(input, visual));
//	imshow("input", input);

	unsigned char* outputData = nullptr;
	unsigned char* fushionDate = nullptr;

	bool result = false;

	hod.RealtimeAlgorithm(input.data, visual.data, input.cols, input.rows, visual.cols, visual.rows, result, outputData, fushionDate);
	Mat output(input.rows,input.cols, CV_8UC1, outputData);
		imshow("output", output);
	if(fushionDate != nullptr)	
	{
		Mat fusionMat(visual.rows, visual.cols, CV_8UC3, fushionDate);
		imshow("fushion", fusionMat);
	}

	cout << result << endl;

	waitKey();
	return 0;
}