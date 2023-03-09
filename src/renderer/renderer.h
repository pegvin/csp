#ifndef __APP_RENDERER_H_INCLUDED
#define __APP_RENDERER_H_INCLUDED 1
#pragma once

#include <SDL2/SDL.h>
#include "pixel/pixel.h"

struct RTexture {
	uint16_t w, h;

	RTexture(uint16_t w, uint16_t h);
	~RTexture();
	void Update(PixelRGBA* pixels, const SDL_Rect* UpdatedPortion = NULL);

private:
	SDL_Texture* tex;
};

bool Renderer_Init(SDL_Window* window);
void Renderer_Quit(void);
void Renderer_NewFrame(void);
void Renderer_Render(void);

#endif

