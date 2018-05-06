/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 00:54:34 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/23 22:55:42 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

 t_mat2		mat2_transpose(const t_mat2 m)
{
	return ((t_mat2){.m = {
		m.m[0], m.m[2],
		m.m[1], m.m[3]
	}});
}

 t_mat3		mat3_transpose(const t_mat3 m)
{
	return ((t_mat3){.m = {
		m.m[0], m.m[3], m.m[6],
		m.m[1], m.m[4], m.m[7],
		m.m[2], m.m[5], m.m[8]
	}});
}

 t_mat4		mat4_transpose(const t_mat4 m)
{
	return ((t_mat4){.m = {
		m.m[0], m.m[4], m.m[8], m.m[12],
		m.m[1], m.m[5], m.m[9], m.m[13],
		m.m[2], m.m[6], m.m[10], m.m[14],
		m.m[3], m.m[7], m.m[11], m.m[15]
	}});
}
