#ifndef TESTFILEHELPER_H
#define TESTFILEHELPER_H
#include "TestStructures.h"
#include <string>
#include <iostream>
namespace testfilehelper {

	//C:\Users\h\Anaconda3\Scripts\conda run -n foo python C:\Users\h\RealDocs\programming.things\projects\scraps\tagger\downloadGoogleDriveFile.py 1eED3AINVizIQV44DXxj91-s2Qa9EWsAX C:/Users/h/Pictures

	//const std::string condaLocation = "C:\\Users\\h\\Anaconda3\\Scripts\\";


    //Checks if a file exists
    //p_filename: full filename including the path
    bool fileExists(const std::string& p_filename);

    //Copies a file
    //p_filename1: full filename including the path of existing file we want to copy
    //Note: we assume file1 exists without checking.
    //p_filename2: full filename including the path of the copy file we're going to create
    //Note: we assume file1 exists without checking.
    void copyFile(const std::string& p_filename1, const std::string& p_filename2);

    //Deletes a file
    //p_filename: full filename including the path
    void deleteFile(const std::string& p_filename);

    //The oldest function in this file.
    //This was used to test running a windows command from a c++ file
	void commandLineTest();

	//downloads a file from google drive into a specified location
    //Note: This relies on a python script, the name and location of which are hardcoded into this function.
    //Note: This relies on anaconda. The installation path is hardcoded into this function. 
    //Note: this is definitely NOT thread safe.
    //targetLocation is just the path of the file without the filename.
    //googleId is the unique id in the url of the file in google drive. 
	void downloadFileWithPython(std::string targetLocation, std::string googleId);

	void PrintMessage();

	/*
    //TODO: make files for TestFile class. 
    //TODO: make al all of these python functions in c++.
	def downloadGooglePicture(p_file, p_path=g_outpath):
    """
    Downloads a picture from google drive for testing purposes
    :param p_file: information about the test file, including filename and googleID
    :type p_file: TestFile class instance
    :param p_path: path the files will be saved to (default: g_outpath imported from TData)
    :type p_path: string
    """
	
	def loadFiles(p_allFiles):
    """
    Downloads a list of files from google drive if we haven't downloaded them already.
    Used for testing purposes.
    :param p_allFiles: information about each test file, including filename and googleID
    :type p_file: list<TestFile class instance>

    :return: full names of the files loaded including their paths. This includes the prexisting files.
    :rtype: list<string>

    def singleClone(p_filename, p_stop=False):
    """
    creates a copy of a file and gives the copy a "clone name".
    Used to create fresh files for metadata editting tests
    example:
        given a file home/user/pictures/birds.jpg exists,
        singleClone('home/user/pictures/birds.jpg')
        will return "home/user/pictures/birdsCopy.jpg"
        and 'home/user/pictures/birdsCopy.jpg' will be created
    Note: according to the shutil documentation, this might not copy all metadata
    :param p_filename: full filename including the path
    :type p_filename: string
    :param p_stop: True if we want to prevent existing clones from being overwritten (default: False)
    :type p_stop: Boolean

    :raise OSError: if no file with p_filename is found
    :raise ValueError: if p_stop is True and a file with a clone's name already exists

    :return: name of the cloned file including the path
    :rtype: string
    """

    def cloneThese(p_filenames):
    """
    creates a copies of several files at once.
    Used to create fresh files for metadata editting tests.
    For a given test, we give this function a list of the files needed.
    :param p_filenames: full filenames including the paths
    :type p_filename: list<string>

    :raise OSError: if no file with p_filename is found
    :raise ValueError: if p_stop is True and a file with a clone's name already exists

    :return: names of the cloned files including the paths
    :rtype: list<string>
    """


    removeAllFiles(p_fileList=g_fileList ,p_path=g_outpath):
    """
    removes several files at once.
    Used for testing to remove original or copied files once they aren't needed
    :param p_fileList: information about each test file including filenames (default: g_fileList from TData)
    :type p_fileList: list<TestFile class instance>
    :param p_path: path the files will be saved to (default: g_outpath imported from TData)
    :type p_path: string
    """


    singleRelease(p_filename):
    """
    removes a file. Redundant
    Used with singleClone(). Removes the copy that function created.
    :param p_filename: full filename including the path
    :type p_filename: string

    :raise OSError: if no file with p_filename is found

    :return: name of the cloned file including the path
    :rtype: string
    """


    releaseAllClones(p_clonelist):
    """
    Removes several files at once.
    p_clonelist should be obtained from cloneThis()
    Used for testing to clean up files left by previous tests
    Used with singleClone(). Removes the copy that function created.
    :param p_clonelist: full filenames including their paths
    :type p_clonelist: list<string>
    """
	*/


}
#endif