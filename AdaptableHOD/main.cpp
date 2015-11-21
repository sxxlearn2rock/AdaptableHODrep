#include "HOD.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	HOD hod("D:\\SXX\\Projects\\HOD资料\\背景图像及背景减除\\毫米波_背景.jpg");
	Mat input = imread("D:\\SXX\\Projects\\HOD资料\\2015.11.6样品\\24fps-大扳手\\毫米波_56.jpg");
	imshow("input", input);
// 	Mat background = imread("D:\\SXX\\Projects\\HOD资料\\背景图像及背景减除\\毫米波_背景.jpg");
// 	cv::addWeighted(input, 1, background, -1, 0, input);
// 	imshow("de", input);

	unsigned char* outputData = nullptr;

	bool result = false;

	hod.RealtimeAlgorithm(input.data,  input.cols, input.rows, result, outputData);
	Mat output(input.rows,input.cols, CV_8UC1, outputData);
	imshow("output", output);
	cout << result << endl;

	waitKey();
	return 0;
}