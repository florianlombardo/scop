/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:33 by flombard          #+#    #+#             */
/*   Updated: 2020/03/12 16:31:20 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include "libft.h"
#include "core.h"

static char	*read_shader(char *filename)
{
	int		fd;
	char	*line;
	char	*ret;
	char	*tmp;

	ret = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (ret)
		{
			if (!(tmp = ft_strjoin(ret, ft_strjoin(line, "\n"))))
			{
				free(ret);
				free(line);
				close(fd);
				return (NULL);
			}
			free(ret);
			ret = tmp;
			free(line);
		}
		else
			ret = ft_strjoin(line, "\n");
	}
	if (close(fd) == -1)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

static int	load_shader(char *filename, unsigned int *id, char type)
{
	char	*str;
	int		success;

	if (!(str = read_shader(filename)))
		return (0);
	if (type == 'v')
		*id = glCreateShader(GL_VERTEX_SHADER);
	else if (type == 'f')
		*id = glCreateShader(GL_FRAGMENT_SHADER);
	else
	{
		free(str);
		return (0);
	}
	glShaderSource(*id, 1, (const GLchar**)&str, NULL);
	glCompileShader(*id);
	free(str);
	glGetShaderiv(*id, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE)
	{
		glDeleteShader(*id);
		return (0);
	}
	return (1);
}

int			create_program(unsigned int *prog, unsigned int *vert, unsigned int *frag)
{
	int				success;

	if (!load_shader("shader/vert.glsl", vert, 'v'))
		return (0);
	if (!load_shader("shader/frag.glsl", frag, 'f'))
		return (0);
	*prog = glCreateProgram();
	glAttachShader(*prog, *vert);
	glAttachShader(*prog, *frag);
	glLinkProgram(*prog);
	glGetProgramiv(*prog, GL_LINK_STATUS, &success);
	int infolength;
	glGetProgramiv(*prog, GL_INFO_LOG_LENGTH, &infolength);
	if (infolength > 0) { int i = 1024; char* str = malloc((i+1)*sizeof(*str)); glGetProgramInfoLog(*prog, infolength, &i, &str[0]); printf("glgeterror: %s\n", str); }
	if (success == GL_FALSE)
	{
		glDeleteShader(*vert);
		glDeleteShader(*frag);
		glDeleteProgram(*prog);
		return (0);
	}
	glDetachShader(*prog, *vert);
	glDetachShader(*prog, *frag);
	glDeleteShader(*vert);
	glDeleteShader(*frag);
	return (1);
}
