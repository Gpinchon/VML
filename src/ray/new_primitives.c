/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_primitives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:55:08 by gpinchon          #+#    #+#             */
/*   Updated: 2016/12/02 19:36:12 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

PRIMITIVE	new_sphere(float radius)
{
	PRIMITIVE	s;

	s = new_primitive(sphere);
	s.data.sphere.radius2 = (s.data.sphere.radius = radius) * radius;
	return (s);
}

PRIMITIVE	new_cylinder(float radius, float size)
{
	PRIMITIVE	c;

	c = new_primitive(cylinder);
	c.data.cylinder.radius2 = (c.data.cylinder.radius = radius) * radius;
	c.data.cylinder.size = size;
	return (c);
}

PRIMITIVE	new_plane(void)
{
	PRIMITIVE	p;

	p = new_primitive(plane);
	return (p);
}

PRIMITIVE	new_cone(float radius, float size)
{
	PRIMITIVE	c;

	c = new_primitive(cone);
	c.data.cone.radius2 = (c.data.cone.radius = radius) * radius;
	c.data.cone.size = size;
	return c;
}

PRIMITIVE	new_triangle(VEC3 a, VEC3 b, VEC3 c)
{
	PRIMITIVE	t;

	t = new_primitive(triangle);
	t.data.triangle.point[0] = a;
	t.data.triangle.point[1] = b;
	t.data.triangle.point[2] = c;
	return (t);
}
