/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:59:30 by flombard          #+#    #+#             */
/*   Updated: 2020/03/12 13:53:48 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "matrices.h"

t_vec3	substract(t_vec3 a, t_vec3 b)
{
	t_vec3	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

float	dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	cross(t_vec3 a, t_vec3 b)
{
	return (new_vec3((a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z),
	(a.x * b.y) - (a.y * b.x)));
}

t_vec3	normalize(t_vec3 vec)
{
	t_vec3	ret;
	float	magnitude;

	magnitude = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	ret.x = vec.x / magnitude;
	ret.y = vec.y / magnitude;
	ret.z = vec.z / magnitude;
	return (ret);
}

float	*mat4_to_floats(t_mat4 mat)
{
	float	*ret;

	if (!(ret = malloc(16 * sizeof(*ret))))
		return (NULL);
	ret[0] = mat.cols[0].x;
	ret[1] = mat.cols[0].y;
	ret[2] = mat.cols[0].z;
	ret[3] = mat.cols[0].w;
	ret[4] = mat.cols[1].x;
	ret[5] = mat.cols[1].y;
	ret[6] = mat.cols[1].z;
	ret[7] = mat.cols[1].w;
	ret[8] = mat.cols[2].x;
	ret[9] = mat.cols[2].y;
	ret[10] = mat.cols[2].z;
	ret[11] = mat.cols[2].w;
	ret[12] = mat.cols[3].x;
	ret[13] = mat.cols[3].y;
	ret[14] = mat.cols[3].z;
	ret[15] = mat.cols[3].w;
	return (ret);
}
