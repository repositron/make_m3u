#ifndef __MAKEM3U_DIRECTORY__
#define __MAKEM3U_DIRECTORY__

#include "alphanum.hpp"
#include <boost/filesystem.hpp>
#include <set>

class Directory
{
public:
    Directory(const boost::filesystem::path Path);
    virtual ~Directory();
private:
    friend class M3uCreate;
    boost::filesystem::path path_;
    std::set<boost::filesystem::path, doj::alphanum_less<boost::filesystem::path> > files_;
};

#endif
