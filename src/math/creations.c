/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:24:47 by flombard          #+#    #+#             */
/*   Updated: 2020/03/11 18:37:04 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_vec3	new_vec3(float x, float y, float z)
{
	t_vec3	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vec4	new_vec4(float x, float y, float z, float w)
{
	t_vec4	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	ret.w = w;
	return (ret);
}

t_mat4	new_mat4(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d)
{
	t_mat4	ret;

	ret.cols[0] = a;
	ret.cols[1] = b;
	ret.cols[2] = c;
	ret.cols[3] = d;
	return (ret);
}

t_mat4	identity(void)
{
	return (new_mat4(new_vec4(1.0f, 0.0f, 0.0f, 0.0f),
	new_vec4(0.0f, 1.0f, 0.0f, 0.0f), new_vec4(0.0f, 0.0f, 1.0f, 0.0f),
	new_vec4(0.0f, 0.0f, 0.0f, 1.0f)));
}
