/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:30:41 by appinha           #+#    #+#             */
/*   Updated: 2021/02/14 19:35:47 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray			gen_ray(t_cam *cam, float x, float y)
{
	t_ray	ray;

	ray.p_ori = cam->point;
	ray.v_dir = v_add(v_scale(cam->hor, x), v_scale(cam->ver, y));
	ray.v_dir = v_add(ray.v_dir, cam->llc);
	ray.v_dir = v_norm(v_sub(ray.v_dir, ray.p_ori));
	ft_bzero(&ray.hit, 0);
	return (ray);
}

static void		iter_lst_objs(t_ray *ray, t_elem *elem, bool *ret,
								bool (*ft)(t_ray *ray, t_elem *elem))
{
	while (elem)
	{
		*ret |= (*ft)(ray, elem);
		elem = elem->next;
	}
}

static bool		intersect(t_rt *rt, t_ray *ray)
{
	bool				ret;

	ray->hit.time = INFINITY;
	ret = false;
	if (rt->scene.sp != 0)
		iter_lst_objs(ray, rt->scene.sp, &ret, *hit_sp);
	if (rt->scene.pl != 0)
		iter_lst_objs(ray, rt->scene.pl, &ret, *hit_pl);
	if (rt->scene.sq != 0)
		iter_lst_objs(ray, rt->scene.sq, &ret, *hit_polyg);
	if (rt->scene.tr != 0)
		iter_lst_objs(ray, rt->scene.tr, &ret, *hit_polyg);
	if (rt->scene.cy != 0)
		iter_lst_objs(ray, rt->scene.cy, &ret, *hit_cy);
	return (ret);
}

static bool		in_shadow(t_rt *rt, t_hit hit, t_elem *light)
{
	t_ray	shadow;

	shadow.p_ori = v_add(hit.point, v_scale(hit.normal, EPSILON));
	shadow.v_dir = v_norm(v_sub(light->point, shadow.p_ori));
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
