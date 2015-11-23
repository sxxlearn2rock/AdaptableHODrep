#pragma once
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>


class ImageFushion
{
public:
	ImageFushion(void);
	~ImageFushion(void);

	cv::Mat fusionGray( cv::Mat & image_mmw, cv::Mat & image_visible);
	cv::Mat fusionBinary( cv::Mat & image_mmw, cv::Mat & image_visible);
};

