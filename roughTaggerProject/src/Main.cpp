#include "Helper.h"
#include "TestStructures.h"

int main() {
	std::cout << "Hello World" << std::endl;
	helper::PrintMessage();
	helper::commandLineTest();
	std::cout << "new test data instance created" << std::endl;
	testingmanager::TestData g_testdata1;
	std::cout << g_testdata1.m_hasTitle << std::endl;

	for (int i = 0; i < testingmanager::g_metatypes.size(); i = i + 1){
		std::cout << "Existence of " << testingmanager::g_metatypes[i] << ": ";
		//bool i_exists = g_testdata1.containsData(testingmanager::g_metatypes[i]);
		//std::cout << i_exists << std::endl;
	}
	/*
	if (g_testdata1.containsTitle()) {
		std::cout << "we have a title" << std::endl;
	}
	else { std::cout << "we do NOT have a title" << std::endl; }*/

	//g_metatypes
	//helper::downloadFileWithPython("C:/Users/h/Pictures", "1eED3AINVizIQV44DXxj91-s2Qa9EWsAX");
	//existence::exists_test3("C:\\Users\\h\\Pictures\\catScreamPizza.jpg");
	/*
	if (exists_test3("C:\\Users\\h\\Pictures\\catScreamPizza.jpg")) {
		std::cout << "file exists!!!" << std::endl;
	}
	else {
		std::cout << "the file isn't here yet" << std::endl;
	}
	*/
	//TODO: test download google drive file command to see if it works. 

	//TODO: test download google drive file command and check if the file exists on the next line. This might be a race condition. 

	//http://www.cplusplus.com/forum/general/1796/
	//https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c

}