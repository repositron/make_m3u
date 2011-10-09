#include "Directory.hpp"
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <exception>
#include <boost/algorithm/string/erase.hpp>

#include "M3uCreate.hpp"


namespace fs = boost::filesystem;
std::string M3uCreate::PlayListName(const boost::filesystem::path Path)
{
    const std::string suffix = ".m3u";
    std::string filename = Path.filename().string();
    std::string playListFileName = Path.string() + '/' + Path.filename().string() + suffix;
    return playListFileName;
}

M3uCreate::M3uCreate(const boost::filesystem::path Path, const Directory& TheDirectory)
{
    BOOST_ASSERT(fs::is_directory(Path));

    std::string plsFileName = PlayListName(Path);
    std::ofstream file(plsFileName);
    if (!file.good())
        throw std::runtime_error("Can't open" + plsFileName);

    file << "#EXTM3U\n";
    std::for_each(TheDirectory.files_.begin(), TheDirectory.files_.end(), [&file](const fs::path i) {

        TagLib::FileRef f(i.c_str());
        int length = 0;
        std::string title;
        if(!f.isNull() && f.tag())
        {
            TagLib::Tag *tag = f.tag();
            title = tag->title().to8Bit();
            std::cout << "title   - \"" << title << "\"" << std::endl;

            if(f.audioProperties())
            {
                TagLib::AudioProperties* properties = f.audioProperties();
                length = properties->length();
            }
        }
        else
        {
            std::cerr << "taglib could not open file: " << i.filename() << '\n';
            title = i.filename().string();
        }
        file << "#EXTINF:" << length << "," << title << '\n';
        file << i.filename().string() << '\n';
    });
    file << std::endl;
    std::cout << plsFileName << '\n';
}

M3uCreate::~M3uCreate()
{
    // TODO Auto-generated destructor stub
}

void M3uCreate::Process()
{
}



