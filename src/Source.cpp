#include"Header.h"

int main()
{
	using namespace std;
	using namespace cv;
	FolderOfImage test("CameradetectedData");
	//Testchar ch("asdfasdf");
	string path ,type;
	//test.setFolderPath("D:\\Users\\Zhao\\source\\repos\\DemoVision1");
	//test.setImageType("png");
	path = test.getFolderPath();
	type = test.getImageType();
	test.createFolderInSystem();

	return 0;
}