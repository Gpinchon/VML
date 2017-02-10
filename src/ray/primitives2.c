/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:44:28 by gpinchon          #+#    #+#             */
/*   Updated: 2017/02/10 14:31:15 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

INTERSECT				intersect_cone(OBJ cp, RAY r, TRANSFORM *transform)
{
	INTERSECT	inter;
	VEC3		co = vec3_sub(r.origin, transform->position);
	float		rdpd = vec3_dot(r.direction, transform->rotation);
	float		copd = vec3_dot(co, transform->rotation);
	float		rad = 1 + cp.cone.radius2;

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

static inline INTERSECT	inter_cyl(OBJ p, t_ray r, TRANSFORM *t, INTERSECT i)
{
	if (!(i.intersects = intersect_test(i.distance)))
		return (i);
	if (i.distance[0] <= 0)
	{
		i.distance[0] = i.distance[1];
		i.position = intersect_compute_position(r, i.distance[0]);
		i.normal = vec3_negate(cylinder_normal(i.position, p, t));
	}
	else
	{
		i.position = intersect_compute_position(r, i.distance[0]);
		i.normal = cylinder_normal(i.position, p, t);
	}
	return (i);
}

INTERSECT				intersect_cylinder(OBJ p, t_ray r, TRANSFORM *t)
{
	t_vec3		v[5];
	INTERSECT	i;

	i = new_intersect();
	v[0] = vec3_proj(t->position, t->rotation);
	v[1] = vec3_proj(r.origin, t->rotation);
	v[2] = vec3_proj(r.direction, t->rotation);
	v[3] = vec3_sub(r.direction, v[2]);
	v[4] = vec3_sub(vec3_sub(r.origin, v[1]), vec3_sub(t->position, v[0]));
	if (!(i.intersects = solve_quadratic(vec3_dot(v[3], v[3]),
		vec3_dot(v[4], v[3]) * 2.0,
		vec3_dot(v[4], v[4]) - (p.cylinder.radius2), i.distance)))
		return (i);
	if (p.cylinder.size > 0)
	{
		i.distance[0] *= (vec3_length(vec3_sub(vec3_add(v[1], vec3_scale(v[2],
			i.distance[0])), v[0])) <= p.cylinder.size / 2.f);
		i.distance[1] *= (vec3_length(vec3_sub(vec3_add(v[1], vec3_scale(v[2],
			i.distance[1])), v[0])) <= p.cylinder.size / 2.f);
	}
	return (inter_cyl(p, r, t, i));
}
