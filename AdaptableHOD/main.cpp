#include "HOD.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	HOD hod;
	Mat input = imread("D:\\SXX\\TestPics\\HODTestPics\\1.png");
//	imshow("input", input);

	unsigned char* outputData = nullptr;

	bool result = false;

	hod.RealtimeAlgorithm(input.data,  input.cols, input.rows, result, outputData);
	Mat output(input.rows,input.cols, CV_8UC1, outputData);
	imshow("output", output);
	cout << result << endl;

	waitKey();
	return 0;
}