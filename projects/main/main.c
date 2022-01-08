#include <SDL.h>

int main(int argc, char** argsv)
{

	SDL_Window* window;
	SDL_Renderer* renderer;

	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow(
		"SDL2 TEST",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_FULLSCREEN
	);

	if (window == NULL) {
		SDL_Log("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (window == NULL) {
		SDL_Log("Could not create renderer: %s\n", SDL_GetError());
		return 1;
	}
	SDL_RenderSetLogicalSize(renderer, 640, 480); //it is necessary
	int quit = 1;
	while (quit) {
		SDL_Event evt;
		while (SDL_PollEvent(&evt)) {
			switch (evt.type)
			{
			case SDL_KEYDOWN:
			{
				const int sym = evt.key.keysym.sym;
				if (sym == SDLK_SPACE) {
					SDL_Log("Key : Space!");
				}
				if (sym == SDLK_ESCAPE || sym == SDLK_AC_BACK) {
					quit = 0;
					SDL_Log("Key : Escape!");
				}
			}
			break;
			case SDL_QUIT:
			{
				quit = 0;
				SDL_Log("Ctlr+C : Quit!");
			}
			break;

			}

		}


		SDL_SetRenderDrawColor(renderer, 0x70, 0x70, 0x70, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_Rect  rect = { 10,10,50,50 };
		SDL_RenderFillRect(renderer, &rect);
		SDL_Rect  crect = { 100, 100, 200, 200 };
		SDL_RenderSetClipRect(renderer, &crect);//it is necessary
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_Rect  drawrect = { 100, 100, 50, 50 };
		SDL_RenderDrawRect(renderer, &drawrect);//it is necessary
		SDL_Rect  fillrect = { 100, 100, 0, 0 };//it is necessary  w,h = 0
		SDL_RenderFillRect(renderer, &fillrect);//it is necessary
		SDL_RenderSetClipRect(renderer, NULL);
		SDL_RenderPresent(renderer);
	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}