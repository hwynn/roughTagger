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

	std::string getExtension(const std::string& p_filename) {
		int ext = '.';
		const char* cextension = NULL;
		const char* str = p_filename.c_str();
		cextension = strrchr(p_filename.c_str(), ext);

		if (cextension == NULL) {
			printf("Invalid extension encountered\n");
			return "";
		}

		size_t n = strlen(cextension);
		size_t foundat = cextension - str + 1;
		//printf("File extension is %s\n", cextension);
		std::string found1 (cextension, n);
		//std::string found2 (p_filename, foundat-1, n);//this is also valid
		return found1;
	}

	void commandLineTest() {
		//Note: This is not cross compatible
		//const char* x = "dir > test.txt";
		std::string y = "dir > test.txt";
		const char* x = y.c_str();
		std::system(x); // execute the UNIX command "ls -l >test.txt"
		//std::cout << std::ifstream("test.txt").rdbuf();
	}

	void downloadFileWithPython(std::string googleId, std::string targetLocation, std::string p_filename) {
		std::string condaLocation = "C:\\Users\\h\\Anaconda3\\Scripts\\";
		std::string scriptLocation = "C:\\Users\\h\\RealDocs\\programming.things\\projects\\scraps\\tagger\\";
		//targetLocation example: "C:/Users/h/Pictures"
		//googleId example: "1eED3AINVizIQV44DXxj91-s2Qa9EWsAX"
		//p_filename example: "rippledotzero.jpg"
		//char longCommand[300];
		std::string command = condaLocation + "conda run -n foo python "+ scriptLocation +"downloadGoogleDriveFile.py "
			+ googleId + " " + targetLocation + " " + p_filename;
		//strcpy(longCommand, "C:\\Users\\h\\Anaconda3\\Scripts\\conda run -n foo python C:\\Users\\h\\RealDocs\\programming.things\\projects\\scraps\\tagger\\downloadGoogleDriveFile.py ");
		//strcat(longCommand, googleId);
		//strcat(longCommand, " ");
		//strcat(longCommand, targetLocation);
		const char* longCommand = command.c_str();
		std::system(longCommand);
	}

	void PrintMessage() { std::cout << "The Library says Hello" << std::endl; }

	std::string singleClone(std::string p_filename, bool p_stop){
		if (!fileExists(p_filename)){
			return "";//TODO: remove this when we return error. throw OSError: if no file with p_filename is found
		}
		std::string ext = getExtension(p_filename);
		std::string f_name = p_filename.substr(0, p_filename.length() - ext.length());
		const std::string f_newfile = f_name + "Copy" + ext;
		if (fileExists(f_newfile)){
			if (p_stop) {
				std::cout << "File " << f_newfile << " already exists" << std::endl;//TODO: throw exception. ValueError
				return "";//TODO: remove this when we return error.
			}
			else {
				deleteFile(f_newfile);
			}
		}
		copyFile(p_filename, f_newfile);//TODO: does p_filename need to be const?
		return f_newfile;
	}

	std::vector<std::string> cloneThese(std::vector<std::string> p_filenames){
		std::vector<std::string> files;
		for (size_t i = 0; i < p_filenames.size(); i = i + 1) {
			files.push_back(singleClone(p_filenames[i],false));
		}
		return files;
	}

	void releaseAllClones(std::vector<std::string> p_clonelist){
		for (size_t i = 0; i < p_clonelist.size(); i = i + 1) {
			deleteFile(p_clonelist[i]);
		}
	}
}