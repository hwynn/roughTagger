#include "TestFileHelper.h"
#include <cstdlib>
#include <sys/stat.h>
#include <stdio.h>
#include <fstream>
namespace testfilehelper {

	bool fileExists(const std::string& p_filename) {
		struct stat buffer;
		return (stat(p_filename.c_str(), &buffer) == 0);
	}

	void copyFile(const std::string& p_filename1, const std::string& p_filename2) {
		//maybe switch to using fopen_s? A lot of people on coding forums said this isn't really an issue though.
		register int key;

		FILE* fp1, * fp2;

		fp1 = fopen(p_filename1.c_str(), "rb");
		fp2 = fopen(p_filename2.c_str(), "wb");

		while ((key = fgetc(fp1)) != EOF)
		{
			fputc(key, fp2);
		}
		fclose(fp1); fclose(fp2);
	}

	void deleteFile(const std::string& p_filename){
		remove(p_filename.c_str());
	}

	void commandLineTest() {
		//Note: This is not cross compatible
		//const char* x = "dir > test.txt";
		std::string y = "dir > test.txt";
		const char* x = y.c_str();
		std::system(x); // execute the UNIX command "ls -l >test.txt"
		//std::cout << std::ifstream("test.txt").rdbuf();
	}

	void downloadFileWithPython(std::string targetLocation, std::string googleId) {
		std::string condaLocation = "C:\\Users\\h\\Anaconda3\\Scripts\\";
		std::string scriptLocation = "C:\\Users\\h\\RealDocs\\programming.things\\projects\\scraps\\tagger\\";
		//targetLocation example: "C:/Users/h/Pictures"
		//googleId example: "1eED3AINVizIQV44DXxj91-s2Qa9EWsAX"
		//char longCommand[300];
		std::string command = condaLocation + "conda run -n foo python "+ scriptLocation +"downloadGoogleDriveFile.py "
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