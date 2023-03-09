#include <string>
#include <SDL2/SDL.h>

#include "app.h"
#include "log/log.h"
#include "assets/assets.h"
#include "renderer/renderer.h"

static SDL_Window* window = NULL;
static std::string WindowTitle = "";
static int32_t WindowDims[2] = { 700, 500 };
static bool ShouldClose = true;

int main(int argc, char** argv) {
	if (!App_Init()) return 1;

	while(!ShouldClose) {
		App_NewFrame();
		App_ProcessEvents();
		App_EndFrame();
	}

	App_Quit();
	return 0;
}

void App_RequestClose() {
	ShouldClose = true;
}

void App_NewFrame() {
	Renderer_NewFrame();
}

void App_ProcessEvents() {
	Renderer_Render();
}

void App_EndFrame() {
	Renderer_Render();
}

bool App_Init() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) != 0) {
		log_error("failed to initialize SDL2: %s", SDL_GetError());
		return false;
	}

	SDL_version compiled;
	SDL_version linked;
	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);

	log_info("Init csprite " CS_VERSION_STR);
	log_info("Compiled With SDL version %u.%u.%u", compiled.major, compiled.minor, compiled.patch);
	log_info("Linked With SDL version %u.%u.%u", linked.major, linked.minor, linked.patch);

	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	WindowDims[0] = dm.w * 0.7;
	WindowDims[1] = dm.h * 0.8;

	window = SDL_CreateWindow(
		WindowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WindowDims[0], WindowDims[1],
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_MAXIMIZED
	);

	Renderer_Init(window);

	uint8_t* winIcon_Pixels = (uint8_t*)Assets_Get("data/icons/icon-24.png", NULL);
	SDL_Surface* winIcon_Surface = SDL_CreateRGBSurfaceFrom(
		winIcon_Pixels,
		24, 24, 32, 24 * 4,
		0x000000ff,
		0x0000ff00,
		0x00ff0000,
		0xff000000
	);
	if (winIcon_Surface == NULL) {
		log_error("Failed to set window icon: %s", SDL_GetError());
	}
	SDL_SetWindowIcon(window, winIcon_Surface);
	SDL_FreeSurface(winIcon_Surface);

	SDL_ShowWindow(window);

	return true;
}

void App_Quit() {
	Renderer_Quit();
	SDL_DestroyWindow(window);
	SDL_Quit();

	window = NULL;
}

