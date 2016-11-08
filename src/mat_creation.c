/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:55:45 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/08 18:06:48 by gpinchon         ###   ########.fr       */
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
	t_vec3	u;

	target = vec3_normalize(vec3_sub(target, eye));
	up = vec3_normalize(vec3_cross(target, up));
	u = vec3_cross(up, target);
	return ((t_mat4){.m = {
		up.x, u.x, -target.x, 0,
		up.y, u.y, -target.y, 0,
		up.z, u.z, -target.z, 0,
		-vec3_dot(up, eye),
		-vec3_dot(u, eye),
		vec3_dot(target, eye)
	}});
}
