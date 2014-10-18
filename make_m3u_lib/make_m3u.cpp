#include <boost/filesystem.hpp>
#include <set>
#include <string>
#include <boost/algorithm/string/erase.hpp>

#include "Directory.hpp"
#include "M3uCreate.hpp"

namespace fs = boost::filesystem;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Not enough arguments\n";
    }
    try
    {
        fs::path p(argv[1]);
        if (fs::exists(p))
        {
            if (fs::is_directory(p))
            {
                std::string path = p.string();
                if (path[path.size() - 1] == '/')
                    boost::algorithm::erase_tail(path, 1);
                fs::path rootPath(path);

                std::for_each(fs::directory_iterator(rootPath), fs::directory_iterator(), [](fs::path i)
                {
                    std::cout << i.string() << '\n';
                    if (fs::is_directory(i))
                    {
                        Directory directory(i);
                        M3uCreate m3uCreate(i, directory);
                    }
                });
            }
            else
            {
                std::cout << "Enter a directory\n";
            }
        }
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
