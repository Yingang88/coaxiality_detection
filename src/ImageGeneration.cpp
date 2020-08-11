#include"Header.h"

ImageGeneration::~ImageGeneration()
{
	m_filesPathList.clear();
}

bool ImageGeneration::setDeviceID(int _deviceID)
{
	m_deviceID = _deviceID;
	m_filesPathList.clear();
	if (generateImage())
	{
		return true;
	}
	return false;
}

bool ImageGeneration::setApiID(int _apiID)
{	
	m_apiID = _apiID;
	m_filesPathList.clear();
	if (generateImage())
	{
		return true;
	}
	return false;
}

const std::vector<std::string>& ImageGeneration::getfilesPathList() const
{
	return m_filesPathList;
}

bool ImageGeneration::generateImage(const int _count, const int _waitTime)
{
	cv::Mat frame;
	cv::VideoCapture cap;
	cap.open(m_deviceID, m_apiID);

	if (!cap.isOpened())
	{
		std::cerr << "Error! Unable to open camera!" << std::endl;
		frame.release();
		cap.release();
		return false;
	}
	int count = 0;
	m_filesPathList.clear();
	std::cout << "************************************************\n" 
			    "*            Please save "<< _count<<" pictures.          *\n"
		        "*         s:save                   q:quit      *\n"
		        "************************************************" << std::endl;
	for (;;)
	{	
		if (count >= _count)
		{
			break;
		}
		cap.read(frame);
		if (frame.empty())
		{
			std::cerr << "Error! blank frame grabbed!" << std::endl;
			frame.release();
			cap.release();
			return false;
		}
		cv::imshow("frame", frame);
		char c = cv::waitKey(_waitTime);
		//char c = std::cin.get();
		if ('s' == c)
		{
			std::string bildname = std::string(m_fileName) + cv::format("_%d", count) + std::string(m_suffix);
			std::string tmp = std::string(m_dirPath) +  bildname;
			cv::imwrite(tmp, frame);
			m_filesPathList.push_back(tmp);
			++count;
			std::cout << bildname << std::endl;
		}
		if ('q' == c)
		{
			break;
		}
	}
	frame.release();
	cap.release();
	return true;
}