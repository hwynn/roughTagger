#ifndef TESTFILEHELPER_H
#define TESTFILEHELPER_H
#include "TestStructures.h"
#include <string>
#include <iostream>

//These are functions  manage files to help automate unit testing.
//These functions are used with files immediately. 
//We don't need to package them in the TestFile class first.
namespace testfilehelper {

    //Checks if a file exists
    //p_filename: full filename including the path
    bool fileExists(const std::string& p_filename);

    //Copies a file
    //p_filename1: full filename including the path of existing file we want to copy
    //Note: we assume file1 exists without checking.
    //p_filename2: full filename including the path of the copy file we're going to create
    //Note: we assume file1 exists without checking.
    //TODO: maybe throw errors instead of assuming stuff?
    void copyFile(const std::string& p_filename1, const std::string& p_filename2);

    //Deletes a file
    //p_filename: full filename including the path
    void deleteFile(const std::string& p_filename);

    //this function checks the type of the file.
    //: param p_filepathname : the path/name of the file

    //Given a filename, returns the extension of a file.
    //example: BigHat.png -> .png
    //example: c:\\.directoryname\\file.name.with.too.many.dots.ext -> .ext
    //Note: returns "" if no extension is found.
    //src: https://stackoverflow.com/a/59923175/3561314
    std::string getExtension(const std::string& p_filename);

    //The oldest function in this file.
    //This was used to test running a windows command from a c++ file
	void commandLineTest();

	//downloads a file from google drive into a specified location
    //Note: This relies on a python script, the name and location of which are hardcoded into this function.
    //Note: This relies on anaconda. The installation path is hardcoded into this function. 
    //Note: this is definitely NOT thread safe.
    //targetLocation is just the path of the file without the filename.
    //googleId is the unique id in the url of the file in google drive. 
    //p_filename: full filename DOES NOT INCLUDE THE PATH
	void downloadFileWithPython(std::string googleId, std::string targetLocation, std::string p_filename);

	void PrintMessage();

    //creates a copy of a file and gives the copy a "clone name".
    //Used to create fresh files for metadata editting tests
    //example:
    //given a file home/user/pictures/birds.jpg exists,
    //singleClone('home/user/pictures/birds.jpg')
    //will return "home/user/pictures/birdsCopy.jpg"
    //and 'home/user/pictures/birdsCopy.jpg' will be created
    //Note: according to the shutil documentation, this might not copy all metadata
    //:param p_filename: full filename including the path
    //:param p_stop: True if we want to prevent existing clones from being overwritten (default: False)
    //:raise OSError: if no file with p_filename is found
    //:raise ValueError: if p_stop is True and a file with a clone's name already exists
    //:return: name of the cloned file including the path
    std::string singleClone(std::string p_filename, bool p_stop);

    //creates a copies of several files at once.
    //Used to create fresh files for metadata editting tests.
    //For a given test, we give this function a list of the files needed.
    //:param p_filenames: full filenames including the paths
    //:raise OSError: if no file with p_filename is found
    //:raise ValueError: if p_stop is True and a file with a clone's name already exists
    //:return: names of the cloned files including the paths
    std::vector<std::string> cloneThese(std::vector<std::string> p_filenames);

    //Removes several files at once.
    //p_clonelist should be obtained from cloneThis()
    //Used for testing to clean up files left by previous tests
    //Used with singleClone() or cloneThese(). Removes the copy that function created.
    //:param p_clonelist: full filenames including their paths
    void releaseAllClones(std::vector<std::string> p_clonelist);
}
#endif