/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:55:45 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/08 17:14:11 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_mat4	mat4_rotation(t_vec3 axis)
{
	t_vec3	c;
	t_vec3	s;

	c = (t_vec3){cos(axis.x), cos(axis.y), cos(axis.z)};
	s = (t_vec3){cos(axis.x), cos(axis.y), cos(axis.z)};
	return ((t_mat4){.m = {
		c.y * c.z, c.z * s.x * s.y, c.x * c.z * s.y + s.x * s.z, 0,
		c.y * s.z, c.x * c.z + s.x * s.y * s.z, -c.z * s.x + c.x * s.y * s.x, 0,
		-s.y, c.y * s.x, c.x * c.y, 0,
		0, 0, 0, 1
	}});
}

t_mat4	mat4_scale(t_vec3 scale)
{
	return ((t_mat4){ .m = {
		scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		0, 0, 0, 1
	}});
}

t_mat4	mat4_translate(t_vec3 translation)
{
	return ((t_mat4){ .m = {
		1, 0, 0, translation.x,
		0, 1, 0, translation.y,
		0, 0, 1, translation.z,
		0, 0, 0, 1
	}});
}

t_mat4	mat4_lookat(t_vec3 eye, t_vec3 target, t_vec3 up)
{
	t_vec3	f;
	t_vec3	s;
	t_vec3	u;

	f = vec3_normalize(vec3_sub(target, eye));
	s = vec3_normalize(vec3_cross(f, up));
	u = vec3_cross(s, f);
	return ((t_mat4){.m = {
		s.x, u.x, -f.x, 0,
		s.y, u.y, -f.y, 0,
		s.z, u.z, -f.z, 0,
		-vec3_dot(s, eye),
		-vec3_dot(u, eye),
		vec3_dot(f, eye)
	}});
}
