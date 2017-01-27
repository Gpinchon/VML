/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:25:25 by gpinchon          #+#    #+#             */
/*   Updated: 2017/01/27 17:28:01 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

INTERSECT			intersect_triangle(u_obj p, t_ray r, TRANSFORM *tr)
{
	INTERSECT	i;
	float		n_dot_r;
	VEC3		tp[3];

	i = new_intersect();
	tp[0] = mat4_mult_vec3(tr->transform, p.triangle.point[0]);
	tp[1] = mat4_mult_vec3(tr->transform, p.triangle.point[1]);
	tp[2] = mat4_mult_vec3(tr->transform, p.triangle.point[2]);
	i.normal = vec3_cross(vec3_sub(tp[1], tp[0]), vec3_sub(tp[2], tp[0]));
	n_dot_r = vec3_dot(i.normal, r.direction);
	if (fabs(n_dot_r) < FLOAT_ZERO || (i.distance[0] =
	(vec3_dot(i.normal, r.origin) + vec3_dot(i.normal, tp[0])) / n_dot_r) < 0)
		return (i);
	i.distance[1] = i.distance[0];
	i.position = intersect_compute_position(r, i.distance[0]);
	if (vec3_dot(i.normal, vec3_cross(vec3_sub(tp[1], tp[0]),
		vec3_sub(i.position, tp[0]))) < 0
	|| vec3_dot(i.normal, vec3_cross(vec3_sub(tp[2], tp[1]),
		vec3_sub(i.position, tp[1]))) < 0
	|| vec3_dot(i.normal, vec3_cross(vec3_sub(tp[0], tp[2]),
		vec3_sub(i.position, tp[2]))) < 0)
		return (i);
	i.intersects = 1;
	return (i);
}

INTERSECT			intersect_sphere(u_obj p, t_ray r, TRANSFORM *t)
{
	t_vec3		eye;
	INTERSECT	inter;

	inter = new_intersect();
	eye = vec3_sub(r.origin, t->position);
	if (!(inter.intersects = solve_quadratic(
				vec3_dot(r.direction, r.direction),
				vec3_dot(eye, r.direction) * 2.0,
				vec3_dot(eye, eye) - (p.sphere.radius2),
				inter.distance) && intersect_test(inter.distance)))
		return (inter);
	if (inter.distance[0] <= 0)
	{
		inter.distance[0] = inter.distance[1];
		inter.position = intersect_compute_position(r, inter.distance[0]);
		inter.normal = vec3_negate(sphere_normal(inter.position, p, t));
	}
	else
	{
		inter.position = intersect_compute_position(r, inter.distance[0]);
		inter.normal = sphere_normal(inter.position, p, t);
	}
	return (inter);
}

inline INTERSECT	intersect_plane(u_obj p, t_ray r, TRANSFORM *t)
{
	INTERSECT	inter;
	t_vec3		normal;
	float		denom;
	float		t;

	inter = new_intersect();
	normal = vec3_negate(t->rotation);
	denom = vec3_dot(normal, r.direction);
	if (!float_equal(denom, 0.f))
	{
		if ((t = vec3_dot(vec3_sub(t->position, r.origin), normal) / denom)
			>= FLOAT_ZERO)
		{
			inter.intersects = 1;
			inter.distance[0] = t;
			inter.distance[1] = inter.distance[0];
			inter.position = intersect_compute_position(r, inter.distance[0]);
			inter.normal = plane_normal(inter.position, p, t);
			if (denom < 0)
				inter.normal = vec3_negate(inter.normal);
		}
	}
	return (inter);
}

INTERSECT			intersect_disc(u_obj d, t_ray r, TRANSFORM *transform)
{
	INTERSECT	inter;

	inter = intersect_plane(d, r, transform);
	inter.intersects = inter.intersects
	&& vec3_distance(inter.position, transform->position) <= d.disc.radius;
	return (inter);
}
