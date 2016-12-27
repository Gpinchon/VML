/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_primitives2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:41:06 by gpinchon          #+#    #+#             */
/*   Updated: 2016/12/27 14:45:03 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

PRIMITIVE	new_disc(float radius, VEC3 position, VEC3 direction)
{
	PRIMITIVE	p;

	p = new_primitive(disc);
	p.position = position;
	p.direction = direction;
	p.radius = radius;
	p.radius2 = radius * radius;
	return (p);
}

PRIMITIVE	new_plane(VEC3 position, VEC3 direction)
{
	PRIMITIVE	p;

	p = new_primitive(plane);
	p.position = position;
	p.direction = direction;
	return (p);
}