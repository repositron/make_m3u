/*
 * main.cpp
 *
 *  Created on: 19 Oct 2014
 *      Author: ljw
 */
#include <iostream>

#include "make_m3u.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Not enough arguments\n";
		return 1;
	}
	else
	{
		CreatePlaylists(std::string(argv[1]));
		return 0;
	}
}



