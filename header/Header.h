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

	// TODO 
	/*bool saveImageInFolder(const char* name, cv::Mat& image, int flag);
	static std::vector<std::string> findeImageFileSystem(const char* folderPath, const char* imageType);*/
};
/*********************************/

#endif // !_HEADER_H_
