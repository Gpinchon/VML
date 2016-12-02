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

static float	cone_factor1(t_cone c, t_ray r, t_vec3 *vec)
{
	return (pow(cos(c.radius), 2) * vec3_dot(vec[1], vec[1]) -
		pow(sin(c.radius), 2) * pow(vec3_dot(r.direction, c.direction), 2));
}

static float	cone_factor2(t_cone c, t_ray r, t_vec3 *vec)
{
	return (2 * (pow(cos(c.radius), 2) * vec3_dot(vec[1], vec[2])) -
		2 * (pow(sin(c.radius), 2) * vec3_dot(r.direction, c.direction)
		* vec3_dot(vec[0], c.direction)));
}

static float	cone_factor3(t_cone c, t_vec3 *vec)
{
	return (pow(cos(c.radius), 2) * vec3_dot(vec[2], vec[2]) -
	pow(sin(c.radius), 2) * pow(vec3_dot(vec[0], c.direction), 2));
}

INTERSECT		intersect_cone(t_primitive cp, t_ray r)
{
	t_vec3	vec[3];
	INTERSECT	inter;

	inter = new_intersect();
	vec[0] = vec3_sub(r.origin, cp.data.cone.position);
	vec[1] = vec3_sub(r.direction, vec3_scale(cp.data.cone.direction,
		vec3_dot(r.direction, cp.data.cone.direction)));
	vec[2] = vec3_sub(vec[0], vec3_scale(cp.data.cone.direction,
		vec3_dot(vec[0], cp.data.cone.direction)));
	if (solve_quadratic(cone_factor1(cp.data.cone, r, vec),
		cone_factor2(cp.data.cone, r, vec), cone_factor3(cp.data.cone, vec), inter.distance) 
		&& intersect_test(inter.distance))
	{
		if ((cp.data.cone.size == 0 || cp.data.cone.direction.x > 0)
		|| (cp.data.cone.size > 0. && vec3_dot(cp.data.cone.direction,
			vec[0] = vec3_sub(vec3_add(r.origin,
			vec3_scale(r.direction, inter.distance[0])), cp.data.cone.position)) > 0.
		&& cp.data.cone.size / cos(atan(cp.data.cone.radius)) > vec3_length(vec[0])))
		{
			inter.intersects = 1;
			inter.position = intersect_compute_position(r, inter.distance[0]);
			inter.normal = cone_normal(inter.position, cp);
			return (inter);
		}
	}
	return (inter);
}
