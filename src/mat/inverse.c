/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 19:38:09 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/10 01:48:43 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

static void	m4_inverse1(t_mat4 *t, const t_mat4 m)
{
	t->m[0] = m.m[5] * m.m[10] * m.m[15] - m.m[5] * m.m[11] * m.m[14] -
		m.m[9] * m.m[6] * m.m[15] + m.m[9] * m.m[7] * m.m[14] +
		m.m[13] * m.m[6] * m.m[11] - m.m[13] * m.m[7] * m.m[10];
	t->m[4] = -m.m[4] * m.m[10] * m.m[15] + m.m[4] * m.m[11] * m.m[14] +
		m.m[8] * m.m[6] * m.m[15] - m.m[8] * m.m[7] * m.m[14] -
		m.m[12] * m.m[6] * m.m[11] + m.m[12] * m.m[7] * m.m[10];
	t->m[8] = m.m[4] * m.m[9] * m.m[15] - m.m[4] * m.m[11] * m.m[13] -
		m.m[8] * m.m[5] * m.m[15] + m.m[8] * m.m[7] * m.m[13] +
		m.m[12] * m.m[5] * m.m[11] - m.m[12] * m.m[7] * m.m[9];
	t->m[12] = -m.m[4] * m.m[9] * m.m[14] + m.m[4] * m.m[10] * m.m[13] +
		m.m[8] * m.m[5] * m.m[14] - m.m[8] * m.m[6] * m.m[13] -
		m.m[12] * m.m[5] * m.m[10] + m.m[12] * m.m[6] * m.m[9];
	t->m[1] = -m.m[1] * m.m[10] * m.m[15] + m.m[1] * m.m[11] * m.m[14] +
		m.m[9] * m.m[2] * m.m[15] - m.m[9] * m.m[3] * m.m[14] -
		m.m[13] * m.m[2] * m.m[11] + m.m[13] * m.m[3] * m.m[10];
	t->m[5] = m.m[0] * m.m[10] * m.m[15] - m.m[0] * m.m[11] * m.m[14] -
		m.m[8] * m.m[2] * m.m[15] + m.m[8] * m.m[3] * m.m[14] +
		m.m[12] * m.m[2] * m.m[11] - m.m[12] * m.m[3] * m.m[10];
	t->m[9] = -m.m[0] * m.m[9] * m.m[15] + m.m[0] * m.m[11] * m.m[13] +
		m.m[8] * m.m[1] * m.m[15] - m.m[8] * m.m[3] * m.m[13] -
		m.m[12] * m.m[1] * m.m[11] + m.m[12] * m.m[3] * m.m[9];
	t->m[13] = m.m[0] * m.m[9] * m.m[14] - m.m[0] * m.m[10] * m.m[13] -
		m.m[8] * m.m[1] * m.m[14] + m.m[8] * m.m[2] * m.m[13] +
		m.m[12] * m.m[1] * m.m[10] - m.m[12] * m.m[2] * m.m[9];
}

static void	m4_inverse2(t_mat4 *t, const t_mat4 m)
{
	t->m[2] = m.m[1] * m.m[6] * m.m[15] - m.m[1] * m.m[7] * m.m[14] -
		m.m[5] * m.m[2] * m.m[15] + m.m[5] * m.m[3] * m.m[14] +
		m.m[13] * m.m[2] * m.m[7] - m.m[13] * m.m[3] * m.m[6];
	t->m[6] = -m.m[0] * m.m[6] * m.m[15] + m.m[0] * m.m[7] * m.m[14] +
		m.m[4] * m.m[2] * m.m[15] - m.m[4] * m.m[3] * m.m[14] -
		m.m[12] * m.m[2] * m.m[7] + m.m[12] * m.m[3] * m.m[6];
	t->m[10] = m.m[0] * m.m[5] * m.m[15] - m.m[0] * m.m[7] * m.m[13] -
		m.m[4] * m.m[1] * m.m[15] + m.m[4] * m.m[3] * m.m[13] +
		m.m[12] * m.m[1] * m.m[7] - m.m[12] * m.m[3] * m.m[5];
	t->m[14] = -m.m[0] * m.m[5] * m.m[14] + m.m[0] * m.m[6] * m.m[13] +
		m.m[4] * m.m[1] * m.m[14] - m.m[4] * m.m[2] * m.m[13] -
		m.m[12] * m.m[1] * m.m[6] + m.m[12] * m.m[2] * m.m[5];
	t->m[3] = -m.m[1] * m.m[6] * m.m[11] + m.m[1] * m.m[7] * m.m[10] +
		m.m[5] * m.m[2] * m.m[11] - m.m[5] * m.m[3] * m.m[10] -
		m.m[9] * m.m[2] * m.m[7] + m.m[9] * m.m[3] * m.m[6];
	t->m[7] = m.m[0] * m.m[6] * m.m[11] - m.m[0] * m.m[7] * m.m[10] -
		m.m[4] * m.m[2] * m.m[11] + m.m[4] * m.m[3] * m.m[10] +
		m.m[8] * m.m[2] * m.m[7] - m.m[8] * m.m[3] * m.m[6];
	t->m[11] = -m.m[0] * m.m[5] * m.m[11] + m.m[0] * m.m[7] * m.m[9] +
		m.m[4] * m.m[1] * m.m[11] - m.m[4] * m.m[3] * m.m[9] -
		m.m[8] * m.m[1] * m.m[7] + m.m[8] * m.m[3] * m.m[5];
	t->m[15] = m.m[0] * m.m[5] * m.m[10] - m.m[0] * m.m[6] * m.m[9] -
		m.m[4] * m.m[1] * m.m[10] + m.m[4] * m.m[2] * m.m[9] +
		m.m[8] * m.m[1] * m.m[6] - m.m[8] * m.m[2] * m.m[5];
}

