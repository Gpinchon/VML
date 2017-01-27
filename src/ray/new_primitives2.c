/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_primitives2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:41:06 by gpinchon          #+#    #+#             */
/*   Updated: 2017/01/26 18:32:26 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

PRIMITIVE	new_disc(t_json *data)
{
	float		radius;
	PRIMITIVE	p;

	radius = data->value;
	p = new_primitive(disc);
	p.data.disc.radius = radius;
	p.data.disc.radius2 = radius * radius;
	return (p);
}

PRIMITIVE	new_plane(t_json *data)
{
	PRIMITIVE	p;

	(void)data;
	p = new_primitive(plane);
	return (p);
}
