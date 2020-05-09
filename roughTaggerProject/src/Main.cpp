#include <iostream>
#include "Helper.h"
#include <sys/stat.h>
#include <fstream>
inline bool exists_test3(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

int main() {
	std::cout << "Hello World" << std::endl;
	helper::PrintMessage();
	helper::commandLineTest();
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