/*
 * SortDirectoryTest.cpp
 *
 *  Created on: 20 Oct 2014
 *      Author: ljw
 */
#include <boost/test/unit_test.hpp>
#include "SortedDirectory.hpp"

BOOST_AUTO_TEST_SUITE(SortDirectoryTest)

BOOST_AUTO_TEST_CASE( emptycase )
{
	std::string testDir("test/testfolder2");
	SortedDirectory sortedDirectory(testDir);
	BOOST_REQUIRE(sortedDirectory.cbegin() == sortedDirectory.cend());
}

BOOST_AUTO_TEST_CASE( files3 )
{
	std::string testDir("test/testfolder");
	SortedDirectory sortedDirectory(testDir);
	SortedDirectory::const_iterator i = sortedDirectory.cbegin();
	BOOST_REQUIRE(i != sortedDirectory.cend());
	BOOST_REQUIRE_EQUAL(i++->string(), std::string("test/testfolder/1.mp3"));
	BOOST_REQUIRE_EQUAL(i++->string(), std::string("test/testfolder/aa.mp3"));
	BOOST_REQUIRE_EQUAL(i++->string(), std::string("test/testfolder/aaa.mp3"));
	BOOST_REQUIRE(i == sortedDirectory.cend());
}


BOOST_AUTO_TEST_SUITE_END()



