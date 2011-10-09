#include <iterator>
#include <algorithm>
#include <string>
#include "Directory.hpp"

namespace fs = boost::filesystem;
namespace doj
{
  int alphanum_comp(const fs::path& l, const fs::path& r)
  {
    return alphanum_impl(l.c_str(), r.c_str());
  }
};

Directory::Directory(const fs::path Path) : path_(Path)
{

    std::for_each(fs::directory_iterator(Path), fs::directory_iterator(), [&files_](fs::path i)
    {
        if (fs::is_regular_file(i) && i.extension().string() == ".mp3")
        {
            files_.insert(i);
        }
    });
}

Directory::~Directory()
{
}



