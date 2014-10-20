/*
 * Mp3TagInterface.hpp
 *
 *  Created on: 19 Oct 2014
 *      Author: ljw
 */

#ifndef MP3TAGINTERFACE_HPP_
#define MP3TAGINTERFACE_HPP_

#include <boost/filesystem.hpp>

class Mp3TagInterface
{
public:

	virtual ~Mp3TagInterface() { }
	virtual std::string GetTitle() const = 0;
	virtual int GetLength() const = 0;
};


#endif /* MP3TAGINTERFACE_HPP_ */
