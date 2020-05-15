#include "TestFileHelper.h"

int main() {
	std::cout << "Hello World" << std::endl;
	testfilehelper::PrintMessage();
	testfilehelper::commandLineTest();
	std::cout << "new test data instance created" << std::endl;
	testingmanager::TestData g_testdata1;
	testingmanager::printExistence(&g_testdata1);
	
	g_testdata1.setTitle("Sample Title");
	g_testdata1.setArtists({ "thing1", "thing2" });
	g_testdata1.setDescr("This is just uh...");
	g_testdata1.setRating(3);

	if (g_testdata1.containsTitle()) {
		std::cout << "we have a title" << std::endl;
	}
	else { std::cout << "we do NOT have a title" << std::endl; }

	testingmanager::printExistence(&g_testdata1);

	testingmanager::printPresentData(&g_testdata1);

	std::string g_st = "C:\\Users\\h\\Pictures\\catScreamPizza.jpg";

	testfilehelper::downloadFileWithPython("C:/Users/h/Pictures", "1eED3AINVizIQV44DXxj91-s2Qa9EWsAX");

	
	if (testfilehelper::fileExists("C:\\Users\\h\\Pictures\\catScreamPizza.jpg")) {
		std::cout << "file exists!!!" << std::endl;
		testfilehelper::copyFile("C:\\Users\\h\\Pictures\\catScreamPizza.jpg", "C:\\Users\\h\\Pictures\\panic.jpg");
	}
	else {
		std::cout << "the file isn't here yet" << std::endl;
	}
	
	if (testfilehelper::fileExists("C:\\Users\\h\\Pictures\\panic.jpg")) {
		std::cout << "the copy file exists!!!" << std::endl;
		testfilehelper::deleteFile("C:\\Users\\h\\Pictures\\panic.jpg");
	}
	else {
		std::cout << "sorry" << std::endl;
	}

}