#include"Header.h"

bool FilePath::buildDirPath(const char* _dirPath)
{
	if (_dirPath == nullptr)
	{
		return false;
	}
	size_t len = strlen(_dirPath) + 3;
	m_dirPath = new char[len];
	if (!m_dirPath)
	{
		return false;
	}
	strcpy_s(m_dirPath, len, _dirPath);
	strcat_s(m_dirPath, len, "\\");
	return true;
}

bool FilePath::buildSuffix(const char* _fileType)
{
	if (_fileType == nullptr)
	{
		return false;
	}
	size_t len = strlen(_fileType);
	m_suffix = new char[len + size_t(2)];
	if (!m_suffix)
	{
		return false;
	}
	m_suffix[0] = '.';
	for (auto i = 0; i < len; ++i)
	{
		m_suffix[i + 1] = _fileType[i];
	}
	m_suffix[len + 1] = '\0';
	return true;
}

bool FilePath::buildFullPath(const char* _fileName)
{
	if (m_dirPath && m_suffix)
	{
		size_t len = strlen(m_dirPath) + strlen(_fileName) + strlen(m_suffix) + 1;
		m_fullPath = new char[len];
		if (!m_fullPath)
		{
			return false;
		}
		strcpy_s(m_fullPath, len, m_dirPath);
		strcat_s(m_fullPath, len, _fileName);
		strcat_s(m_fullPath, len, m_suffix);
		return true;

	}
	return false;
}

FilePath::FilePath(const char* _dirPath, const char* _suffix, const char* _fileName)
{
	size_t len = strlen(_fileName);
	m_fileName = new char[len + size_t(1)];
	if (!m_fileName)
	{
		return;
	}
	strcpy_s(m_fileName, len + size_t(1), _fileName);
	if (!buildDirPath(_dirPath))
	{
		std::cerr << "Error! Incorrect directory path!";
		return;
	}
	if (!buildSuffix(_suffix))
	{
		std::cerr << "Error! The suffix name is incorrectly entered!";
		return;
	}
	if (!buildFullPath(m_fileName))
	{
		std::cerr << "Error! A full path cannot be created!";
	}
}



FilePath::~FilePath()
{
	delete m_dirPath;
	delete m_suffix;
	delete m_fileName;
	delete m_fullPath;
	//std::cout << "destructor of FilePath!"<<std::endl;
}

bool FilePath::setDirPath(const char* _dirPath)
{
	if (!_dirPath)
	{
		return false;
	}
	delete m_dirPath;
	if (!buildDirPath(_dirPath))
	{
		return false;
	}
	delete m_fullPath;
	if (!buildFullPath(m_fileName))
	{
		return false;
	}
	return true;
}

bool FilePath::setFileType(const char* _fileType)
{
	if (!_fileType)
	{
		return false;
	}
	delete m_suffix;
	if (!buildSuffix(_fileType))
	{
		return false;
	}
	delete m_fullPath;
	if (!buildFullPath(m_fileName))
	{
		return false;
	}
	return true;
}

bool FilePath::setFileName(const char* _fileName)
{
	if (!_fileName)
	{
		return false;
	}
	if (!strcmp(m_fileName, _fileName))
	{
		return false;
	}
	delete m_fileName;
	size_t len = strlen(_fileName);
	m_fileName = new char[len + size_t(1)];
	strcpy_s(m_fileName, len + size_t(1), _fileName);
	if (!buildFullPath(m_fileName))
	{
		return false;
	}
	return true;
}

const char* FilePath::getFileName() const
{
	return m_fileName;
}

const char* FilePath::getFullPath() const
{
	if (!m_fullPath)
	{
		std::cout << "Error! Path is empty!" << std::endl;
		return nullptr;
	}
	return m_fullPath;
}

std::ostream& operator<<(std::ostream& _os, const FilePath& _fp)
{
	_os << _fp.m_fullPath << std::endl;
	return _os;
}

std::ostream& operator<<(std::ostream& _os, const ListFilePath& _sfp)
{
	for (auto i = 0; i < _sfp.m_filesPathList.size(); ++i)
	{
		_os << _sfp.m_filesPathList[i]<< std::endl;
	}
	return _os;
}

std::ostream& operator<<(std::ostream& _os, const ImageGeneration& _ig)
{
	for (auto i = 0; i < _ig.m_filesPathList.size(); ++i)
	{
		_os << _ig.m_filesPathList[i] << std::endl;
	}
	return _os;
}
