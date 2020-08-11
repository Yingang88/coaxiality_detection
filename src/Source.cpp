#include"Header.h"

int main()
{
	// Test 1
	using namespace std;
	using namespace cv;
	const char* path = "C:";
	const char* path1 = "C:\\Users";
	ListFilePath test1(path);
	test1.findListFile();
	cout << test1 << endl;
	test1.setSearchDirPath(path1);
	cout << test1 << endl;
	test1.setSearchFileType("txt");
	cout << test1 << endl;

	// Test 2
	ImageGeneration test2(path);
	test2.generateImage();
	cout << test2 << endl;
	return 0;
}



