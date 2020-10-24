/*
 * main.cc
 *
 *  Created on: 24 окт. 2020 г.
 *      Author: unyuu
 */

#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "RayCastingWindow.h"

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try {
		RayCastingWindow w;

		w.main_loop();

	} catch (const std::exception &e) {
		std::cerr << "Во время выполнения программы произошла ошибка: "
				<< std::endl << e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cerr << "Во время выполнения программы произошла "
				"неизвестная ошибка!" << std::endl;
		return 1;
	}


	return 0;
}

