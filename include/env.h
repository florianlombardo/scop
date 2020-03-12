/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:21 by flombard          #+#    #+#             */
/*   Updated: 2020/02/27 16:28:43 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "display.h"
# include "core.h"

typedef struct	s_env
{
	t_display	*dis;
	t_core		*core;
}				t_env;

#endif
