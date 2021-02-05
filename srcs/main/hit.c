/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:48 by appinha           #+#    #+#             */
/*   Updated: 2021/02/05 10:34:41 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vectors.h"

bool	hit_pl(t_ray *ray, t_elem *pl)
{
	double	dot;
	double	den;

	den = v_dot(v_norm(ray->normal), pl->normal);
	if (!den)
		return (false);
	dot = v_dot(v_sub(pl->coord, ray->coord), pl->normal) / den;
	if (ray->hit.dot > dot && dot > EPSILON)
	{
		ray->hit.dot = dot;
		ray->hit.coord = ray_at(*ray);
		if (v_dot(ray->normal, pl->normal) > 0)
			pl->normal = v_scale(pl->normal, -1);
		ray->hit.normal = pl->normal;
		ray->hit.obj_type = PLANE;
		ray->hit.obj = pl;
		ray->hit.colour = pl->colour;
		return (true);
	}
	return (false);
}
