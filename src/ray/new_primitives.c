/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_primitives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:55:08 by gpinchon          #+#    #+#             */
/*   Updated: 2016/12/27 14:48:15 by gpinchon         ###   ########.fr       */
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
