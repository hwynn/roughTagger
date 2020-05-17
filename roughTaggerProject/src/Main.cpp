#include "TestFileHelper.h"
#include "TestStructures.h"
int main() {
	std::cout << "Hello World" << std::endl;
	testfilehelper::PrintMessage();
	/*
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

	*/

	std::vector<std::string> g_googleIds = { "1pFEbWruySWWgNCShKP8qn8dJ9w7kXNKk", "1eED3AINVizIQV44DXxj91-s2Qa9EWsAX", "1euq0D6OrdWVkdC4RZdFIrre7WsQ7N9do", "1ofFpQYKFTJ9NLGUMiCLtz3X5awyBAx99", "1MQgoUI6tIQhkNMg7KIDeRraVsGhPrx0H" };
	std::vector<std::string> g_filenames = { "fixingComputer.jpg", "catScreamPizza.jpg", "rippledotzero.jpg", "Toaster.pdf", "creepyCharger.gif" };
	std::string g_path = "C:\\Users\\h\\Pictures\\";
	std::vector<std::string> g_fullfilenames;
	for (size_t i = 0; i < g_googleIds.size(); i = i + 1){
		testfilehelper::downloadFileWithPython(g_googleIds[i], g_path, g_filenames[i]);
		if (testfilehelper::fileExists(g_path + g_filenames[i])) {
			std::cout << "file exists!!!" << std::endl;
			testfilehelper::copyFile(g_path + g_filenames[i], g_path +"Copy0"+ g_filenames[i]);
		}
		else {std::cout << "the file isn't here yet" << std::endl;}
		if (testfilehelper::fileExists(g_path + "Copy0" + g_filenames[i])) {
			std::cout << "the copy file exists!!!" << std::endl;
			testfilehelper::deleteFile(g_path + "Copy0" + g_filenames[i]);
		}
		else {std::cout << "sorry" << std::endl;}
		g_fullfilenames.push_back(g_path + g_filenames[i]);
	}
	std::vector<std::string> g_clones = testfilehelper::cloneThese(g_fullfilenames);
	testfilehelper::releaseAllClones(g_fullfilenames);
}