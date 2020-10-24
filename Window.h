/*
 * Window.h
 *
 *  Created on: 24 окт. 2020 г.
 *      Author: unyuu
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/SDL.h>

class Window
{
public:
	static constexpr int DEFAULT_WIDTH = 1920;
	static constexpr int DEFAULT_HEIGHT = 1080;
protected:
	std::shared_ptr<SDL_Window> _window;
	std::shared_ptr<SDL_Renderer> _renderer;

	int _width, _height;
public:
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~Window() = default;
	Window(const Window &other) = delete;
	Window(Window &&other) = default;

	int height() const { return _height; }
	int width() const { return _width; }

	void main_loop();

	virtual void setup() {}
	virtual void do_logic() {}
	virtual void render() {}
	virtual void handle_event(SDL_Event &) {}
	virtual void handle_keys(const Uint8 *) {}
};

#endif /* WINDOW_H_ */
