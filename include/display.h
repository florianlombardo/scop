/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:47:09 by flombard          #+#    #+#             */
/*   Updated: 2020/03/11 18:49:19 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# define WIDTH 1280
# define HEIGHT 720

typedef struct	s_display
{
	void		*mlx;
	void		*win;
}				t_display;

t_display		*init_display(void);
void			quit_display(t_display **dis);

#endif
