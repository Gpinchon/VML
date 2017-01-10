/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_primitives3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:48:29 by gpinchon          #+#    #+#             */
/*   Updated: 2016/12/27 15:04:39 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

PRIMITIVE	new_capped_cylinder(float radius, float size)
{
	PRIMITIVE	c;

	c = new_primitive(cylinder);
	c.data.cylinder.radius2 = (c.data.cylinder.radius = radius) * radius;
	c.data.cylinder.size = size;
	return (c);
}

PRIMITIVE	new_cylinder(float radius, float size)
{
	PRIMITIVE	c;

	c = new_primitive(cylinder);
	c.data.cylinder.radius2 = (c.data.cylinder.radius = radius) * radius;
	c.data.cylinder.size = size;
	return (c);
}
