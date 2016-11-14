/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:35:23 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/14 18:36:26 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	clamp(float nbr, float min, float max)
{
	if (nbr >= max)
		return (max);
	else if (nbr <= min)
		return (min);
	else
		return (nbr);
}

float	cycle(float nbr, float min, float max)
{
	if (nbr > max)
		return (min);
	else if (nbr < min)
		return (max);
	else
		return (nbr);
}

float	step(float a, float x)
{
	return (x >= a);
}
