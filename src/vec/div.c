/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:04:06 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 20:05:43 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_vec3	vec3_div(t_vec3 v, t_vec3 v1)
{
	return ((t_vec3){
		v.x / v1.x,
		v.y / v1.y,
		v.z / v1.z
	});
}

t_vec4	vec4_div(t_vec4 v, t_vec4 v1)
{
	return ((t_vec4){
		v.x / v1.x,
		v.y / v1.y,
		v.z / v1.z,
		v.w / v1.w
	});
}

t_vec3	vec3_fdiv(t_vec3 v, float d)
{
	return ((t_vec3){
		v.x / d,
		v.y / d,
		v.z / d
	});
}

t_vec4	vec4_fdiv(t_vec4 v, float d)
{
	return ((t_vec4){
		v.x / d,
		v.y / d,
		v.z / d,
		v.w / d
	});
}
