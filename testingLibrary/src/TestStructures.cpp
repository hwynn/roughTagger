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
	std::string TestData::getData(std::string p_metatype) { return ""; };
	void TestData::setData(std::string p_metatype, std::string p_data) {};
}