/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:20:11 by flombard          #+#    #+#             */
/*   Updated: 2020/03/12 15:17:46 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrices.h"

t_mat4	translate(t_mat4 to_trans, t_vec3 vec)
{
	t_mat4	ret;
	int		i;

	i = -1;
	while (++i < 4)
		ret.cols[i] = new_vec4(to_trans.cols[i].x + vec.x * to_trans.cols[i].w,
		to_trans.cols[i].y + vec.y * to_trans.cols[i].w,
		to_trans.cols[i].z + vec.z * to_trans.cols[i].w, to_trans.cols[i].w);
	return (ret);
}

t_mat4	scale(t_mat4 to_scale, t_vec3 vec)
{
	t_mat4	ret;
	int		i;

	i = -1;
	while (++i < 4)
		ret.cols[i] = new_vec4(to_scale.cols[i].x * vec.x, to_scale.cols[i].y *
		vec.y, to_scale.cols[i].z * vec.z, to_scale.cols[i].w);
	return (ret);
}

t_mat4	rotate_x(t_mat4 to_rot, float radian)
{
	t_mat4	ret;
	int		i;

	i = -1;
	while (++i < 4)
		ret.cols[i] = new_vec4(to_rot.cols[i].x, to_rot.cols[i].y * cosf(radian)
		- to_rot.cols[i].z * sinf(radian), to_rot.cols[i].y * sinf(radian) +
		to_rot.cols[i].z * cosf(radian), to_rot.cols[i].w);
	return (ret);
}

t_mat4	rotate_y(t_mat4 to_rot, float radian)
{
	t_mat4	ret;
	int		i;

	i = -1;
	while (++i < 4)
		ret.cols[i] = new_vec4(to_rot.cols[i].x * cosf(radian) +
		to_rot.cols[i].z * sinf(radian), to_rot.cols[i].y, to_rot.cols[i].z *
		cosf(radian) - to_rot.cols[i].x * sinf(radian), to_rot.cols[i].w);
	return (ret);
}

t_mat4	rotate_z(t_mat4 to_rot, float radian)
{
	t_mat4	ret;
	int		i;

	i = -1;
	while (++i < 4)
		ret.cols[i] = new_vec4(to_rot.cols[i].x * cosf(radian) -
		to_rot.cols[i].y * sinf(radian), to_rot.cols[i].x * sinf(radian) +
		to_rot.cols[i].y * cosf(radian), to_rot.cols[i].z, to_rot.cols[i].w);
	return (ret);
}
