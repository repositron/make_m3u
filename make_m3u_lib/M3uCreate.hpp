/*
 * M3uCreate.hpp
 *
 *  Created on: 4/10/2011
 *      Author: ljw
 */

#ifndef M3UCREATE_HPP_
#define M3UCREATE_HPP_
#include <boost/filesystem.hpp>
#include "Mp3TagFactory.hpp"
#include "Directory.hpp"

class M3uCreate
{
public:
    M3uCreate(const boost::filesystem::path Path, const Directory& TheDirectory, Mp3TagFactory& Mp3TagFact);
    virtual ~M3uCreate();
private:
    std::string GeneratePlayListName(const boost::filesystem::path Path);
};

#endif /* M3UCREATE_HPP_ */
