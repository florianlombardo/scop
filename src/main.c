/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:46:14 by flombard          #+#    #+#             */
/*   Updated: 2020/09/29 21:32:21 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
	if (argc != 2 || ends_with(argv[1], ".obj") != 0)
	{
		ft_putendl("usage: ./scop file.obj");
		return (EXIT_FAILURE);
	}
	return 0;
}
