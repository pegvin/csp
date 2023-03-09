#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
#include "log/log.h"
#include "renderer.h"

static SDL_Renderer* renderer = NULL;

RTexture::RTexture(uint16_t width, uint16_t height) {
	this->w = width;
	this->h = height;
	this->tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, this->w, this->h);
}

RTexture::~RTexture() {
	SDL_DestroyTexture(this->tex);
}

void RTexture::Update(PixelRGBA* pixels, const SDL_Rect* UpdatedPortion) {
	SDL_UpdateTexture(this->tex, UpdatedPortion, pixels, this->w * 4);
}

bool Renderer_Init(SDL_Window* window) {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (renderer == NULL) {
		log_error("Failed to create SDL_Renderer, SDL_CreateRenderer() returned NULL!");
		return false;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer_Init(renderer);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	return true;
}

void Renderer_Quit(void) {
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
}

void Renderer_NewFrame(void) {
	SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
	SDL_RenderClear(renderer);

	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
}

void Renderer_Render(void) {
	ImGui::Render();
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(renderer); // Swap Front & Back Buffers
}

