/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjugate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 01:00:03 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/10 01:12:46 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

/*
** returns the cofactor matrix
*/

t_mat3	mat3_adjugate(const t_mat3 m)
{
	return (mat3_transpose(mat3_cofactor(m)));
}
