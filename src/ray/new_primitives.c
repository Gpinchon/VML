/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_primitives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:55:08 by gpinchon          #+#    #+#             */
/*   Updated: 2017/01/27 11:46:38 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

VEC3		get_vector3_from_json(t_value val)
{
	return ((VEC3){ json_get(arr.data.obj, "x").data.number,
					json_get(arr.data.obj, "y").data.number,
					json_get(arr.data.obj, "z").data.number,
			});
}

PRIMITIVE	new_sphere(t_value val)
{
	float		radius;
	PRIMITIVE	s;

	radius = json_get(val.data.obj, "radius").data.number;
	s = new_primitive(sphere);
	s.data.sphere.radius2 = (s.data.sphere.radius = radius) * radius;
	return (s);
}

PRIMITIVE	new_cone(t_value val)
{
	float		radius;
	float		size;
	PRIMITIVE	c;

	radius = json_get(val.data.obj, "radius").data.number;
	size = json_get(val.data.obj, "size").data.number;
	c = new_primitive(cone);
	c.data.cone.radius2 = (c.data.cone.radius = radius) * radius;
	c.data.cone.size = size;
	return c;
}

PRIMITIVE	new_triangle(t_value val)
{
	PRIMITIVE	t;

	t = new_primitive(triangle);
	t.data.triangle.point[0] = get_vec3_json(json_get(val.data.obj,	"point0"));
	t.data.triangle.point[1] = get_vec3_json(json_get(val.data.obj,	"point1"));
	t.data.triangle.point[2] = get_vec3_json(json_get(val.data.obj,	"point2"));
	return (t);
}
