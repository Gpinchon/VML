/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vml.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:13:36 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/08 16:54:02 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VML_H
# define VML_H

# include <math.h>
# define TO_RADIAN(x) (x * M_PI / 180.f)

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

t_vec3			new_vec3(float x, float y, float z);
t_vec4			new_vec4(float x, float y, float z, float w);
t_mat4			new_m4(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d);
t_mat3			new_m3(t_vec3 a, t_vec3 b, t_vec3 c);

t_vec3			vec3_add(t_vec3 v, t_vec3 v1);
t_vec4			vec4_add(t_vec4 v, t_vec4 v1);
t_vec3			vec3_sub(t_vec3 v, t_vec3 v1);
t_vec4			vec4_sub(t_vec4 v, t_vec4 v1);
t_vec3			vec4_to_vec3(t_vec4 v);
t_vec4			vec3_to_vec4(t_vec3 v);
t_vec3			vec3_cross(t_vec3 v, t_vec3 v1);
float			vec3_dot(t_vec3 v1, t_vec3 v2);
float			vec4_dot(t_vec4 v1, t_vec4 v2);
float			vec3_length(t_vec3 v);
float			vec4_length(t_vec4 v);
t_vec3			vec3_mult_vec3(t_vec3 v1, t_vec3 v2);
t_vec4			vec4_mult_vec4(t_vec4 v1, t_vec4 v2);
t_vec3			mat4_mult_vec3(t_mat4 m, t_vec3 v);
t_vec4			mat4_mult_vec4(t_mat4 m, t_vec4 v);
t_vec3			vec3_normalize(t_vec3 v);
t_vec4			vec4_normalize(t_vec4 v);
t_vec2			vec3_to_vec2(t_vec3 v);
t_vec3			vec2_to_vec3(t_vec2 v);
t_vec3			vec3_interp(float (*interp_function)(float, float, float),
	t_vec3 start, t_vec3 end, float percent);
t_vec4			vec4_interp(float (*interp_function)(float, float, float),
	t_vec4 start, t_vec4 end, float percent);
float			linear(float start, float end, float percent);
float			cubic(float start, float end, float percent);

t_mat4			mat4_identity(void);
t_mat4			mat4_zero(void);
t_mat3			mat3_identity(void);
t_mat3			mat3_zero(void);
t_mat3			mat4_to_mat3(t_mat4 m);
t_mat4			mat3_to_mat4(t_mat3 m);
t_mat4			mat4_inverse(const t_mat4 i);
t_mat4			mat4_transpose(const t_mat4 in);
t_mat4			mat4_mult_mat4(t_mat4 m, t_mat4 m1);

t_mat4			mat4_rotation(t_vec3 axis);
t_mat4			mat4_lookat(t_vec3 eye, t_vec3 target, t_vec3 up);
t_mat4			mat4_perspective(float fov, float aspect,
	float z_near, float z_far);
t_mat4			mat4_scale(t_vec3 scale);
t_mat4			mat4_translate(t_vec3 translation);

#endif
