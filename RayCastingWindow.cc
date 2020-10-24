/*
 * RayCastingWindow.cc
 *
 *  Created on: 24 окт. 2020 г.
 *      Author: unyuu
 */

#include "RayCastingWindow.h"

RayCastingWindow::RayCastingWindow(int width, int height)
: Window(width, height)
{
	_map = std::make_shared<Map>("map01.txt");
	_player = std::make_shared<Player>(_map);
}

void RayCastingWindow::render()
{
	SDL_Rect r_sky { 0, 0, width(), height() / 2 };
	SDL_Rect r_floor { 0, height() / 2, width(), height() / 2 };
	SDL_SetRenderDrawColor(_renderer.get(), 64, 128, 192, 255);
	SDL_RenderFillRect(_renderer.get(), &r_sky);
	SDL_SetRenderDrawColor(_renderer.get(), 0, 128, 0, 255);
	SDL_RenderFillRect(_renderer.get(), &r_floor);

	SDL_SetRenderDrawBlendMode(_renderer.get(), SDL_BLENDMODE_BLEND);

	// Рисование стен (с использованием алгоритма бросания лучей)

	for (int col = 0; col < width(); ++col) {

		// Здесь будет алгоритм



		draw_col(col, 300); // тут надо будет поменять 300 на h
	}

	// Рисование карты

	SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 64);
	for (int y = 0; y < _map->height(); ++y)
		for (int x = 0; x < _map->width(); ++x) {
			SDL_Rect r { x * 100, y * 100, 100, 100 };
			if (_map->wall(x, y))
				SDL_RenderFillRect(_renderer.get(), &r);
		}

	SDL_Rect r_player {
		int(_player->x() * 100)-10,
		int(_player->y() * 100)-10,
		20, 20
	};
	SDL_Rect r_player_eye {
		int(_player->x() * 100 + 20*cos(_player->dir()))-5,
		int(_player->y() * 100 + 20*sin(_player->dir()))-5,
		10, 10
	};

	SDL_SetRenderDrawColor(_renderer.get(), 255, 64, 64, 255);
	SDL_RenderFillRect(_renderer.get(), &r_player);
	SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 0, 255);
	SDL_RenderFillRect(_renderer.get(), &r_player_eye);
}

void RayCastingWindow::draw_col(int col, int h)
{
	SDL_SetRenderDrawColor(_renderer.get(), 64, 64, 64, 255);
	int y1 = height() / 2 - h / 2;
	int y2 = height() / 2 + h / 2;
	SDL_RenderDrawLine(_renderer.get(), col, y1, col, y2);

}

void RayCastingWindow::handle_keys(const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_W]) _player->walk_forward();
	if (keys[SDL_SCANCODE_S]) _player->walk_backward();
	if (keys[SDL_SCANCODE_D]) _player->shift_right();
	if (keys[SDL_SCANCODE_A]) _player->shift_left();
	if (keys[SDL_SCANCODE_E]) _player->turn_right();
	if (keys[SDL_SCANCODE_Q]) _player->turn_left();
}





