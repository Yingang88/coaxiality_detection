#ifndef _HEADER_H_
#define _HEADER_H_
#include<iostream>
#include<vector>
#include<io.h>
#include<fstream>
#include<opencv2/opencv.hpp>

/*******************************************************/
class FilePath
{
private:
	FilePath(const FilePath&);
	FilePath& operator=(const FilePath&) {};
protected:
	char* m_dirPath{ nullptr };						// directory path
	char* m_suffix{ nullptr };							// file suffix
	char* m_fileName{ nullptr };
	char* m_fullPath{ nullptr };						// file full path

	bool buildDirPath(const char* _dirPath);			// build directory path	
	bool buildSuffix(const char* _fileType);			// build suffix path
	bool buildFullPath(const char* _fileName);			// build full file path
public:
	// constructor
	FilePath(const char* _dirPath, const char* _suffix = "*", const char* _fileName = "*");
	// destructor
	virtual ~FilePath();

	// others methods
	bool setDirPath(const char* _dirPath);				// set new directory path and update full path
	bool setFileType(const char* _fileType);			// set new suffix and update full path
	bool setFileName(const char* _fileName);			// set search file name, the default is *
	const char* getFileName()const;
	const char* getFullPath()const;							// get full file path
	// overload operator methods

	// overload operator friends
	friend std::ostream& operator<<(std::ostream& _os, const FilePath& _fp);

};

/***************************************************************/
class ListFilePath :protected FilePath
{
protected:
	std::vector<std::string> m_filesPathList{"Empty!"};				// List of storage file paths
public:
	// constructor
	ListFilePath(const char* _dirPath, const char* _suffix = "*", const char* _fileName = "*") :FilePath(_dirPath, _suffix, _fileName){}
	// destructor
	virtual ~ListFilePath();

	// others methods
	bool setSearchDirPath(const char* _dirPath);					// set new search directory path
	bool setSearchFileType(const char* _fileType);					// set new search file type
	bool findListFile();											// search files and save files list
	// overload operator methods
	const std::vector<std::string> &getfilesPathList()const;			// get full file path list
	// overload operator friends
	friend std::ostream& operator<<(std::ostream& _os, const ListFilePath& _sfp);
};

class ImageGeneration :protected FilePath
{
protected:
	int m_deviceID{0};											// camera device number (0 = open default camera)
	int m_apiID{0};												// API ID (0 = autodetect default API)
	std::vector<std::string> m_filesPathList{ "Empty!" };				// List of storage file paths
public:
	// constructor
	ImageGeneration(const char* _dirPath, const char* _suffix = "jpg", const char* _fileName = "bild", int _deviceID = 0, int _apiID = 0) :FilePath(_dirPath, _suffix, _fileName), m_deviceID(_deviceID), m_apiID(_apiID) {}
	// destructor
	virtual ~ImageGeneration();

	// others methods
	bool setDeviceID(int _deviceID);								// set device ID
	bool setApiID(int _apiID);										// set API ID

	//bool setImageGeneration();

	int getDeviceID()const { return m_deviceID; }					// get device ID
	int getApiId()const { return m_apiID; }							// get API ID
	const std::vector<std::string>& getfilesPathList()const;			// get full file path list

	// generate picture and save files list
	bool generateImage(const int _count = 10, const int _waitTime = 50);
	// overload operator methods


	// overload operator friends
	friend std::ostream& operator<<(std::ostream& _os, const ImageGeneration& _ig);
};
#endif // !_HEADER_H_
