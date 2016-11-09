/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_primitives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:25:25 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 21:22:17 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

INTERSECT	intersect_sphere(t_primitive s, t_ray r)
{
	t_vec3		eye;
	INTERSECT	inter;

	inter = new_intersect();
	eye = vec3_sub(r.origin, s.position);
	if (!(inter.intersects = solve_quadratic(
				vec3_dot(r.direction, r.direction),
				vec3_dot(eye, r.direction) * 2.0,
				vec3_dot(eye, eye) - (s.radius2),
				inter.distance) && intersect_test(inter.distance)))
		return (inter);
	inter.position = intersect_compute_position(r, inter.distance[0]);
	inter.normal = sphere_normal(inter.position, s);
	return (inter);
}

INTERSECT	intersect_cylinder(t_primitive cp, t_ray r)
{
	t_vec3		v[6];
	INTERSECT	inter;

	inter = new_intersect();
	v[0] = vec3_proj(cp.position, cp.direction);
	v[1] = vec3_sub(cp.position, v[0]);
	v[2] = vec3_proj(r.origin, cp.direction);
	v[3] = vec3_proj(r.direction, cp.direction);
	v[4] = vec3_sub(r.direction, v[3]);
	v[5] = vec3_sub(vec3_sub(r.origin, v[2]), v[1]);
	if (cp.size > 0 && vec3_length(vec3_sub(vec3_add(v[2],
		vec3_scale(v[3], inter.distance[0])), v[0])) >= cp.size / 2)
		inter.distance[0] = 0;
	if (cp.size > 0 && vec3_length(vec3_sub(vec3_add(v[2],
		vec3_scale(v[3], inter.distance[1])), v[0])) >= cp.size / 2)
		inter.distance[1] = 0;
	if (!(inter.intersects = solve_quadratic(
				vec3_dot(v[4], v[4]), vec3_dot(v[4], v[4]) * 2.0,
				vec3_dot(v[5], v[5]) - (cp.radius2),
				inter.distance) && intersect_test(inter.distance)))
		return (inter);
	inter.position = intersect_compute_position(r, inter.distance[0]);
	inter.normal = cylinder_normal(inter.position, cp);
	return (inter);
}

INTERSECT	intersect_plane(t_primitive cp, t_ray r)
{
	INTERSECT	inter;
	t_vec3		normal;
	float		denom;
	float		t;

	inter = new_intersect();
	normal = vec3_negate(cp.direction);
	denom = vec3_dot(normal, r.direction);
	inter = new_intersect();
	if (denom > FLOAT_ZERO)
	{
		if ((t = vec3_dot(vec3_sub(cp.position, r.origin), normal) / denom) >= FLOAT_ZERO)
		{
			inter.intersects = 1;
			inter.distance[0] = inter.distance[1] = t;
			inter.position = intersect_compute_position(r, inter.distance[0]);
			inter.normal = plane_normal(inter.position, cp);
		}
	}
	return (inter);
}
