/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:15:01 by gpinchon          #+#    #+#             */
/*   Updated: 2016/12/02 19:47:21 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_vec3	cylinder_normal(t_vec3 position, t_primitive p)
{
	t_vec3	co;
	t_vec3	vpersp;

	co = vec3_sub(position, p.data.cylinder.position);
	vpersp = vec3_sub(co, vec3_proj(co, p.data.cylinder.direction));
	return (vec3_normalize(vec3_add(vpersp, vec3_normalize(vpersp))));
}

t_vec3	sphere_normal(t_vec3 position, t_primitive p)
{
	return (vec3_normalize((t_vec3){
				(position.x - p.data.sphere.position.x) / p.data.sphere.radius,
				(position.y - p.data.sphere.position.y) / p.data.sphere.radius,
				(position.z - p.data.sphere.position.z) / p.data.sphere.radius
			}));
}

t_vec3	plane_normal(t_vec3 position, t_primitive p)
{
	return (vec3_normalize(p.data.plane.direction));
	position = (t_vec3){position.x, position.y, position.z};
}

t_vec3	cone_normal(t_vec3 position, t_primitive p)
{
	t_vec3	co;
	t_vec3	vpersp;

	co = vec3_sub(position, p.data.cone.position);
	vpersp = vec3_sub(co, vec3_proj(co,
		vec3_normalize(vec3_scale(p.data.cone.direction, p.data.cone.radius))));
	return (vec3_normalize(vec3_add(vpersp, vec3_normalize(vpersp))));
}
