#include <boost/test/unit_test.hpp>
#include <ostream>
//#include <sstream>
#include <fstream>
#include <iostream>
#include <functional>
#include "SortedDirectory.hpp"
#include "M3uCreate.hpp"

class MockTag : public Mp3TagInterface
{
public:

	MockTag(const boost::filesystem::path Path) : path_(Path.filename().string())
	{
	}
	virtual ~MockTag()
	{
	}
	virtual std::string GetTitle() const override
	{
		return std::string("title_") + path_;
	}
	virtual int GetLength() const override
	{
		return GetLengthFn();
	}
	std::string title_;
	std::string path_;

	static std::function<int (void)> GetLengthFn;
};

std::function<int (void)> MockTag::GetLengthFn = [](){return 1;};  // set default

std::unique_ptr<Mp3TagInterface> CreateTestTagLib(const boost::filesystem::path Path)
{
	std::unique_ptr<Mp3TagInterface> mp3tag(new MockTag(Path));
	return mp3tag;
}

BOOST_AUTO_TEST_SUITE(M3uCreateTest)

BOOST_AUTO_TEST_CASE( test_case1 )
{
	std::string testDir("test/testfolder");
	Mp3TagFactory mp3TagFactory;
	mp3TagFactory.SetProduct(CreateTestTagLib);

	std::stringstream ss;
	SortedDirectory directory(testDir);

	boost::filesystem::path path(testDir);
	int i = 1;
	MockTag::GetLengthFn = [&i]() { return i++; };
	M3uCreate m3uCreate(path, directory, ss, mp3TagFactory);

	std::string line;
	std::getline(ss, line);
	BOOST_REQUIRE_EQUAL(line, "#EXTM3U");

	std::getline(ss, line);
	BOOST_REQUIRE_EQUAL(line, "#EXTINF:1,title_1.mp3");
	std::getline(ss, line);
	BOOST_REQUIRE_EQUAL(line, "1.mp3");

	std::getline(ss, line);
	BOOST_REQUIRE_EQUAL(line, "#EXTINF:2,title_aa.mp3");
	std::getline(ss, line);
	BOOST_REQUIRE_EQUAL(line, "aa.mp3");


	std::getline(ss, line);
	BOOST_REQUIRE_EQUAL(line, "#EXTINF:3,title_aaa.mp3");
	std::getline(ss, line);
	BOOST_REQUIRE_EQUAL(line, "aaa.mp3");

}

BOOST_AUTO_TEST_SUITE_END()
