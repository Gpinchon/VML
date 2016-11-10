/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmult.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:35:50 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/10 15:44:19 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

MAT2	mat2_fmult(MAT2 m, float f)
{
	int i;

	i = 0;
	while (i < 4)
	{
		m.m[i] *= f;
		i++;
	}
	return (m);
}

MAT3	mat3_fmult(MAT3 m, float f)
{
	int i;

	i = 0;
	while (i < 9)
	{
		m.m[i] *= f;
		i++;
	}
	return (m);
}

MAT4	mat4_fmult(MAT4 m, float f)
{
	int i;

	i = 0;
	while (i < 16)
	{
		m.m[i] *= f;
		i++;
	}
	return (m);
}
