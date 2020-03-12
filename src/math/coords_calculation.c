/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:25:12 by flombard          #+#    #+#             */
/*   Updated: 2020/03/12 15:52:16 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrices.h"

t_mat4	look_at(t_vec3 eye, t_vec3 target, t_vec3 world_up)
{
	t_vec3	dir;
	t_vec3	cam_right;
	t_vec3	cam_up;
	t_mat4	view;

	dir = normalize(substract(target, eye));
	cam_right = normalize(cross(dir, world_up));
	cam_up = cross(cam_right, dir);
	view = new_mat4(new_vec4(cam_right.x, cam_up.x, -dir.x, 0.0f),
	new_vec4(cam_right.y, cam_up.y, -dir.y, 0.0f),
	new_vec4(cam_right.z, cam_up.z, -dir.z, 0.0f),
	new_vec4(-dot(cam_right, eye), -dot(cam_up, eye), dot(dir, eye), 1.0f));
	return (view);
}

t_mat4	perspective(float fov, float aspect_ratio, float near, float far)
{
	t_mat4	ret;
	float	tan_half_fov;

	ret = identity();
	tan_half_fov = tanf(fov / 2.0f);
	ret.cols[0].x = 1.0f / (aspect_ratio * tan_half_fov);
	ret.cols[1].y = 1.0f / tan_half_fov;
	ret.cols[2].z = -(far + near) / (far - near);
	ret.cols[3].z = -(2.0f * far * near) / (far - near);
	ret.cols[2].w = -1.0f;
	return (ret);
}
