/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:44:28 by gpinchon          #+#    #+#             */
/*   Updated: 2016/12/02 19:53:17 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

INTERSECT		intersect_cone(OBJ cp, RAY r, TRANSFORM *transform)
{
	INTERSECT	inter;
	VEC3	co = vec3_sub(r.origin, transform->position);
	float	rdpd = vec3_dot(r.direction, transform->rotation);
	float	copd = vec3_dot(co, transform->rotation);
	float	rad = 1 + cp.cone.radius2;
	if ((inter.intersects = (solve_quadratic(
		vec3_dot(r.direction, r.direction) - rad * pow(rdpd, 2),
		2 * (vec3_dot(r.direction, co) - rad * rdpd * copd),
		vec3_dot(co, co) - rad * pow(copd, 2), inter.distance)
	&& intersect_test(inter.distance))))
	{
		if (inter.distance[0] <= 0)
			inter.distance[0] = inter.distance[1];
		inter.position = intersect_compute_position(r, inter.distance[0]);
		float	m = rdpd * inter.distance[0] + copd;
		if (vec3_dot(transform->rotation, vec3_normalize(vec3_sub(inter.position, transform->position))) < 0)
			inter.intersects = 0;
		else if (cp.cone.size >= 0)
			inter.intersects = (vec3_distance(transform->position, vec3_add(transform->position, vec3_scale(transform->rotation, m))) <= cp.cone.size);
		if (inter.intersects)
			inter.normal = vec3_normalize(vec3_sub(vec3_sub(inter.position, transform->position), vec3_scale(transform->rotation, rad * m)));
	}
	return (inter);
}
