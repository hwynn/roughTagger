#include "TestStructures.h"
namespace testingmanager {
	//TODO: finish these functions
	//TODO: documentation. You can probably resuse most of python's documentation. Or make a template in excel to remake it.
	//Note: without any default values, we don't need a class constructor.
	TestData::TestData() {
		m_hasTitle = false;
		m_Title = "";
		m_hasArtists = false;
		m_Artists = {};
		m_hasTags = false;
		m_Tags = {};
		m_hasDescr = false;
		m_Descr = "";
		m_hasRating = false;
		m_Rating = -1;
		m_hasSource = false;
		m_Source = "";
		m_hasOrgDate = false;
		m_OrgDate = 0;//seconds since the epoch
		m_hasSeriesName = false;
		m_SeriesName = "";
		m_hasSeriesInstallment = false;
		m_SeriesInstallment = -1;
		m_hasMetadataDate = false;
		m_MetadataDate = 0;
		m_hasTaggerMark = false;
		m_TaggerMark = "";
		m_hasVersionNum = false;
		m_VersionNum = "-1";
	};

	bool TestData::containsTitle() { return m_hasTitle; };
	//return: title if it exists. Else, ""
	std::string TestData::getTitle() { return m_Title; };
	void TestData::setTitle(std::string p_x) {
		m_Title = p_x;
		m_hasTitle = true;
	};

	bool TestData::containsArtists() { return m_hasArtists; };
	//return: list of artists if it exists. Else, {}
	std::vector<std::string> TestData::getArtists() { return m_Artists; };
	void TestData::setArtists(std::vector<std::string> p_x) {
		m_Artists = p_x;
		m_hasArtists = true;
	};

	bool TestData::containsTags() { return m_hasTags; };
	//return: list of tags if it exists. Else, {}
	std::vector<std::string> TestData::getTags() { return m_Tags; };
	void TestData::setTags(std::vector<std::string> p_x) {
		m_Tags = p_x;
		m_hasTags = true;
	};

	bool TestData::containsDescr() { return m_hasDescr; };
	//return: description if it exists. Else, ""
	std::string TestData::getDescr() { return m_Descr; };
	void TestData::setDescr(std::string p_x) {
		m_Descr = p_x;
		m_hasDescr = true;
	};

	bool TestData::containsRating() { return m_hasRating; };
	//return: rating if it exists. Else, -1
	int TestData::getRating() { return m_Rating; };
	void TestData::setRating(int p_x) {
		m_Rating = p_x;
		m_hasRating = true;
	};

	bool TestData::containsSource() { return m_hasSource; };
	//return: source url if it exists. Else, ""
	std::string TestData::getSource() { return m_Source; };
	void TestData::setSource(std::string p_x) {
		m_Source = p_x;
		m_hasSource = true;
	};

	bool TestData::containsOrgDate() { return m_hasOrgDate; };
	//return: original data if it exists. Else, datetime.datetime(1,1,1)
	time_t  TestData::getOrgDate() { return m_OrgDate; };
	void TestData::setOrgDate(time_t p_x) {
		m_OrgDate = p_x;
		m_hasOrgDate = true;
	};

	bool TestData::containsSeriesName() { return m_hasSeriesName; };
	//return: series name if it exists. Else, ""
	std::string TestData::getSeriesName() { return m_SeriesName; };
	void TestData::setSeriesName(std::string p_x) {
		m_SeriesName = p_x;
		m_hasSeriesName = true;
	};

	bool TestData::containsSeriesInstallment() { return m_hasSeriesInstallment; };
	//return: series installment if it exists. Else, -1
	int TestData::getSeriesInstallment() { return m_SeriesInstallment; };
	void TestData::setSeriesInstallment(int p_x) {
		m_SeriesInstallment = p_x;
		m_hasSeriesInstallment = true;
	};

	bool TestData::containsMetadataDate() { return m_hasMetadataDate; };
	//return: original data if it exists. Else, datetime.datetime(1,1,1)
	//please don't use this as a magic number. It's just to keep consistent type
	time_t TestData::getMetadataDate() { return m_MetadataDate; };
	void TestData::setMetadataDate(time_t p_x) {
		m_MetadataDate = p_x;
		m_hasMetadataDate = true;
	};

