/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 19:38:09 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 23:43:11 by gpinchon         ###   ########.fr       */
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

t_mat4		mat4_transpose(const t_mat4 m)
{
	int		x;
	int		z;
	t_mat4	out;

	z = 0;
	while (z < 4)
	{
		x = 0;
		while (x < 4)
		{
			out.m[(z * 4) + x] = m.m[(x * 4) + z];
			x++;
		}
		z++;
	}
	return (out);
}
