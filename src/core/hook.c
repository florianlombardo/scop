/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:46:34 by flombard          #+#    #+#             */
/*   Updated: 2020/03/12 16:02:34 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include "mlx.h"
#include "mlx_opengl.h"
#include "keys.h"
#include "matrices.h"
#include "env.h"
#include "display.h"
#include "core.h"

int		close_hook(void *param)
{
	t_env	*e;

	e = param;
	quit_core(&(e->core));
	quit_display(&(e->dis));
	exit(EXIT_SUCCESS);
}

int		loop_hook(void *param)
{
	t_env	*e;
	t_mat4	model;
	t_mat4	view;
	t_mat4	proj;
	unsigned int transLoc;

	e = param;
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	model = rotate_y(identity(), RADIANS(50.0f) * 5.0f * ((float)clock() / CLOCKS_PER_SEC));
	model = rotate_x(model, RADIANS(25.0f) * 5.0f * ((float)clock() / CLOCKS_PER_SEC));
	view = translate(identity(), (t_vec3){0.0f, 0.0f, -3.0f});
	proj = perspective(RADIANS(45.0f), (float)WIDTH/(float)HEIGHT, 0.1f, 100.0f);
	glUseProgram(e->core->program);

	if (!(e->core->transform = mat4_to_floats(model)))
	{
		quit_core(&(e->core));
		quit_display(&(e->dis));
		exit(EXIT_SUCCESS);
	}
	transLoc = glGetUniformLocation(e->core->program, "model");
	glUniformMatrix4fv(transLoc, 1, GL_FALSE, e->core->transform);
	free(e->core->transform);

	if (!(e->core->transform = mat4_to_floats(view)))
	{
		quit_core(&(e->core));
		quit_display(&(e->dis));
		exit(EXIT_SUCCESS);
	}
	transLoc = glGetUniformLocation(e->core->program, "view");
	glUniformMatrix4fv(transLoc, 1, GL_FALSE, e->core->transform);
	free(e->core->transform);

	if (!(e->core->transform = mat4_to_floats(proj)))
	{
		quit_core(&(e->core));
		quit_display(&(e->dis));
		exit(EXIT_SUCCESS);
	}
	transLoc = glGetUniformLocation(e->core->program, "projection");
	glUniformMatrix4fv(transLoc, 1, GL_FALSE, e->core->transform);
	free(e->core->transform);

	glBindVertexArray(e->core->vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	mlx_opengl_swap_buffers(e->dis->win);
	return (0);
}
