#include "Header.h"

ListFilePath::~ListFilePath()
{
	m_filesPathList.clear();
}

bool ListFilePath::setSearchDirPath(const char* _dirPath)
{
	if (!setDirPath(_dirPath))
	{	
		std::cerr << "The new search path cannot be set!" << std::endl;
		return false;
	}
	m_filesPathList.clear();
	if (!findListFile())
	{
		return false;
	}
	return true;

}

bool ListFilePath::setSearchFileType(const char* _fileType)
{
	if (!setFileType(_fileType))
	{
		std::cerr << "The new search file type cannot be set!" << std::endl;
		return false;
	}
	m_filesPathList.clear();
	if (!findListFile())
	{
		return false;
	}
	return true;
}

bool ListFilePath::findListFile()
{
	if (!m_fullPath)
	{
		std::cerr << "The new search path cannot be set and list is empty!" << std::endl;
		return false;
	}
	intptr_t handle;
	_finddata_t findData;
	handle = _findfirst(m_fullPath, &findData);
	if (-1 == handle)
	{
		std::cout << "Can't find the required file!" << std::endl;
		_findclose(handle);
		return false;
	}
	m_filesPathList.clear();
	do
	{
		std::string tmp = std::string(m_dirPath) + findData.name;
		m_filesPathList.push_back(tmp);
	} while (0 == _findnext(handle, &findData));
	_findclose(handle);
	return true;
}

const std::vector<std::string>& ListFilePath::getfilesPathList() const
{
	return m_filesPathList;
}
