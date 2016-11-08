/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vml.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:13:36 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/08 18:04:54 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VML_H
# define VML_H

# include <math.h>
# define TO_RADIAN(x)	(x * M_PI / 180.f)
# define VEC3			struct s_vec3
# define VEC4			struct s_vec4
# define MAT4			struct s_mat4
# define MAT3			struct s_mat3
# define FRUSTUM		VEC4

typedef struct	s_vec4
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4;

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef struct	s_mat4
{
	float		m[16];
}				t_mat4;

typedef struct	s_mat3
{
	float		m[9];
}				t_mat3;

VEC3			new_vec3(float x, float y, float z);
VEC4			new_vec4(float x, float y, float z, float w);
MAT4			new_m4(VEC4 a, VEC4 b, VEC4 c, VEC4 d);
MAT3			new_m3(VEC3 a, VEC3 b, VEC3 c);

VEC3			vec3_add(VEC3 v, VEC3 v1);
VEC4			vec4_add(VEC4 v, VEC4 v1);
VEC3			vec3_sub(VEC3 v, VEC3 v1);
VEC4			vec4_sub(VEC4 v, VEC4 v1);
VEC3			vec3_cross(VEC3 v, VEC3 v1);
float			vec3_dot(VEC3 v1, VEC3 v2);
float			vec4_dot(VEC4 v1, VEC4 v2);
float			vec3_length(VEC3 v);
float			vec4_length(VEC4 v);
VEC3			vec3_mult(VEC3 v1, VEC3 v2);
VEC4			vec4_mult(VEC4 v1, VEC4 v2);
VEC3			vec3_scale(VEC3 v, float f);
VEC4			vec4_scale(VEC4 v, float f);
VEC3			vec3_normalize(VEC3 v);
VEC4			vec4_normalize(VEC4 v);
VEC3			mat4_mult_vec3(MAT4 m, VEC3 v);
VEC4			mat4_mult_vec4(MAT4 m, VEC4 v);
t_vec2			vec3_to_vec2(VEC3 v);
VEC3			vec2_to_vec3(t_vec2 v);
VEC3			vec4_to_vec3(VEC4 v);
VEC4			vec3_to_vec4(VEC3 v);

VEC3			vec3_interp(float (*interp_function)(float, float, float),
				VEC3 start, VEC3 end, float percent);
VEC4			vec4_interp(float (*interp_function)(float, float, float),
				VEC4 start, VEC4 end, float percent);
float			linear(float start, float end, float percent);
float			cubic(float start, float end, float percent);

MAT4			mat4_identity(void);
MAT4			mat4_zero(void);
MAT3			mat3_identity(void);
MAT3			mat3_zero(void);
MAT3			mat4_to_mat3(MAT4 m);
MAT4			mat3_to_mat4(MAT3 m);
MAT4			mat4_inverse(const MAT4 i);
MAT4			mat4_transpose(const MAT4 in);
MAT4			mat4_mult_mat4(MAT4 m, MAT4 m1);

FRUSTUM			new_frustum(float left, float right, float bottom, float top);
MAT4			mat4_rotation(VEC3 axis);
MAT4			mat4_lookat(VEC3 eye, VEC3 target, VEC3 up);
MAT4			mat4_perspective(float fov, float aspect,
				float z_near, float z_far);
MAT4			mat4_orthographic(FRUSTUM frustum, float z_near, float z_far);
MAT4			mat4_scale(VEC3 scale);
MAT4			mat4_translate(VEC3 translation);

#endif
