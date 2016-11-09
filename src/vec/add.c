/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 19:26:03 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 20:02:39 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_vec3	vec3_add(t_vec3 v, t_vec3 v1)
{
	return ((t_vec3){
		v.x + v1.x,
		v.y + v1.y,
		v.z + v1.z
	});
}

t_vec4	vec4_add(t_vec4 v, t_vec4 v1)
{
	return ((t_vec4){
		v.x + v1.x,
		v.y + v1.y,
		v.z + v1.z,
		v.w + v1.w
	});
}

t_vec3	vec3_fadd(t_vec3 v, float d)
{
	return ((t_vec3){
		v.x + d,
		v.y + d,
		v.z + d
	});
}

t_vec4	vec4_fadd(t_vec4 v, float d)
{
	return ((t_vec4){
		v.x + d,
		v.y + d,
		v.z + d,
		v.w + d
	});
}
