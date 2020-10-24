/*
 * Map.cc
 *
 *  Created on: 24 окт. 2020 г.
 *      Author: unyuu
 */

#include <fstream>
#include <sstream>

#include "Map.h"

Map::Map(const char *filename)
{
	std::ifstream file(filename);
	if (file.bad())
		throw std::runtime_error(
				std::string("Не могу загрузить карту ") +
				std::string(filename));

	std::string line;
	std::getline(file, line);
	std::stringstream map_info(line);
	map_info >> _width >> _height >>
		_start_x >> _start_y >> _start_dir;
	while (not file.eof()) {
		std::getline(file, line);
		if (file.fail()) break;
		_data.push_back(line);
	}
}


