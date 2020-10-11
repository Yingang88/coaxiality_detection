#include "Header.h"

bool InitiCamera::_setInitiCameraParameter()
{
	cv::VideoCapture cap;
	cap.open(_deviceID, _apiID);
	if (true == _highDisplayRate)
	{
		// 1280 * 720
		cap.set(cv::CAP_PROP_FRAME_WIDTH, _frameWidth);
		cap.set(cv::CAP_PROP_FRAME_HEIGHT, _frameHeight);
		std::cout << "Die Auflösung der Kamera ist auf "<< _frameWidth<<" * " << _frameHeight <<" eingestellt." << std::endl;
	}
	if (!cap.isOpened())
	{
		std::cerr << "Die sich im System befindende Kamera kann nicht angeschaltet werden!" << std::endl;
		cap.release();
		return false;
	}
	cv::Mat frame,dst;
	std::string fensterName = "Einstellung der Kameraparameter";
	cv::namedWindow(fensterName, cv::WINDOW_AUTOSIZE);
	cv::Rect rect;
	for (;;)
	{
		cap.read(frame);
		//cv::bilateralFilter(frame, dst, 0,100, 10, 4);
		//cv::edgePreservingFilter(frame, frame);
		if (frame.empty())
		{
			std::cout << "Ein leerer Rahmen wurde gelesen!" << std::endl;
			cap.release();
			return false;
		}
		int ch = cv::waitKey(1);
		if (27 == ch)
		{
			break;
		}
		// TODO
		if ('r' == ch)
		{
			rect = cv::selectROI("Einstellung der Kameraparameter", frame);
			if (!rect.empty())
			{
				_roiX = rect.x;
				_roiY = rect.y;
				_roiWidth = rect.width;
				_roiHeight = rect.height;
			}
		}
		if (0 != _roiWidth)
		{
			cv::rectangle(frame,cv::Rect(_roiX,_roiY,_roiWidth,_roiHeight),cv::Scalar(255,0,0),2,8,0);
		}
		/***********/
		cv::imshow(fensterName, frame);
	}
	cv::destroyAllWindows();
	cap.release();
	return true;
}

cv::Rect InitiCamera::getRoiParameter() const
{
	return cv::Rect(_roiX,_roiY,_roiWidth,_roiHeight);
}

void InitiCamera::setRoiParameter(int deviceID, int apiID, int frameWidth, int frameHeight, bool highDisplayRate)
{
	_deviceID = deviceID;
	_apiID = apiID;
	_frameWidth = frameWidth;
	_frameHeight = frameHeight;
	_highDisplayRate = highDisplayRate;
	if (!_setInitiCameraParameter())
	{
		std::cout << "ROI-Parametereinstellung ist misslungen." << std::endl;
		return;
	}
	std::cout << "ROI-Parametereinstellung ist gelungen." << std::endl;
	return;
}
