/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:46:46 by flombard          #+#    #+#             */
/*   Updated: 2020/03/11 18:49:20 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "mlx_opengl.h"
#include "libft.h"
#include "display.h"

t_display	*init_display(void)
{
	t_display	*ret;

	if (!(ret = calloc(1, sizeof(*ret))))
	{
		perror(NULL);
		return (NULL);
	}
	if (!(ret->mlx = mlx_init()))
	{
		ft_putendl("Graphical initialization failed.");
		quit_display(&ret);
		return (NULL);
	}
	if (!(ret->win = mlx_new_opengl_window(ret->mlx, WIDTH, HEIGHT, "Scop")))
	{
		ft_putendl("Window not created.");
		quit_display(&ret);
		return (NULL);
	}
	return (ret);
}
