#ifndef __MAKEM3U_DIRECTORY__
#define __MAKEM3U_DIRECTORY__

#include "alphanum.hpp"
#include <boost/filesystem.hpp>
#include <set>
#include <functional>

// list of ordered mp3 files in folder
class SortedDirectory
{
public:
    SortedDirectory(const boost::filesystem::path Path);
    virtual ~SortedDirectory();
    typedef std::set<boost::filesystem::path, doj::alphanum_less<boost::filesystem::path> >::const_iterator const_iterator;
    // expose iterator for files_
    const_iterator cbegin() const;
    const_iterator cend() const;
private:
    boost::filesystem::path path_;
    std::set<boost::filesystem::path, doj::alphanum_less<boost::filesystem::path> > files_;
};

#endif
