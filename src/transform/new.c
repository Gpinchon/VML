/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:11:40 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/23 21:59:38 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vml.h>
#include <string.h>

TRANSFORM	new_transform(VEC3 position, VEC3 rotation, VEC3 scaling, VEC3 up)
{
	TRANSFORM	t;

	memset(&t, 0, sizeof(TRANSFORM));
	t.position = position;
	t.rotation = rotation;
	t.scaling = scaling;
	t.up = up;
	return (t);
}
