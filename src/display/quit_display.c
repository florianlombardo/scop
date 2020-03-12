/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:46:40 by flombard          #+#    #+#             */
/*   Updated: 2020/02/20 18:46:41 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "display.h"

void	quit_display(t_display **dis)
{
	if (*dis)
	{
		if ((*dis)->win)
			mlx_destroy_window((*dis)->mlx, (*dis)->win);
		free((*dis)->mlx);
		free(*dis);
	}
}
