/*
 * TagLibMp3Props.cpp
 *
 *  Created on: 19 Oct 2014
 *      Author: ljw
 */

#include <taglib/fileref.h>
#include <taglib/tag.h>

#include "TagLibMp3Props.hpp"

TagLibMp3Props::TagLibMp3Props(const boost::filesystem::path Path) : length_(0)
{
	TagLib::FileRef f(Path.c_str());
	if(!f.isNull() && f.tag())
	{
		TagLib::Tag *tag = f.tag();
		title_ = tag->title().to8Bit();

		if(f.audioProperties())
		{
			TagLib::AudioProperties* properties = f.audioProperties();
			length_ = properties->length();
		}
	}
	else
	{
		std::cerr << "taglib could not open file: " << Path.filename() << '\n';
		title_ = Path.filename().string();
	}
}

TagLibMp3Props::~TagLibMp3Props()
{
}

std::string TagLibMp3Props::GetTitle() const
{

	return title_;
}


int TagLibMp3Props::GetLength() const
{
	return length_;
}
