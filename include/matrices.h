/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flombard <flombard@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:26:09 by flombard          #+#    #+#             */
/*   Updated: 2020/03/12 15:33:27 by flombard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include <math.h>
# define RADIANS(x) (x * (M_PI/180.f))

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_vec4
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4;

typedef struct	s_mat4
{
	t_vec4		cols[4];
}				t_mat4;

/*
** Creation
*/

t_vec3			new_vec3(float x, float y, float z);
t_vec4			new_vec4(float x, float y, float z, float w);
t_mat4			new_mat4(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d);
t_mat4			identity(void);

/*
** Operations
*/

t_vec3			substract(t_vec3 a, t_vec3 b);
float			dot(t_vec3 a, t_vec3 b);
t_vec3			cross(t_vec3 a, t_vec3 b);
t_vec3			normalize(t_vec3 vec);
float			*mat4_to_floats(t_mat4 mat);

/*
** Transformations
*/

t_mat4			translate(t_mat4 to_trans, t_vec3 vec);
t_mat4			scale(t_mat4 to_scale, t_vec3 vec);
t_mat4			rotate_x(t_mat4 to_rot, float radian);
t_mat4			rotate_y(t_mat4 to_rot, float radian);
t_mat4			rotate_z(t_mat4 to_rot, float radian);

/*
** Coordinates Calculations
*/

t_mat4			look_at(t_vec3 eye, t_vec3 target, t_vec3 world_up);
t_mat4			perspective(float fov, float aspect_ratio, float near,
																float far);

#endif
