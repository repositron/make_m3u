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

M3uCreate::M3uCreate(const boost::filesystem::path Path, const SortedDirectory& TheDirectory, std::ostream& OutStream, Mp3TagFactory& Mp3TagFact)
{
    if (!fs::is_directory(Path))
    {
    	throw std::runtime_error(Path.string() + " isn't a path");
    }

    if (!OutStream.good())
        throw std::runtime_error("Can't open output stream");

    OutStream << "#EXTM3U\n";

    std::for_each(TheDirectory.cbegin(), TheDirectory.cend(), [&OutStream, &Mp3TagFact](const fs::path i) {
    	std::unique_ptr<Mp3TagInterface> mp3Tag = Mp3TagFact.CreateMp3Tag(i);
    	OutStream << "#EXTINF:" << mp3Tag->GetLength() << "," << mp3Tag->GetTitle() << '\n';
    	OutStream << i.filename().string() << '\n';
    });
    OutStream << std::endl;
    //std::cout << plsFileName << '\n';
}


M3uCreate::~M3uCreate()
{
}



