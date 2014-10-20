#include <iterator>
#include <algorithm>
#include <string>
#include "SortedDirectory.hpp"

namespace fs = boost::filesystem;
namespace doj
{
  int alphanum_comp(const fs::path& l, const fs::path& r)
  {
    return alphanum_impl(l.c_str(), r.c_str());
  }
};

SortedDirectory::SortedDirectory(const fs::path Path)
	: path_(Path)
{
	// get all the mp3 filenames within the specified folder
    std::for_each(fs::directory_iterator(Path), fs::directory_iterator(), [&](fs::path i)
    {
        if (fs::is_regular_file(i) && i.extension().string() == ".mp3")
        {
            files_.insert(i);
        }
    });
}

SortedDirectory::~SortedDirectory()
{
}

SortedDirectory::const_iterator SortedDirectory::cbegin() const
{
	return files_.cbegin();
}

SortedDirectory::const_iterator SortedDirectory::cend() const
{
	return files_.cend();
}


