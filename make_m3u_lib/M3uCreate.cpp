#include <fstream>
#include <string>
#include <exception>
#include "Mp3TagInterface.hpp"
#include "M3uCreate.hpp"

namespace fs = boost::filesystem;

std::string M3uCreate::GeneratePlayListName(const boost::filesystem::path Path)
{
    const std::string suffix = ".m3u";
    std::string filename = Path.filename().string();
    std::string playListFileName = Path.string() + '/' + Path.filename().string() + suffix;
    return playListFileName;
}

M3uCreate::M3uCreate(const boost::filesystem::path Path, const Directory& TheDirectory, Mp3TagFactory& Mp3TagFact)
{
    if (!fs::is_directory(Path))
    {
    	throw std::runtime_error(Path.string() + " isn't a path");
    }

    std::string plsFileName = GeneratePlayListName(Path);
    std::ofstream file(plsFileName);
    if (!file.good())
        throw std::runtime_error("Can't open" + plsFileName);

    file << "#EXTM3U\n";
    std::for_each(TheDirectory.files_.begin(), TheDirectory.files_.end(), [&file, &Mp3TagFact](const fs::path i) {
    	std::unique_ptr<Mp3TagInterface> mp3Tag = Mp3TagFact.CreateMp3Tag(i);
        file << "#EXTINF:" << mp3Tag->GetLength() << "," << mp3Tag->GetTitle() << '\n';
        file << i.filename().string() << '\n';
    });
    file << std::endl;
    //std::cout << plsFileName << '\n';
}

void M3uCreate::WritePlayListEntry(const boost::filesystem::path Mp3File, std::ofstream& File)
{

}

M3uCreate::~M3uCreate()
{
}



