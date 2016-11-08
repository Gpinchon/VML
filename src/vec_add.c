/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 19:26:03 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/08 16:30:18 by gpinchon         ###   ########.fr       */
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
