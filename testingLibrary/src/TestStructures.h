#pragma once
#include <ctime>
#include <string>
#include <vector>
namespace testingmanager{
	//TODO: if you want extra careful error testing (like checking if strings passed as parameters are valid) use precompiler commands to wrap them.
	class TestData{
	//TODO: documentation
	//TODO: maybe check naming conventions.
	//http://manual.gromacs.org/documentation/5.1-current/dev-manual/naming.html
	//https://google.github.io/styleguide/cppguide.html

	public:
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
		std::string getData(std::string p_metatype);
		//Note: data given as p_data will be converted to a string. No error testing is done on this. 
		void setData(std::string p_metatype, std::string p_data);
	

	private:
		bool m_hasTitle = false;
		std::string m_Title = "";
		bool m_hasArtists = false;
		std::vector<std::string> m_Artists = {};
		bool m_hasTags = false;
		std::vector<std::string> m_Tags = {};
		bool m_hasDescr = false;
		std::string m_Descr = "";
		bool m_hasRating = false;
		int m_Rating = -1;
		bool m_hasSource = false;
		std::string m_Source = "";
		bool m_hasOrgDate = false;
		//https://en.cppreference.com/w/c/chrono/time_t
		//https://en.cppreference.com/w/cpp/chrono/c/time
		time_t m_OrgDate = 0;//seconds since the epoch
		bool m_hasSeriesName = false;
		std::string m_SeriesName = "";
		bool m_hasSeriesInstallment = false;
		int m_SeriesInstallment = -1;
		bool m_hasMetadataDate = false;
		time_t m_MetadataDate = 0;
		bool m_hasTaggerMark = false;
		std::string m_TaggerMark = "";
		bool m_hasVersionNum = false;
		std::string m_VersionNum = "-1";

	};

struct TestFile{};}