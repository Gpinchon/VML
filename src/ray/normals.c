/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_normals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:15:01 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 20:19:12 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_vec3	cylinder_normal(t_vec3 position, t_primitive p)
{
	t_vec3	co;
	t_vec3	vpersp;

	co = vec3_sub(position, p.position);
	vpersp = vec3_sub(co, vec3_proj(co, p.direction));
	return (vec3_normalize(vec3_add(vpersp, vec3_normalize(vpersp))));
}

t_vec3	sphere_normal(t_vec3 position, t_primitive p)
{
	return (vec3_normalize((t_vec3){
				(position.x - p.position.x) / p.radius,
				(position.y - p.position.y) / p.radius,
				(position.z - p.position.z) / p.radius
			}));
}

t_vec3	plane_normal(t_vec3 position, t_primitive p)
{
	return (vec3_normalize(p.direction));
	position = (t_vec3){position.x, position.y, position.z};
}

t_vec3	cone_normal(t_vec3 position, t_primitive p)
{
	t_vec3	co;
	t_vec3	vpersp;

	co = vec3_sub(position, p.position);
	vpersp = vec3_sub(co, vec3_proj(co,
		vec3_normalize(vec3_scale(p.direction, p.radius))));
	return (vec3_normalize(vec3_add(vpersp, vec3_normalize(vpersp))));
}