	bool TestData::containsTaggerMark() { return m_hasTaggerMark; };
	//return: TaggerMark if it exists. Else, ""
	std::string TestData::getTaggerMark() { return m_TaggerMark; };
	void TestData::setTaggerMark(std::string p_x) {
		m_TaggerMark = p_x;
		m_hasTaggerMark = true;
	};

	bool TestData::containsVersionNum() { return m_hasVersionNum; };
	//return: VersionNum if it exists. Else, "-1"
	//example: if this returns "1.02", it has version 1.02
	std::string TestData::getVersionNum() { return m_VersionNum; };
	void TestData::setVersionNum(std::string p_x) {
		m_VersionNum = p_x;
		m_hasVersionNum = true;
	};


	//Title, Artist, Tags, Description, Rating, Source, Date Created, SeriesName, SeriesInstallment, MetadataDate, TaggerMark, VersionNum
	//TODO: replace this with a map function.
	bool TestData::containsData(std::string p_metatype) {
		if (p_metatype == "Title") { return containsTitle(); }
		else if (p_metatype == "Artist") { return containsArtists(); }
		else if (p_metatype == "Tags") { return containsTags(); }
		else if (p_metatype == "Description") { return containsDescr(); }
		else if (p_metatype == "Rating") { return containsRating(); }
		else if (p_metatype == "Source") { return containsSource(); }
		else if (p_metatype == "Date Created") { return containsOrgDate(); }
		else if (p_metatype == "SeriesName") { return containsSeriesName(); }
		else if (p_metatype == "SeriesInstallment") { return containsSeriesInstallment(); }
		else if (p_metatype == "MetadataDate") { return containsMetadataDate(); }
		else if (p_metatype == "TaggerMark") { return containsTaggerMark(); }
		else if (p_metatype == "VersionNum") { return containsVersionNum(); }
		return false;
	};


