#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO))
		return EXIT_FAILURE;

	SDL_Window* win = NULL;
	SDL_GLContext* context = NULL;
	int quit = 0;
	
	if (!(win = SDL_CreateWindow("Scop testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL)))
		goto Quit;

	if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE) < 0)
		goto Quit;
	if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3) < 0)
		goto Quit;
	if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2) < 0)
		goto Quit;
	if (SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) < 0)
		goto Quit;

	if (!(context = SDL_GL_CreateContext(win)))
		goto Quit;

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		goto Quit;

	SDL_Event event;

	while (!quit)
	{
		SDL_WaitEvent(&event);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			quit = 1;
	}

Quit:
	if (context)
		SDL_GL_DeleteContext(context);
	if (win)
		SDL_DestroyWindow(win);
	SDL_Quit();
	if (quit == 1)
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}
