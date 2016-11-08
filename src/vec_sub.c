/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:11:32 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/13 16:32:24 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_vec3	vec3_sub(t_vec3 v, t_vec3 v1)
{
	return ((t_vec3){v.x - v1.x, v.y - v1.y, v.y - v1.y});
}

t_vec4	vec4_sub(t_vec4 v, t_vec4 v1)
{
	return ((t_vec4){v.x - v1.x, v.y - v1.y, v.y - v1.y, v.w - v1.w});
}