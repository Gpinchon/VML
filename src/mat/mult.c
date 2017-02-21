/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 18:42:13 by gpinchon          #+#    #+#             */
/*   Updated: 2017/02/21 20:10:35 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_mat2	mat2_mult_mat2(t_mat2 m, t_mat2 m1)
{
	return ((t_mat2){.m = {
		m.m[0] * m1.m[0] + m.m[1] * m1.m[2],
		m.m[0] * m1.m[1] + m.m[1] * m1.m[3],
		m.m[2] * m1.m[0] + m.m[3] * m1.m[2],
		m.m[2] * m1.m[1] + m.m[3] * m1.m[3]
	}});
}

t_mat3	mat3_mult_mat3(t_mat3 m, t_mat3 m1)
{
	return ((t_mat3){.m = {
		m.m[0] * m1.m[0] + m.m[1] * m1.m[3] + m.m[2] * m1.m[6],
		m.m[0] * m1.m[1] + m.m[1] * m1.m[4] + m.m[2] * m1.m[7],
		m.m[0] * m1.m[2] + m.m[1] * m1.m[5] + m.m[2] * m1.m[8],
		m.m[3] * m1.m[0] + m.m[4] * m1.m[3] + m.m[5] * m1.m[6],
		m.m[3] * m1.m[1] + m.m[4] * m1.m[4] + m.m[5] * m1.m[7],
		m.m[3] * m1.m[2] + m.m[4] * m1.m[5] + m.m[5] * m1.m[8],
		m.m[6] * m1.m[0] + m.m[7] * m1.m[3] + m.m[8] * m1.m[6],
		m.m[6] * m1.m[1] + m.m[7] * m1.m[4] + m.m[8] * m1.m[7],
		m.m[6] * m1.m[2] + m.m[7] * m1.m[5] + m.m[8] * m1.m[8]
	}});
}

t_mat4	mat4_mult_mat4(t_mat4 m, t_mat4 m1)
{
	float	*a;
	float	*b;

	a = m.m;
	b = m1.m;
	return ((t_mat4){.m = {
		a[0] * b[0] + a[4] * b[1] + a[8] * b[2] + a[12] * b[3],
		a[1] * b[0] + a[5] * b[1] + a[9] * b[2] + a[13] * b[3],
		a[2] * b[0] + a[6] * b[1] + a[10] * b[2] + a[14] * b[3],
		a[3] * b[0] + a[7] * b[1] + a[11] * b[2] + a[15] * b[3],
		a[0] * b[4] + a[4] * b[5] + a[8] * b[6] + a[12] * b[7],
		a[1] * b[4] + a[5] * b[5] + a[9] * b[6] + a[13] * b[7],
		a[2] * b[4] + a[6] * b[5] + a[10] * b[6] + a[14] * b[7],
		a[3] * b[4] + a[7] * b[5] + a[11] * b[6] + a[15] * b[7],
		a[0] * b[8] + a[4] * b[9] + a[8] * b[10] + a[12] * b[11],
		a[1] * b[8] + a[5] * b[9] + a[9] * b[10] + a[13] * b[11],
		a[2] * b[8] + a[6] * b[9] + a[10] * b[10] + a[14] * b[11],
		a[3] * b[8] + a[7] * b[9] + a[11] * b[10] + a[15] * b[11],
		a[0] * b[12] + a[4] * b[13] + a[8] * b[14] + a[12] * b[15],
		a[1] * b[12] + a[5] * b[13] + a[9] * b[14] + a[13] * b[15],
		a[2] * b[12] + a[6] * b[13] + a[10] * b[14] + a[14] * b[15],
		a[3] * b[12] + a[7] * b[13] + a[11] * b[14] + a[15] * b[15]
	}});
}
