/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:46:14 by flombard          #+#    #+#             */
/*   Updated: 2020/03/05 16:10:35 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "mlx.h"
#include "keys.h"
#include "env.h"
#include "display.h"
#include "core.h"

static int	ends_with(char *str, char *to_find)
{
	char	*end;

	end = NULL;
	end = strrchr(str, to_find[0]);
	if (end)
		return (strcmp(end, to_find));
	return (-1);
}

int			main(int argc, char *argv[])
{
	t_env	e;

	if (argc != 2 || ends_with(argv[1], ".scop") != 0)
	{
		ft_putendl("usage: ./scop file.scop");
		return (EXIT_FAILURE);
	}
	if (!(e.dis = init_display()))
		return (EXIT_FAILURE);
	if (!(e.core = init_core()))
	{
		quit_display(&(e.dis));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(e.dis->mlx, loop_hook, &e);
	mlx_hook(e.dis->win, CLOSE, CLOSEMASK, close_hook, &e);
	mlx_loop(e.dis->mlx);
	return (EXIT_SUCCESS);
}
