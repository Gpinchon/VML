/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:59:42 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/08 16:25:53 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_mat4			new_m4(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d)
{
	return ((t_mat4){.m = {
		a.x, a.y, a.z, a.w,
		b.x, b.y, b.z, b.w,
		c.x, c.y, c.z, c.w,
		d.x, d.y, d.z, d.w,
	}});
}

t_mat3			new_m3(t_vec3 a, t_vec3 b, t_vec3 c)
{
	return ((t_mat3){.m = {
		a.x, a.y, a.z,
		b.x, b.y, b.z,
		c.x, c.y, c.z
	}});
}