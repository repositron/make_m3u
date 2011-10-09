/*
 * M3uCreate.hpp
 *
 *  Created on: 4/10/2011
 *      Author: ljw
 */

#ifndef M3UCREATE_HPP_
#define M3UCREATE_HPP_
#include <boost/filesystem.hpp>
#include "Directory.hpp"

class M3uCreate
{
public:
    M3uCreate(const boost::filesystem::path Path, const Directory& TheDirectory);
    virtual ~M3uCreate();
private:
    std::string PlayListName(const boost::filesystem::path Path);
};

#endif /* M3UCREATE_HPP_ */
