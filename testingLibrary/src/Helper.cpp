#include "Helper.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
namespace helper {

	void commandLineTest() {
		//const char* x = "dir > test.txt";
		std::string y = "dir > test.txt";
		const char* x = y.c_str();
		std::system(x); // execute the UNIX command "ls -l >test.txt"
		//std::cout << std::ifstream("test.txt").rdbuf();
	}

	void downloadFileWithPython(std::string targetLocation, std::string googleId) {
		//const std::string condaLocation = "C:\\Users\\h\\Anaconda3\\Scripts\\";
		//targetLocation example: "C:/Users/h/Pictures"
		//googleId example: "1eED3AINVizIQV44DXxj91-s2Qa9EWsAX"
		//char longCommand[300];
		std::string command = "C:\\Users\\h\\Anaconda3\\Scripts\\conda run -n foo python C:\\Users\\h\\RealDocs\\programming.things\\projects\\scraps\\tagger\\downloadGoogleDriveFile.py "
			+ googleId + " " + targetLocation;
		//strcpy(longCommand, "C:\\Users\\h\\Anaconda3\\Scripts\\conda run -n foo python C:\\Users\\h\\RealDocs\\programming.things\\projects\\scraps\\tagger\\downloadGoogleDriveFile.py ");
		//strcat(longCommand, googleId);
		//strcat(longCommand, " ");
		//strcat(longCommand, targetLocation);
		const char* longCommand = command.c_str();
		std::system(longCommand);
	}

	void PrintMessage() { std::cout << "The Library says Hello" << std::endl; }

}