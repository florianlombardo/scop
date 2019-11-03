#ifndef RENDER_H
# define RENDER_H
# pragma once

# include <GL/glew.h>
# include <SDL2/SDL.h>

typedef struct
{
	SDL_Window* win;
	SDL_GLContext* context;

	unsigned int vboCount;
// Un vbo est un tableau qui contient un attribut. Il en
// faudra un pour les positions, un pour les couleurs, etc...
	unsigned int vbo[1];

// Un vao est un tableau qui rassemble plusieurs vbo pour former un object
	unsigned int vao[1];
	unsigned int positionIndex;

//
	unsigned int vertShader;
	unsigned int fragShader;
} render_t;

int		initRender(render_t* render);
void	quitRender(render_t* render);

void	initSquare(render_t* render);

int		initShaders(render_t* render);

int		render(render_t* render);

#endif
