#include <boost/filesystem.hpp>
#include <set>
#include <string>
#include <boost/algorithm/string/erase.hpp>
#include <fstream>
#include <iostream>
#include "SortedDirectory.hpp"
#include "M3uCreate.hpp"

namespace fs = boost::filesystem;

void CreatePlaylists(const std::string Folder)
{
    try
    {
        fs::path p(Folder);
        if (!fs::exists(p) || !fs::is_directory(p))
        {
        	std::cerr << p.string() << " isn't a directory\n";
        	return;
        }

		std::string path = p.string();
		if (path[path.size() - 1] == '/')
			boost::algorithm::erase_tail(path, 1);
		fs::path rootPath(path);
		Mp3TagFactory mp3TagFactory;
		std::for_each(fs::directory_iterator(rootPath), fs::directory_iterator(), [&mp3TagFactory](fs::path i)
		{
			// generate playlist for each directory.
			if (fs::is_directory(i))
			{
				std::ofstream playListFile(M3uCreate::GeneratePlayListName(i));
				SortedDirectory directory(i);
				M3uCreate m3uCreate(i, directory, playListFile, mp3TagFactory);
			}
		});
    }
    catch (const fs::filesystem_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "unknown exception occurred\n";
    }
}
