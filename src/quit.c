#include "render.h"

void quitRender(render_t* render)
{
	if (render->context)
		SDL_GL_DeleteContext(render->context);
	if (render->win)
		SDL_DestroyWindow(render->win);
	SDL_Quit();
}
