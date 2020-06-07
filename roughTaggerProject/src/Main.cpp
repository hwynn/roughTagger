#include "TestFileHelper.h"
#include "TestStructures.h"
#include "externalTestFiles1.h"
int main() {
	std::cout << "Hello World" << std::endl;
	testfilehelper::PrintMessage();

	//download everything
	for (size_t i = 0; i < testingmanager::g_allTestFiles.size(); i = i + 1) {
		testingmanager::g_allTestFiles[i].download();
	}

	//clone everything
	for (size_t i = 0; i < testingmanager::g_allTestFiles.size(); i = i + 1) {
		testingmanager::g_allTestFiles[i].clone();
	}

	//delete all clones
	for (size_t i = 0; i < testingmanager::g_allTestFiles.size(); i = i + 1) {
		//std::cout << testingmanager::g_allTestFiles[i].m_fullname << std::endl;
		testingmanager::g_allTestFiles[i].releaseClone();
	}

	//delete all original files
	for (size_t i = 0; i < testingmanager::g_allTestFiles.size(); i = i + 1) {
		testingmanager::g_allTestFiles[i].deleteFile();
	}


}