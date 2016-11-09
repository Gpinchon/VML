/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:06:23 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/09 20:07:40 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>

t_vec3	vec3_proj(t_vec3 v, t_vec3 v1)
{
	return (vec3_scale(v1, vec3_dot(v, v1) / vec3_dot(v1, v1)));
}

t_vec4	vec4_proj(t_vec4 v, t_vec4 v1)
{
	return (vec4_scale(v1, vec4_dot(v, v1) / vec4_dot(v1, v1)));
}
