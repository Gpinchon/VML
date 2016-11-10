/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_equal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:03:47 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/10 15:04:02 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

char	float_equal(float a, float b)
{
	return(fabs(a - b) <= FLOAT_ZERO);
}
