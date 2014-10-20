/*
 * Mp3TagFactory.h
 *
 *  Created on: 19 Oct 2014
 *      Author: ljw
 */

#ifndef MP3TAGFACTORY_H_
#define MP3TAGFACTORY_H_

#include <type_traits>
#include <memory>
#include <functional>
#include <boost/filesystem.hpp>

#include "TagLibMp3Props.hpp"
#include "Mp3TagInterface.hpp"

class Mp3TagFactory {
public:
	Mp3TagFactory()
	{
		createFn_ = std::bind(&Mp3TagFactory::CreateTagLibProduct, this, std::placeholders::_1);
	}
	virtual ~Mp3TagFactory()
	{
	}
	void SetProduct(std::function<std::unique_ptr<Mp3TagInterface> (const boost::filesystem::path Path)> CreateFn)
	{
		createFn_ = CreateFn;
	}
	std::unique_ptr<Mp3TagInterface> CreateMp3Tag(const boost::filesystem::path Path)
	{
		return createFn_(Path);
	}

	// use TagLib
	std::unique_ptr<Mp3TagInterface> CreateTagLibProduct(const boost::filesystem::path Path)
	{
		std::unique_ptr<Mp3TagInterface> mp3tag(new TagLibMp3Props(Path));
		return mp3tag;
	}

private:
	std::function<std::unique_ptr<Mp3TagInterface> (const boost::filesystem::path Path)> createFn_; // current product factory creates
};

#endif /* MP3TAGFACTORY_H_ */
