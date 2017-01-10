/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:25:25 by gpinchon          #+#    #+#             */
/*   Updated: 2017/01/07 16:52:20 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

/*
** Credits to http://www.scratchapixel.com/ for the original triangle function
*/

INTERSECT	intersect_triangle(u_obj p, t_ray r, TRANSFORM *transform)
{
	INTERSECT	inter;
	t_triangle	t;
	float		n_dot_r;
	VEC3		tp[3];

	inter = new_intersect();
	t = p.triangle;
	tp[0] = mat4_mult_vec3(transform->transform, t.point[0]);
	tp[1] = mat4_mult_vec3(transform->transform, t.point[1]);
	tp[2] = mat4_mult_vec3(transform->transform, t.point[2]);
	inter.normal = vec3_cross(vec3_sub(tp[1], tp[0]), vec3_sub(tp[2], tp[0]));
	n_dot_r = vec3_dot(inter.normal, r.direction);
	if (fabs(n_dot_r) < FLOAT_ZERO
	|| (inter.distance[0] = inter.distance[1] = (vec3_dot(inter.normal, r.origin) + vec3_dot(inter.normal, tp[0])) / n_dot_r) < 0)
		return (inter);
	inter.position = intersect_compute_position(r, inter.distance[0]);
	if (vec3_dot(inter.normal, vec3_cross(vec3_sub(tp[1], tp[0]), vec3_sub(inter.position, tp[0]))) < 0
	|| vec3_dot(inter.normal, vec3_cross(vec3_sub(tp[2], tp[1]), vec3_sub(inter.position, tp[1]))) < 0
	|| vec3_dot(inter.normal, vec3_cross(vec3_sub(tp[0], tp[2]), vec3_sub(inter.position, tp[2]))) < 0)
		return (inter);
	inter.intersects = 1;
	return (inter);
	(void)transform;
}

INTERSECT	intersect_sphere(u_obj p, t_ray r, TRANSFORM *transform)
{
	t_vec3		eye;
	INTERSECT	inter;

	inter = new_intersect();
	eye = vec3_sub(r.origin, transform->position);
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
		inter.normal = vec3_negate(sphere_normal(inter.position, p, transform));
	}
	else
	{
		inter.position = intersect_compute_position(r, inter.distance[0]);
		inter.normal = sphere_normal(inter.position, p, transform);
	}
	return (inter);
}

/*
** TODO find a better way to intersect a cylinder
** (Other than creating a "sphere" along the cylinder's axis...)
*/

INTERSECT intersect_cylinder(u_obj p, t_ray r, TRANSFORM *transform)
{
	t_vec3		v[6];
	INTERSECT	i;

	i = new_intersect();
	v[0] = vec3_proj(transform->position, transform->rotation);
	v[1] = vec3_sub(transform->position, v[0]);
	v[2] = vec3_proj(r.origin, transform->rotation);
	v[3] = vec3_proj(r.direction, transform->rotation);
	v[4] = vec3_sub(r.direction, v[3]);
	v[5] = vec3_sub(vec3_sub(r.origin, v[2]), v[1]);
	if (!(i.intersects = solve_quadratic(vec3_dot(v[4], v[4]),
		vec3_dot(v[5], v[4]) * 2.0, vec3_dot(v[5], v[5]) - (p.cylinder.radius2), i.distance)))
		return (i);
	if (p.cylinder.size > 0)
	{
		i.distance[0] *= (vec3_length(vec3_sub(vec3_add(v[2], vec3_scale(v[3], i.distance[0])), v[0])) <= p.cylinder.size / 2.f);
		i.distance[1] *= (vec3_length(vec3_sub(vec3_add(v[2], vec3_scale(v[3], i.distance[1])), v[0])) <= p.cylinder.size / 2.f);
	}
	if (!(i.intersects = intersect_test(i.distance)))
		return (i);
	if (i.distance[0] <= 0)
	{
		i.distance[0] = i.distance[1];
		i.position = intersect_compute_position(r, i.distance[0]);
		i.normal = vec3_negate(cylinder_normal(i.position, p, transform));
	}
	else
	{
		i.position = intersect_compute_position(r, i.distance[0]);
		i.normal = cylinder_normal(i.position, p, transform);
	}
	return (i);
}

INTERSECT	intersect_plane(u_obj p, t_ray r, TRANSFORM *transform)
{
	INTERSECT	inter;
	t_vec3		normal;
	float		denom;
	float		t;

	inter = new_intersect();
	normal = vec3_negate(transform->rotation);
	denom = vec3_dot(normal, r.direction);
	if (!float_equal(denom, 0.f))
	{
		if ((t = vec3_dot(vec3_sub(transform->position, r.origin), normal) / denom) >= FLOAT_ZERO)
		{
			inter.intersects = 1;
			inter.distance[0] = inter.distance[1] = t;
			inter.position = intersect_compute_position(r, inter.distance[0]);
			inter.normal = plane_normal(inter.position, p, transform);
			if (denom < 0)
				inter.normal = vec3_negate(inter.normal);
		}
	}
	return (inter);
}

INTERSECT	intersect_disc(u_obj d, t_ray r, TRANSFORM *transform)
{
	INTERSECT	inter;

	inter = intersect_plane(d, r, transform);
	inter.intersects = inter.intersects
	&& vec3_distance(inter.position, transform->position) <= d.disc.radius;
	return (inter);
}
