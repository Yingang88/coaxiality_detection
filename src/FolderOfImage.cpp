#include"Header.h"


void FolderOfImage::_buildFileFullPath(std::string& fileFullPath,const std::string& fileName)
{
	if (nullptr == _folderPath || nullptr == _imageType)
	{
		std::cerr << "Fehler! Bei der Erstellung des vollständigen Filepfad!" << std::endl;
		fileFullPath = "\0";
		return;
	}
	// TODO checken die Size von string;
	fileFullPath = _folderPath + fileName + "." + _imageType;
}

FolderOfImage::FolderOfImage(const char* folderName, const char* folderPath, const char* imageType)
{
	if (nullptr == folderPath)
	{
		// TODO checken das Eingabeformat z.B."C:\\CameraFolder\\"
		_folderPath = new char[1];
		strcpy_s(_folderPath, 1, "\0");
		std::cerr<<"Das Pfad des Ordners wird falsch eingegeben! "<<std::endl;
		return;
	}
	if (nullptr == imageType)
	{
		// TODO checken das Eingabeformat z.B."jpg,png..."
		_imageType = new char[1];
		strcpy_s(_imageType, 1, "\0");
		std::cerr << "Der Datentyp des Bildes wird falsch eingegeben! " << std::endl;
		return;
	}
	if (nullptr == folderName)
	{
		// TODO 
		_folderPath = new char[1];
		strcpy_s(_folderPath, 1, "\0");
		_imageType = new char[1];
		strcpy_s(_imageType, 1, "\0");
		std::cerr << "Der Ordnername des Bildes wird falsch eingegeben! " << std::endl;
		return;
	}
	rsize_t fLen = strlen(folderPath) + strlen(folderName);
	//rsize_t nLen = strlen(folderName);
	rsize_t iLen = strlen(imageType);
	_folderPath = new char[fLen + 5];
	if (nullptr ==_folderPath)
	{
		std::cerr << "Fehler! Bei Folder_Path!" << std::endl;
		return;
	}
	_imageType = new char[iLen + 1];
	if (nullptr ==_imageType)
	{
		std::cerr << "Fehler! Bei Image_Type!" << std::endl;
		return;
	}
	strcpy_s(_folderPath, fLen + 5,folderPath);
	strcat_s(_folderPath, fLen + 5, "\\");
	strcat_s(_folderPath, fLen + 5, folderName);
	strcat_s(_folderPath, fLen + 5, "\\");
	strcpy_s(_imageType, iLen + 1, imageType);
	//std::cout << _folderPath << std::endl;
	//std::cout << _imageType << std::endl;
}

FolderOfImage::~FolderOfImage()
{
	delete[] _folderPath;
	_folderPath = nullptr;
	delete[] _imageType;
	_imageType = nullptr;
}

std::string FolderOfImage::getFolderPath() const
{
	if (nullptr == _folderPath)
	{
		std::cerr << "Fehler! Bei Folder_Path!" << std::endl;
		return "\0";
	}
	return std::string(_folderPath);
}

std::string FolderOfImage::getImageType() const
{
	if (nullptr == _imageType)
	{
		std::cerr << "Fehler! Bei Image_Type!" << std::endl;
		return "\0";
	}
	return std::string(_imageType);
}

void FolderOfImage::setFolderPath(const char* folderPath)
{
	if (nullptr == folderPath)
	{
		// TODO checken das Eingabeformat z.B."C:\\CameraFolder\\"
		std::cerr << "Das Pfad des Ordners wird falsch eingegeben! " << std::endl;
		return;
	}
	delete[] _folderPath;
	rsize_t fLen = strlen(folderPath);
	_folderPath = new char[fLen + 3];
	if (nullptr == _folderPath)
	{
		std::cerr << "Fehler! Bei Folder_Path!" << std::endl;
		return;
	}
	strcpy_s(_folderPath, fLen + 3, folderPath);
	strcat_s(_folderPath, fLen + 3, "\\");
}

void FolderOfImage::setImageType(const char* imageType)
{
	if (nullptr == imageType)
	{
		// TODO checken das Eingabeformat z.B."jpg,png..."
		std::cerr << "Der Datentyp des Bildes wird falsch eingegeben! " << std::endl;
		return;
	}
	rsize_t iLen = strlen(imageType);
	_imageType = new char[iLen + 1];
	if (nullptr == _imageType)
	{
		std::cerr << "Fehler! Bei Image_Type!" << std::endl;
		return;
	}
	strcpy_s(_imageType, iLen + 1, imageType);
}

bool FolderOfImage::createFolderInSystem()
{
	if (nullptr == _folderPath || nullptr == _imageType)
	{
		std::cerr<<"Fehler Bei der Erstellung des Ordners im System!"<<std::endl;
		return false;
	}
	std::string tmp(_folderPath);
	tmp.pop_back();
	if (0 != _access(tmp.c_str(), 0))
	{
		if (0 == !_mkdir(tmp.c_str()))
		{
			std::cout << "Folder creation failed!" << std::endl;
			return false;
		}
		else
		{
			std::cout << "Folder creation successful!" << std::endl;
			return true;
		}
	}
	else
	{
		std::cout << "The folder already exists!" << std::endl;
		return true;
	}
	
	std::cout << "The Folder path does not exist!" << std::endl;
	return false;
}

bool FolderOfImage::saveImageInFolder(const char* imagename, cv::Mat& image)
{
	if (nullptr == imagename)
	{
		std::cerr << "Das Eingabeformat des ImageName ist falsch!" << std::endl;
		return false;
	}
	if (image.empty())
	{
		std::cerr << "Die Matrix des Bildes ist eine Leermatrix!" << std::endl;
		return false;
	}
	std::string path;
	_buildFileFullPath(path, imagename);
	//std::cout << path << std::endl;

	//TODO checken path Format 
	if (true == cv::imwrite(path, image))
	{
		return true;
	}
	return false;
}

std::vector<std::string> FolderOfImage::findeImageFileSystem(const char* folderPath, const char* imageType)
{
	if (nullptr == folderPath || nullptr == imageType)
	{
		std::cerr << "Die Erstellung des Dateisuchpfads entsteht ein Fehler!" << std::endl;
		std::string tmp = "\0";
		std::vector<std::string> listFiles;
		listFiles.push_back(tmp);
		return listFiles;
	}
	std::string folderFullPath = std::string(folderPath) + "\\";
	std::string fileSearchPath = folderFullPath;
	fileSearchPath.append("*.");
	fileSearchPath.append(imageType);
	std::cout << fileSearchPath << std::endl;
	intptr_t handle;
	_finddata_t findData;
	handle = _findfirst(fileSearchPath.c_str(), &findData);
	if (-1 == handle)
	{
		std::cout << "Die durchsuchende Datei kann nicht gefunden werden!" << std::endl;
		std::string tmp = "\0";
		std::vector<std::string> listFiles;
		listFiles.push_back(tmp);
		_findclose(handle);
		return listFiles;
	}
	std::string tmp;
	std::vector<std::string> listFiles;
	do
	{
		tmp = folderFullPath + findData.name;
		listFiles.push_back(tmp);
	}while (0 == _findnext(handle, &findData));
	_findclose(handle);
	return listFiles;
}
