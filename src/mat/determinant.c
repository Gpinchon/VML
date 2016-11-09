/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:47:49 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/10 00:14:51 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

float	mat2_determinant(t_mat2 m)
{
	return (m.m[0] * m.m[3] - m.m[2] * m.m[1]);
}

/*
** m[0] m[1] m[2] m[0] m[1]
** m[3] m[4] m[5] m[3] m[4]
** m[6] m[7] m[8] m[6] m[7]
*/

float	mat3_determinant(t_mat3 m)
{
	return (
	m.m[0] * m.m[4] * m.m[8] +
	m.m[1] * m.m[5] * m.m[6] +
	m.m[2] * m.m[3] * m.m[7] -
	m.m[2] * m.m[4] * m.m[6] -
	m.m[0] * m.m[5] * m.m[7] -
	m.m[1] * m.m[3] * m.m[8]);
}

float	mat4_determinant(t_mat4 m)
{
	return (
	m.m[3] * m.m[6] * m.m[9] * m.m[12] - m.m[2] * m.m[7] * m.m[9] * m.m[12] -
	m.m[3] * m.m[5] * m.m[10] * m.m[12] + m.m[1] * m.m[7] * m.m[10] * m.m[12] +
	m.m[2] * m.m[5] * m.m[11] * m.m[12] - m.m[1] * m.m[6] * m.m[11] * m.m[12] -
	m.m[3] * m.m[6] * m.m[8] * m.m[13] + m.m[2] * m.m[7] * m.m[8] * m.m[13] +
	m.m[3] * m.m[4] * m.m[10] * m.m[13] - m.m[0] * m.m[7] * m.m[10] * m.m[13] -
	m.m[2] * m.m[4] * m.m[11] * m.m[13] + m.m[0] * m.m[6] * m.m[11] * m.m[13]+
	m.m[3] * m.m[5] * m.m[8] * m.m[14] - m.m[1] * m.m[7] * m.m[8] * m.m[14] -
	m.m[3] * m.m[4] * m.m[9] * m.m[14] + m.m[0] * m.m[7] * m.m[9] * m.m[14] +
	m.m[1] * m.m[4] * m.m[11] * m.m[14]-m.m[0] * m.m[5] * m.m[11] * m.m[14] -
	m.m[2] * m.m[5] * m.m[8] * m.m[15] + m.m[1] * m.m[6] * m.m[8] * m.m[15] +
	m.m[2] * m.m[4] * m.m[9] * m.m[15] - m.m[0] * m.m[6] * m.m[9] * m.m[15] -
	m.m[1] * m.m[4] * m.m[10] * m.m[15] + m.m[0] * m.m[5] * m.m[10] * m.m[15]);
}