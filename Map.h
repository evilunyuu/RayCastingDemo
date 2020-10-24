/*
 * Map.h
 *
 *  Created on: 24 окт. 2020 г.
 *      Author: unyuu
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <string>
#include <cmath>

class Map
{
protected:
	int _width { 0 }, _height { 0 };
	double _start_x { 0. }, _start_y { 0. }, _start_dir { 0. };
	std::vector<std::string> _data;
public:
	Map(const char * filename);

	int height() const { return _height; }
	double start_dir() const { return _start_dir; }
	double start_x() const { return _start_x; }
	double start_y() const { return _start_y; }
	int width() const { return _width; }

	bool wall(int x, int y)
	{
		if (x < 0 or x >= _width or y < 0 or y >= _height)
			return true;
		return _data[y][x] == '#';
	}

	bool wall(double x, double y)
	{
		return wall(int(floor(x)), int(floor(y)));
	}
};

#endif /* MAP_H_ */
