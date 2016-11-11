/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:57:51 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/11 18:29:58 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

RAY			new_ray(VEC3 origin, VEC3 direction)
{
	return ((RAY){origin, direction});
}

INTERSECT	new_intersect()
{
	INTERSECT	intersect;

	memset(&intersect, 0, sizeof(INTERSECT));
	return (intersect);
}

PRIMITIVE	new_primitive(PRIM_TYPE type)
{
	PRIMITIVE	primitive;

	memset(&primitive, 0, sizeof(PRIMITIVE));
	primitive.type = type;
	return(primitive);
}