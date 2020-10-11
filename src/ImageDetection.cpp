#include"Header.h"

cv::Mat ImageDetection::imagePreprocessing(cv::Mat& image) 
{
	if (image.empty())
	{
		return cv::Mat();
	}
	int num_channel = image.channels();
	cv::Mat dst;
	if (1 == num_channel)
	{
		cv::edgePreservingFilter(image, dst);
		cv::threshold(dst, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_TRIANGLE);
	}
	else
	{
		cv::cvtColor(image, dst, cv::COLOR_BGR2GRAY);
		cv::edgePreservingFilter(dst, dst);
		cv::threshold(dst, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_TRIANGLE);
	}
	return dst;
}

