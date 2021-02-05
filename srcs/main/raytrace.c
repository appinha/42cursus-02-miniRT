/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:30:41 by appinha           #+#    #+#             */
/*   Updated: 2021/02/05 10:31:39 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vectors.h"

t_coord			ray_at(t_ray ray)
{
	return (v_add(ray.coord, v_scale(ray.normal, ray.hit.dot)));
}

static bool		intersect(t_rt *rt, t_ray *ray)
{
	bool	hit;

	ray->hit.dot = INFINITY;
	hit = false;
	if (rt->scene.pl != 0)
		hit = hit_pl(ray, rt->scene.pl);
	return (hit);
}

static bool		in_shadow(t_rt *rt, t_hit hit, t_elem *light)
{
	t_ray	shadow;

	shadow.coord = v_add(hit.coord, v_scale(hit.normal, EPSILON));
	shadow.normal = v_norm(v_sub(light->coord, shadow.coord));
	shadow.hit.obj = hit.obj;
	return (intersect(rt, &shadow));
}

int				raytrace(t_rt *rt, t_ray *ray)
{
	int		amb_li_colour;
	int		colour;
	t_elem	*light;
	bool	vis;

	if (intersect(rt, ray) == false)
		return (0);
	amb_li_colour = c_scale(rt->scene.amb_li.colour, rt->scene.amb_li.ratio);
	colour = c_prod(ray->hit.colour, amb_li_colour);
	light = rt->scene.light;
	while (light)
	{
		vis = !in_shadow(rt, ray->hit, light);
		colour = c_add(colour, vis * c_comp(light, ray->hit));
		light = light->next;
	}
	return (colour);
}
