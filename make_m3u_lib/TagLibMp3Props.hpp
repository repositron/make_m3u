/*
 * TagLibMp3Props.h
 *
 *  Created on: 19 Oct 2014
 *      Author: ljw
 */

#ifndef TAGLIBMP3PROPS_H_
#define TAGLIBMP3PROPS_H_

#include <boost/filesystem.hpp>
#include "Mp3TagInterface.hpp"

class TagLibMp3Props : public Mp3TagInterface
{
public:
	TagLibMp3Props(const boost::filesystem::path Path);
	virtual ~TagLibMp3Props();
	virtual std::string GetTitle() const override;
	virtual int GetLength() const override;
private:
	std::string title_;
	std::string filename_;
	int length_;
};

#endif /* TAGLIBMP3PROPS_H_ */
