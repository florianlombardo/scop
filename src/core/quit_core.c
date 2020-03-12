/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:54:42 by flombard          #+#    #+#             */
/*   Updated: 2020/03/12 15:55:57 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include "core.h"

void	quit_core(t_core **core)
{
	if (*core)
	{
		if (glIsProgram((*core)->program))
			glDeleteProgram((*core)->program);
		if (glIsBuffer((*core)->vbo) == GL_TRUE)
			glDeleteBuffers(1, &((*core)->vbo));
		/*if (glIsBuffer((*core)->ebo) == GL_TRUE)
			glDeleteBuffers(1, &((*core)->ebo));*/
		if (glIsVertexArray((*core)->vao))
			glDeleteVertexArrays(1, &((*core)->vao));
		free(*core);
	}
}