	std::string TestData::getData(std::string p_metatype) { 
		if (p_metatype == "Title") { return getTitle(); }
		else if (p_metatype == "Artist") { 
			//TODO: let this handle cases where semicolons are in the strings. set and get functions' output should have a 1-to-1 reversible relationship.
			std::string f_string = "";
			std::vector<std::string> f_temp = getArtists();
			for (int i = 0; i < f_temp.size()-1; i = i + 1) { f_string = f_string + f_temp[i] + ";"; }
			f_string = f_string + f_temp[f_temp.size() - 1];
			return f_string;
		}
		else if (p_metatype == "Tags") { 
			//TODO: let this handle cases where semicolons are in the strings. set and get functions' output should have a 1-to-1 reversible relationship.
			std::string f_string = "";
			std::vector<std::string> f_temp = getTags();
			for (int i = 0; i < f_temp.size() - 1; i = i + 1) { f_string = f_string + f_temp[i] + ";"; }
			f_string = f_string + f_temp[f_temp.size() - 1];
			return f_string;
		}
		else if (p_metatype == "Description") { return getDescr(); }
		else if (p_metatype == "Rating") { return std::to_string(getRating()); }
		else if (p_metatype == "Source") { return getSource(); }
		else if (p_metatype == "Date Created") { return std::to_string(getOrgDate()); }
		else if (p_metatype == "SeriesName") { return getSeriesName(); }
		else if (p_metatype == "SeriesInstallment") { return std::to_string(getSeriesInstallment()); }
		else if (p_metatype == "MetadataDate") { return std::to_string(getMetadataDate()); }
		else if (p_metatype == "TaggerMark") { return getTaggerMark(); }
		else if (p_metatype == "VersionNum") { return getVersionNum(); }
		return "";
	};
	void TestData::setData(std::string p_metatype, std::string p_data) {
		if (p_metatype == "Title") { setTitle(p_data); }
		else if (p_metatype == "Artist") { 
			//TODO: let this handle cases where semicolons are in the strings. set and get functions' output should have a 1-to-1 reversible relationship.
			std::string delimiter = ";";
			std::vector<std::string> f_vec;
			size_t last = 0;
			size_t next = 0;
			while(next = p_data.find(delimiter, last)){
				f_vec.push_back(p_data.substr(last, next - last));
				last = next + 1;
			}
			f_vec.push_back(p_data.substr(last));
			setArtists(f_vec); }
		else if (p_metatype == "Tags") {
			//TODO: let this handle cases where semicolons are in the strings. set and get functions' output should have a 1-to-1 reversible relationship.
			std::string delimiter = ";";
			std::vector<std::string> f_vec;
			size_t last = 0;
			size_t next = 0;
			while (next = p_data.find(delimiter, last)) {
				f_vec.push_back(p_data.substr(last, next - last));
				last = next + 1;
			}
			f_vec.push_back(p_data.substr(last));
			setTags(f_vec); }
		else if (p_metatype == "Description") { setDescr(p_data); }
		else if (p_metatype == "Rating") {
			//TODO: use this if we ever switch to using cstrings. http://www.cplusplus.com/reference/cstdlib/strtol/
			setRating(std::stoi(p_data)); }
		else if (p_metatype == "Source") { setSource(p_data); }
		else if (p_metatype == "Date Created") { 
			//TODO: support milliseconds.
			int f_intTime = std::stoi(p_data);
			//TODO: Portable programs should not use values of this type directly, but always rely on calls to elements of the standard library to translate them to portable types.
			//TODO: find out how pyexiv2 stored time. It should make calls to c++ or c.
			std::time_t f_time = f_intTime;
			setOrgDate(f_time); }
		else if (p_metatype == "SeriesName") { setSeriesName(p_data); }
		else if (p_metatype == "SeriesInstallment") { setSeriesInstallment(std::stoi(p_data)); }
		else if (p_metatype == "MetadataDate") {
			//TODO: support milliseconds.
			int f_intTime = std::stoi(p_data);
			//TODO: Portable programs should not use values of this type directly, but always rely on calls to elements of the standard library to translate them to portable types.
			//TODO: find out how pyexiv2 stored time. It should make calls to c++ or c.
			std::time_t f_time = f_intTime;
			setOrgDate(f_time);
		}
		else if (p_metatype == "TaggerMark") { setTaggerMark(p_data); }
		else if (p_metatype == "VersionNum") { setVersionNum(p_data); }
	};

	
	extern const std::vector<std::string> g_metatypes = { "Title", "Artist", "Tags", "Description", "Rating", "Source", "Date Created", "SeriesName", "SeriesInstallment", "MetadataDate", "TaggerMark", "VersionNum" };
	void printExistence(TestData* p_data)
	{
		for (size_t i = 0; i < g_metatypes.size(); i = i + 1) {
			std::cout << "Existence of " << g_metatypes[i] << ": ";
			std::cout << ((p_data->containsData(g_metatypes[i])) ? "True" : "False") << std::endl;
		}
	}

	void printPresentData(TestData* p_data) {
		for (size_t i = 0; i < g_metatypes.size(); i = i + 1) {
			if (p_data->containsData(g_metatypes[i])) {
				std::cout << g_metatypes[i] << ": " << p_data->getData(g_metatypes[i]) << std::endl;
			}
		}
	}

	TestFile::TestFile(std::string p_filename, std::string p_path, std::string p_googleId) {
		m_filename = p_filename;
		m_path = p_path;
		m_fullname = p_path + p_filename;
		m_googleId = p_googleId;
	};

	bool TestFile::exists() const{
		return testfilehelper::fileExists(m_fullname);
	}

	void TestFile::download() const{
		testfilehelper::downloadFileWithPython(m_googleId, m_path, m_filename);
	}

	std::string TestFile::clone() const{
		std::string cloneName = testfilehelper::singleClone(m_fullname, false);
		return cloneName;
	}

	void TestFile::releaseClone() const{
		std::string ext = testfilehelper::getExtension(m_filename);
		std::string f_name = m_filename.substr(0, m_filename.length() - ext.length());
		const std::string f_newfile = m_path + f_name + "Copy" + ext;
		testfilehelper::deleteFile(f_newfile);
	}

	void TestFile::deleteFile() const{
		testfilehelper::deleteFile(m_fullname);
	}
}