/*
** m[0] m[1] m[2]
** m[3] m[4] m[5]
** m[6] m[7] m[8]
** 
** m[4] m[5]	m[3] m[5]	m[3] m[4]
** m[7] m[8]	m[6] m[8]	m[6] m[7]
** 
** m[1] m[2]	m[0] m[2]	m[0] m[1]
** m[7] m[8]	m[6] m[8]	m[6] m[7]
**
** m[1] m[2]	m[0] m[2]	m[0] m[1]
** m[4] m[5]	m[3] m[5]	m[3] m[4]
*/

/*t_mat3		mat3_inverse(const t_mat4 m)
{
	t_mat3	minors;
	t_mat3	cofactor;
	float	det[9];
	float	determinant;

	det[0] = mat2_determinant(new_mat2(
		{m.m[4], m.m[5]},
		{m.m[7], m.m[8]}));
	det[1] = mat2_determinant(new_mat2(
		{m.m[3], m.m[5]},
		{m.m[6], m.m[8]}));
	det[2] = mat2_determinant(new_mat2(
		{m.m[3], m.m[4]},
		{m.m[6], m.m[7]}));
	det[3] = mat2_determinant(new_mat2(
		{m.m[1], m.m[2]},
		{m.m[7], m.m[8]}));
	det[4] = mat2_determinant(new_mat2(
		{m.m[0], m.m[2]},
		{m.m[6], m.m[8]}));
	det[5] = mat2_determinant(new_mat2(
		{m.m[0], m.m[1]},
		{m.m[6], m.m[7]}));
	det[6] = mat2_determinant(new_mat2(
		{m.m[1], m.m[2]},
		{m.m[4], m.m[5]}));
	det[7] = mat2_determinant(new_mat2(
		{m.m[0], m.m[2]},
		{m.m[3], m.m[5]}));
	det[8] = mat2_determinant(new_mat2(
		{m.m[0], m.m[1]},
		{m.m[3], m.m[4]}));
	minors = new_mat3(
		{det[0], det[1], det[2]},
		{det[3], det[4], det[5]},
		{det[6], det[7], det[8]});
	cofactor = new_mat3(
		{minors.m[0], -minors.m[1], minors.m[2]},
		{-minors.m[3], minors.m[4], -minors.m[5]},
		{minors.m[6], -minors.m[7], minors.m[8]});
	determinant = 1.0 / mat3_determinant(m);
	1.0 / determinant * 
}*/

t_mat4		mat4_inverse(const t_mat4 m)
{
	t_mat4	t;
	float	det;
	int		j;

	m4_inverse1(&t, m);
	m4_inverse2(&t, m);
	det = m.m[0] * t.m[0] + m.m[1] * t.m[4] +
		m.m[2] * t.m[8] + m.m[3] * t.m[12];
	if (det == 0)
		return (mat4_zero());
	det = 1.0 / det;
	j = 0;
	while (j < 16)
	{
		t.m[j] = t.m[j] * det;
		j++;
	}
	return (t);
}
