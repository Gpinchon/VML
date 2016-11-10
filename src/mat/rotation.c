/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:56:16 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/10 18:04:03 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_mat2	mat2_rotation(float angle)
{
	return ((t_mat2){.m = {
		cos(angle), sin(angle),
		-sin(angle), cos(angle)
	}});
}

t_mat3	mat3_rotation(t_vec3 axis)
{
	t_vec3	c;
	t_vec3	s;

	c = (t_vec3){cos(axis.x), cos(axis.y), cos(axis.z)};
	s = (t_vec3){cos(axis.x), cos(axis.y), cos(axis.z)};
	return ((t_mat3){.m = {
		c.y * c.z, c.z * s.x * s.y, c.x * c.z * s.y + s.x * s.z,
		c.y * s.z, c.x * c.z + s.x * s.y * s.z, -c.z * s.x + c.x * s.y * s.x,
		-s.y, c.y * s.x, c.x * c.y
	}});
}

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