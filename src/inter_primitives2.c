/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_primitives2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:44:28 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 20:55:15 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

static float	cone_factor1(t_primitive cp, t_ray r, t_vec3 *vec)
{
	return (pow(cos(cp.radius), 2) * vec3_dot(vec[1], vec[1]) -
		pow(sin(cp.radius), 2) * pow(vec3_dot(r.direction, cp.direction), 2));
}

static float	cone_factor2(t_primitive cp, t_ray r, t_vec3 *vec)
{
	return (2 * (pow(cos(cp.radius), 2) * vec3_dot(vec[1], vec[2])) -
		2 * (pow(sin(cp.radius), 2) * vec3_dot(r.direction, cp.direction)
		* vec3_dot(vec[0], cp.direction)));
}

static float	cone_factor3(t_primitive cp, t_vec3 *vec)
{
	return (pow(cos(cp.radius), 2) * vec3_dot(vec[2], vec[2]) -
	pow(sin(cp.radius), 2) * pow(vec3_dot(vec[0], cp.direction), 2));
}

INTERSECT		intersect_cone(t_primitive cp, t_ray r)
{
	t_vec3	vec[3];
	INTERSECT	inter;

	inter = new_intersect();
	vec[0] = vec3_sub(r.origin, cp.position);
	vec[1] = vec3_sub(r.direction, vec3_scale(cp.direction,
		vec3_dot(r.direction, cp.direction)));
	vec[2] = vec3_sub(vec[0], vec3_scale(cp.direction,
		vec3_dot(vec[0], cp.direction)));
	if (solve_quadratic(cone_factor1(cp, r, vec),
		cone_factor2(cp, r, vec), cone_factor3(cp, vec), inter.distance) 
		&& intersect_test(inter.distance))
	{
		if ((cp.size == 0 || cp.direction.x > 0)
		|| (cp.size > 0. && vec3_dot(cp.direction,
			vec[0] = vec3_sub(vec3_add(r.origin,
			vec3_scale(r.direction, inter.distance[0])), cp.position)) > 0.
		&& cp.size / cos(atan(cp.radius)) > vec3_length(vec[0])))
		{
			inter.intersects = 1;
			inter.closest = inter.distance[0];
			inter.position = intersect_compute_position(r, inter.closest);
			inter.normal = cone_normal(inter.position, cp);
			return (inter);
		}
	}
	return (inter);
}
