#include <stdio.h>
#include <string.h>
#include "render.h"

int initRender(render_t* render)
{
	render->win = NULL;
	render->context = NULL;

	if (!(render->win = SDL_CreateWindow("Scop testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL)))
		goto InitRenderQuit;

	if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE) < 0)
		goto InitRenderQuit;
	if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3) < 0)
		goto InitRenderQuit;
	if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2) < 0)
		goto InitRenderQuit;
	if (SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) < 0)
		goto InitRenderQuit;

	if (!(render->context = SDL_GL_CreateContext(render->win)))
		goto InitRenderQuit;

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		goto InitRenderQuit;

	render->vboCount = -1;
	render->positionIndex = -1;

	render->vertShader = -1;
	render->fragShader = -1;

	return 1;

InitRenderQuit:
	quitRender(render);
	return 0;
}

void initSquare(render_t* render)
{
	float square[4][3] = {
		{-0.5, 0.5, 0.5},
		{0.5, 0.5, 0.5},
		{0.5, -0.5, 0.5},
		{-0.5, -0.5, 0.5}
	};

// Crée le tableau avec la posisiton, indique qu'on s'en sert de vbo actif,
//et remplir le vbo avec les données du square
	render->vboCount = 1;
	glGenBuffers(render->vboCount, render->vbo); // Le deuxième paramètre demande une adresse valide d'un int, une adresse nulle crashera
	glBindBuffer(GL_ARRAY_BUFFER, render->vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, (4 * 3) * sizeof(float), square, GL_STATIC_DRAW);

// Crée le tableau qui contient tous les attributs d'un objet (position, couleurs, ...) et
// indique qu'on s'en sert de vao actif
	glGenVertexArrays(1, render->vao);
	glBindVertexArray(render->vao[0]);

// Remplit la vao avec le vbo de positions. L'index ici n'est pas très utile,
// mais si on rajoute les couleurs par exemple à ce vao, l'index indiquera
// dans quel ordre les attributs sont stockés
	render->positionIndex = 0;
	glVertexAttribPointer(render->positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

// Active l'attribut à l'index fourni. Par défaut tous les attributs sont désactivés
	glEnableVertexAttribArray(render->positionIndex);
}

int initShaders(render_t* render)
{
	FILE* file = NULL;
	char* line = NULL;
	char* shader = NULL;

	if (!(file = fopen("shader/basic.vert", "r")))
		goto InitShadersQuit;
	if (!(line = malloc(sizeof(char) * 255)))
		goto InitShadersQuit;
	memset(line, 0, 255);
	if (!(shader = malloc(1)))
		goto InitShadersQuit;
	memset(shader, 0, 1);

	while (fgets(line, 255, file))
	{
		int len = strlen(shader) + strlen(line) + 1;
		if (!(shader = realloc(shader, len)))
			goto InitShadersQuit;
		if (!snprintf(shader, len, "%s%s", shader, line))
			goto InitShadersQuit;
	}

	fclose(file);
	file = NULL;
	free(line);
	line = NULL;

	render->vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(render->vertShader, 1, shader, NULL);
	glCompileShader(render->vertShader);

	free(shader);
	shader = NULL;

	// Repeat for frag shader

InitShadersQuit:
	if (shader)
		free(shader);
	if (line)
		free(line);
	if (file)
		fclose(file);
}
