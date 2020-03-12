/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:47:02 by flombard          #+#    #+#             */
/*   Updated: 2020/03/12 15:55:46 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

typedef struct		s_core
{
	unsigned int	vbo;
	//unsigned int	ebo;
	unsigned int	vao;
	unsigned int	vert;
	unsigned int	frag;
	unsigned int	program;
	float			*transform;
}					t_core;

/*
** Core related
*/

t_core				*init_core(void);
int					create_program(unsigned int *prog, unsigned int *vert,
														unsigned int *frag);
void				quit_core(t_core **core);

/*
** User input related
*/

int					close_hook(void *param);
int					loop_hook(void *param);

#endif
