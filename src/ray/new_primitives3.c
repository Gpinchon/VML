/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_primitives3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:48:29 by gpinchon          #+#    #+#             */
/*   Updated: 2016/12/27 14:48:50 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

PRIMITIVE	new_capped_cylinder(float radius, float size,
	VEC3 position, VEC3 direction)
{
	PRIMITIVE	c;

	c = new_primitive(capped_cylinder);
	c.position = position;
	c.direction = vec3_normalize(direction);
	c.radius2 = (c.radius = radius) * radius;
	c.size = size;
	return (c);
}