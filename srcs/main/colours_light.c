/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:01:45 by appinha           #+#    #+#             */
/*   Updated: 2021/02/05 10:02:32 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vectors.h"

static float	light_brightness(t_elem *light, t_hit hit)
{
	t_coord		light_normal;
	float		gain;
	float		r2;

	light_normal = v_sub(light->coord, hit.coord);
	r2 = v_len_sqr(light_normal);
	gain = v_dot(v_norm(light_normal), hit.normal);
	if (gain <= 0)
		return (0);
	return ((light->ratio * gain * ALBEDO) / (4.0 * M_PI * r2));
}

int				c_comp(t_elem *light, t_hit hit)
{
	int		colour;

	colour = 0;
	colour = c_add(colour, c_scale(hit.colour, light_brightness(light, hit)));
	colour = c_prod(colour, light->colour);
	return (colour);
}
