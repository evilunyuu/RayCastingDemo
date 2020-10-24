/*
 * Window.cc
 *
 *  Created on: 24 окт. 2020 г.
 *      Author: unyuu
 */

#include "Window.h"

#include <stdexcept>
#include <string>

Window::Window(int width, int height)
: _width(width), _height(height)
{
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"SDL Window",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width, height,
					SDL_WINDOW_SHOWN),
			SDL_DestroyWindow);
	if (_window == nullptr)
		throw std::runtime_error(
				std::string("Не могу создать окно: ") +
				std::string(SDL_GetError()));

	_renderer = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(
					_window.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (_renderer == nullptr)
		throw std::runtime_error(
						std::string("Не могу создать рендерер: ") +
						std::string(SDL_GetError()));
}

void Window::main_loop()
{

	SDL_Event event;
	auto keys = SDL_GetKeyboardState(nullptr);
	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return;
			handle_event(event);
		}
		handle_keys(keys);

		do_logic();

		render();
		SDL_RenderPresent(_renderer.get());
	}
}




