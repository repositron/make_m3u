#ifndef __MAKEM3U_DIRECTORY__
#define __MAKEM3U_DIRECTORY__

#include "alphanum.hpp"
#include <boost/filesystem.hpp>
#include <string>
#include <vector>
#include <set>

namespace fs = boost::filesystem;


class Directory
{


public:
    Directory(const fs::path Path);
    virtual ~Directory();
private:
    struct NaturalSortOrder
    {
        bool operator()(fs::path& Lhs, fs::path& Rhs)
        {
            return true;
        }
    } naturalSortOrder_;
    friend class M3uCreate;
    fs::path path_;
    //std::vector<fs::path> files_;
    std::set<fs::path, doj::alphanum_less<fs::path> > files_;
};

#endif
