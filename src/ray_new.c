/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:57:51 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 17:25:46 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

RAY			new_ray(VEC3 origin, VEC3 direction)
{
	return ((RAY){origin, direction});
}

INTERSECT	new_intersect(float t[2])
{
	INTERSECT	intersect;

	if ((intersect.intersects = test_intersect(t)))
		intersect.closest = find_closest(t);
	return (intersect);
}
