/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_primitives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:25:25 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 20:23:46 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

INTERSECT	intersect_sphere(t_primitive s, t_ray r)
{
	t_vec3		eye;
	INTERSECT	intersect;

	eye = vec3_sub(r.origin, s.position);
	intersect.intersects = solve_quadratic(
		vec3_dot(r.direction, r.direction),
		vec3_dot(eye, r.direction) * 2.0,
		vec3_dot(eye, eye) - (s.radius2),
		intersect.distance) && intersect_test(intersect.distance);
	intersect.closest = intersect.distance[0];
	intersect.position = intersect_compute_position(r, intersect.closest);
	intersect.normal = sphere_normal(intersect.position, s);
	return (intersect);
}

INTERSECT intersect_cylinder(t_primitive cp, t_ray r)
{
	t_vec3		v[6];
	INTERSECT	intersect;

	v[0] = vec3_proj(cp.position, cp.direction);
	v[1] = vec3_sub(cp.position, v[0]);
	v[2] = vec3_proj(r.origin, cp.direction);
	v[3] = vec3_proj(r.direction, cp.direction);
	v[4] = vec3_sub(r.direction, v[3]);
	v[5] = vec3_sub(vec3_sub(r.origin, v[2]), v[1]);
	if (cp.size > 0 && 
		vec3_length(vec3_sub(vec3_add(v[2],
		vec3_scale(v[3], intersect.distance[0])), v[0])) >= cp.size / 2)
		intersect.distance[0] = 0;
	if (cp.size > 0 && vec3_length(vec3_sub(vec3_add(v[2],
		vec3_scale(v[3], intersect.distance[1])), v[0])) >= cp.size / 2)
		intersect.distance[1] = 0;
	intersect.intersects = solve_quadratic(
		vec3_dot(v[4], v[4]),
		vec3_dot(v[4], v[4]) * 2.0,
		vec3_dot(v[5], v[5]) - (cp.radius2),
		intersect.distance) && intersect_test(intersect.distance);
	intersect.closest = intersect.distance[0];
	intersect.position = intersect_compute_position(r, intersect.closest);
	intersect.normal = cylinder_normal(intersect.position, cp);
	return (intersect);
}