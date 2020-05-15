#ifndef TESTSTRUCTURES_H
#define TESTSTRUCTURES_H
#include <ctime>
#include <string>
#include <vector>
#include <iostream>
namespace testingmanager{
	//TODO: if you want extra careful error testing (like checking if strings passed as parameters are valid) use precompiler commands to wrap them.
	
	//TODO: documentation
	//TODO: maybe check naming conventions.
	//http://manual.gromacs.org/documentation/5.1-current/dev-manual/naming.html
	//https://google.github.io/styleguide/cppguide.html
	//This class holds all the same kind of data we can store in a file's metadata.
	//Note: This class has a value for each metadata type.
	//	However, actual files with metadata won't always have values for each metadata type.
	//	This class has a bool value for each metadata type. If it's false, that means we pretend that the TestData has no value for that metadatatype.
	class TestData{


	public:

		//TODO: Make a constructor that will allow a TestData object to be defined immediately. That way we can make const instances of TestData.
		TestData();

		bool containsTitle();
		//return: title if it exists. Else, ""
		std::string getTitle();
		void setTitle(std::string p_x);

		bool containsArtists();
		//return: list of artists if it exists. Else, {}
		std::vector<std::string> getArtists();
		void setArtists(std::vector<std::string> p_x);

		bool containsTags();
		//return: list of tags if it exists. Else, {}
		std::vector<std::string> getTags();
		void setTags(std::vector<std::string> p_x);

		bool containsDescr();
		//return: description if it exists. Else, ""
		std::string getDescr();
		void setDescr(std::string p_x);

		bool containsRating();
		//return: rating if it exists. Else, -1
		int getRating();
		void setRating(int p_x);

		bool containsSource();
		//return: source url if it exists. Else, ""
		std::string getSource();
		void setSource(std::string p_x);

		bool containsOrgDate();
		//return: original data if it exists. Else, datetime.datetime(1,1,1)
		time_t  getOrgDate();
		void setOrgDate(time_t p_x);

		bool containsSeriesName();
		//return: series name if it exists. Else, ""
		std::string getSeriesName();
		void setSeriesName(std::string p_x);

		bool containsSeriesInstallment();
		//return: series installment if it exists. Else, -1
		int getSeriesInstallment();
		void setSeriesInstallment(int p_x);

		bool containsMetadataDate();
		//return: original data if it exists. Else, datetime.datetime(1,1,1)
		//please don't use this as a magic number. It's just to keep consistent type
		time_t getMetadataDate();
		void setMetadataDate(time_t p_x);

		bool containsTaggerMark();
		//return: TaggerMark if it exists. Else, ""
		std::string getTaggerMark();
		void setTaggerMark(std::string p_x);

		bool containsVersionNum();
		//return: VersionNum if it exists. Else, "-1". Should be formatted like a double.
		//example: if this returns "1.02", it has version 1.02
		std::string getVersionNum();
		void setVersionNum(std::string p_x);

		bool containsData(std::string p_metatype);

		//Note: does not check if TestData has a non-default value. 
		//	This function is meant to mirror the functionality of our metadataL0 library. 
		//		All those get functions return a value no matter what (for consistent behaviour)
		//		If no value for a metadatatype exists in the file's metadata, the get functions return a default value.
		//	Those default values of metadataL0's get functions are the actual default values of TestData's attributes.
		//	So keep this in mind when designing tests. The default values of TestData's attributes won't actually exist inside a real file.
		std::string getData(std::string p_metatype);
		//Note: data given as p_data will be converted to a string. No error testing is done on this. 
		void setData(std::string p_metatype, std::string p_data);

	private:

		bool m_hasTitle;
		std::string m_Title;
		bool m_hasArtists;
		std::vector<std::string> m_Artists;
		bool m_hasTags;
		std::vector<std::string> m_Tags;
		bool m_hasDescr;
		std::string m_Descr;
		bool m_hasRating;
		int m_Rating;
		bool m_hasSource;
		std::string m_Source;
		bool m_hasOrgDate;
		//https://en.cppreference.com/w/c/chrono/time_t
		//https://en.cppreference.com/w/cpp/chrono/c/time
		time_t m_OrgDate;//seconds since the epoch
		bool m_hasSeriesName;
		std::string m_SeriesName;
		bool m_hasSeriesInstallment;
		int m_SeriesInstallment;
		bool m_hasMetadataDate;
		time_t m_MetadataDate;
		bool m_hasTaggerMark;
		std::string m_TaggerMark;
		bool m_hasVersionNum;
		std::string m_VersionNum;
	
	};

	//TODO: perhaps make this a const array.
	//Contains each Metadatatype
	extern const std::vector<std::string> g_metatypes;

	//For each metadatatype, prints the name of the metadatatype and whether or this TestData has a non-default value for it.
	//Used for Debugging. Lets us see what metadatatypes a TestData has values for.
	void printExistence(TestData* p_data);

	//For each metadatatype, if this TestData has a non-default value for it, prints the metadatatype and the value
	//Used for Debugging. Lets us see what "true" values TestData has. 
	//	If this TestData represents a real file, this prints all the metadata values that file should have (at least all the ones our software deals with).
	void printPresentData(TestData* p_data);

	//This class is meant to hold all the data we need to locate and or download a file used for testing.
	class TestFile {
		/*
		self.filename = p_filename
		//file name is the name of the file and does NOT include the path. But it does include the extension. 
        self.fullname = p_fullname
		//fullname is the full name of the file including the path.
        self.googleId = p_googleId
		*/

	public:
		TestFile(std::string p_filename,std::string p_fullname,std::string p_googleId);

		//the name of the file along with the file extension. Does NOT include the path.
		std::string m_filename;

		//the name of the file along with the file extension and directory path.
		std::string m_fullname;
	
		//google file id. Used in the google drive url of the file.
		std::string m_googleId;
	private:
	};
}

#endif