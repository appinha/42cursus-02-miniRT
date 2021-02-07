/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:48 by appinha           #+#    #+#             */
/*   Updated: 2021/02/07 09:23:35 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vectors.h"

bool	hit_pl(t_ray *ray, t_elem *elem)
{
	double	dist;
	double	den;

	den = v_dot(v_norm(ray->normal), elem->normal);
	if (!den)
		return (false);
	dist = v_dot(v_sub(elem->point, ray->point), elem->normal) / den;
	if (ray->hit.dist > dist && dist > EPSILON)
	{
		ray->hit.dist = dist;
		ray->hit.point = ray_at(*ray);
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
