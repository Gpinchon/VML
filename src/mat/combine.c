/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:35:48 by gpinchon          #+#    #+#             */
/*   Updated: 2017/02/21 19:39:57 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_mat2	mat2_combine(t_mat2 m, t_mat2 m1, t_mat2 m2)
{
	return (mat2_mult_mat2(mat2_mult_mat2(m, m1), m2));
}

t_mat3	mat3_combine(t_mat3 m, t_mat3 m1, t_mat3 m2)
{
	return (mat3_mult_mat3(mat3_mult_mat3(m, m1), m2));
}

t_mat4	mat4_combine(t_mat4 m, t_mat4 m1, t_mat4 m2)
{
	return (mat4_mult_mat4(mat4_mult_mat4(m, m1), m2));
}
