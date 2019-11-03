#include "render.h"

int render(render_t* render)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(render->win);

	return 1;
}
