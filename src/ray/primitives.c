/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:25:25 by gpinchon          #+#    #+#             */
/*   Updated: 2016/12/27 16:34:26 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

/*
** Credits to http://www.scratchapixel.com/ for the original triangle function
*/

INTERSECT	intersect_triangle(t_primitive t, t_ray r)
{
	INTERSECT	inter;
	float		n_dot_r;

	inter = new_intersect();
	inter.normal = vec3_cross(vec3_sub(t.point[1], t.point[0]), vec3_sub(t.point[2], t.point[0]));
	n_dot_r = vec3_dot(inter.normal, r.direction);
	if (fabs(n_dot_r) < FLOAT_ZERO
	|| (inter.distance[0] = inter.distance[1] = (vec3_dot(inter.normal, r.origin) + vec3_dot(inter.normal, t.point[0])) / n_dot_r) < 0)
		return (inter);
	t.position = intersect_compute_position(r, inter.distance[0]);
	if (vec3_dot(inter.normal, vec3_cross(vec3_sub(t.point[1], t.point[0]), vec3_sub(t.position, t.point[0]))) < 0
	|| vec3_dot(inter.normal, vec3_cross(vec3_sub(t.point[2], t.point[1]), vec3_sub(t.position, t.point[1]))) < 0
	|| vec3_dot(inter.normal, vec3_cross(vec3_sub(t.point[0], t.point[2]), vec3_sub(t.position, t.point[2]))) < 0)
		return (inter);
	inter.intersects = 1;
	return (inter);
}

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
	if (inter.distance[0] <= 0)
	{
		inter.distance[0] = inter.distance[1];
		inter.position = intersect_compute_position(r, inter.distance[0]);
		inter.normal = vec3_negate(sphere_normal(inter.position, s));
	}
	else
	{
		inter.position = intersect_compute_position(r, inter.distance[0]);
		inter.normal = sphere_normal(inter.position, s);
	}
	return (inter);
}

/*
** TODO find a better way to intersect a cylinder
** (Other than creating a "sphere" along the cylinder's axis...)
*/

INTERSECT intersect_cylinder(t_primitive cp, t_ray r)
{
	t_vec3		v[6];
	INTERSECT	i;

	i = new_intersect();
	v[0] = vec3_proj(cp.position, cp.direction);
	v[1] = vec3_sub(cp.position, v[0]);
	v[2] = vec3_proj(r.origin, cp.direction);
	v[3] = vec3_proj(r.direction, cp.direction);
	v[4] = vec3_sub(r.direction, v[3]);
	v[5] = vec3_sub(vec3_sub(r.origin, v[2]), v[1]);
	if (!(i.intersects = solve_quadratic(vec3_dot(v[4], v[4]),
		vec3_dot(v[5], v[4]) * 2.0, vec3_dot(v[5], v[5]) - (cp.radius2), i.distance)))
		return (i);
	if (cp.size > 0)
	{
		i.distance[0] *= (vec3_length(vec3_sub(vec3_add(v[2], vec3_scale(v[3], i.distance[0])), v[0])) <= cp.size / 2.f);
		i.distance[1] *= (vec3_length(vec3_sub(vec3_add(v[2], vec3_scale(v[3], i.distance[1])), v[0])) <= cp.size / 2.f);
	}
	if (!(i.intersects = intersect_test(i.distance)))
		return (i);
	if (i.distance[0] <= 0)
	{
		i.position = intersect_compute_position(r, (i.distance[0] = i.distance[1]));
		i.normal = vec3_negate(cylinder_normal(i.position, cp));
	}
	else
	{
		i.position = intersect_compute_position(r, i.distance[0]);
		i.normal = cylinder_normal(i.position, cp);
	}
	return (i);
}

INTERSECT	intersect_disc(t_primitive d, t_ray r)
{
	INTERSECT	inter;

	inter = intersect_plane(d, r);
	inter.intersects = inter.intersects
	&& vec3_distance(inter.position, d.position) <= d.radius;
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
	if (!float_equal(denom, 0.f))
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
