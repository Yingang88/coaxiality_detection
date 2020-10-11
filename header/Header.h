#ifndef _HEADER_H_
#define _HEADER_H_
#include<iostream>
#include<opencv2/opencv.hpp>
#include<io.h>
#include<direct.h>

/**********FolderOfImage**********/
class FolderOfImage
{
private:
	char* _folderPath{nullptr};
	char* _imageType{nullptr};
	void _buildFileFullPath(std::string& fileFullPath, const std::string& fileName);
public:
	FolderOfImage(const char* folderName, const char* folderPath = "C:", const char* imageType = "jpg");
	virtual ~FolderOfImage();
	std::string getFolderPath()const;
	std::string getImageType()const;
	void setFolderPath(const char* folderPath);
	void setImageType(const char* imageType);
	bool createFolderInSystem();
	bool saveImageInFolder(const char* imagename, cv::Mat& image);
	static std::vector<std::string> findeImageFileSystem(const char* folderPath, const char* imageType = "*");
};
/*********************************/

/***********InitiCamera***********/
class InitiCamera
{
private:
	int _deviceID{ 0 };
	int _apiID{ cv::CAP_ANY };
	int _frameWidth{640};
	int _frameHeight{480};
	int _roiX{0};
	int _roiY{0};
	int _roiWidth{0};
	int _roiHeight{0};
	bool _highDisplayRate{ false };
	bool _setInitiCameraParameter();
public:
	InitiCamera(int deviceID = 0, int apiID = cv::CAP_ANY, int frameWidth = 640, int frameHeight = 480, bool highDisplayRate = false) 
		:_deviceID(deviceID), _apiID(apiID), _frameWidth(frameWidth), _frameHeight(frameHeight), _highDisplayRate(highDisplayRate)
	{
		_setInitiCameraParameter();
	}
	virtual ~InitiCamera() {};
	cv::Rect getRoiParameter()const;
	void setRoiParameter(int deviceID, int apiID, int frameWidth, int frameHeight, bool highDisplayRate);
};

/*********************************/

/***********ImageDetection***********/
class ImageDetection
{
public:
	cv::Mat imagePreprocessing(cv::Mat &image);

};





/************************************/

#endif // !_HEADER_H_
