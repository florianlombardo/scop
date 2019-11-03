#include <stdlib.h>
#include <stdio.h>
#include "render.h"

int main(int argc, char* argv[])
{
	render_t rend;
	if (!initRender(&rend))
		return EXIT_FAILURE;

	initSquare(&rend);

	int quit = 0;
	if (!initShaders(&rend))
		goto Quit;

	SDL_Event event;
	while (!quit)
	{
		if (!render(&rend))
			goto Quit;

		SDL_WaitEvent(&event);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			quit = 1;
	}

Quit:
	quitRender(&rend);
	if (quit == 1)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}
