/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:48 by appinha           #+#    #+#             */
/*   Updated: 2021/02/06 15:23:46 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vectors.h"

bool	hit_pl(t_ray *ray, t_elem *elem)
{
	double	dot;
	double	den;

	den = v_dot(v_norm(ray->normal), elem->normal);
	if (!den)
		return (false);
	dot = v_dot(v_sub(elem->coord, ray->coord), elem->normal) / den;
	if (ray->hit.dot > dot && dot > EPSILON)
	{
		ray->hit.dot = dot;
		ray->hit.coord = ray_at(*ray);
		if (v_dot(ray->normal, elem->normal) > 0)
			elem->normal = v_scale(elem->normal, -1);
		ray->hit.normal = elem->normal;
		ray->hit.obj_type = PLANE;
		ray->hit.obj = elem;
		ray->hit.colour = elem->colour;
		return (true);
	}
	return (false);
}
