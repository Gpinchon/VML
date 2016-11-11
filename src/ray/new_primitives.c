/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_primitives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:55:08 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/11 18:18:33 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

PRIMITIVE	new_sphere(float radius, VEC3 position)
{
	PRIMITIVE	s;

	s = new_primitive(sphere);
	s.position = position;
	s.radius2 = (s.radius = radius) * radius;
	return (s);
}

PRIMITIVE	new_cylinder(float radius, float size,
	VEC3 position, VEC3 direction)
{
	PRIMITIVE	c;

	c = new_primitive(cylinder);
	c.position = position;
	c.direction = vec3_normalize(direction);
	c.radius2 = (c.radius = radius) * radius;
	c.size = size;
	return (c);
}

PRIMITIVE	new_plane(VEC3 position, VEC3 direction)
{
	PRIMITIVE	p;

	p = new_primitive(plane);
	p.position = position;
	p.direction = direction;
	return (p);
}

PRIMITIVE	new_cone(float radius, float size,
	VEC3 position, VEC3 direction)
{
	PRIMITIVE	c;

	c = new_primitive(cone);
	c.position = position;
	c.direction = vec3_normalize(direction);
	c.radius2 = (c.radius = radius) * radius;
	c.size = size;
	return c;
}

PRIMITIVE	new_triangle(VEC3 a, VEC3 b, VEC3 c)
{
	PRIMITIVE	t;

	t = new_primitive(triangle);
	t.point[0] = a;
	t.point[1] = b;
	t.point[2] = c;
	return (t);
}
