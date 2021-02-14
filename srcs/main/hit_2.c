/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:37:51 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/14 19:35:24 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool		hit_pl(t_ray *ray, t_elem *elem)
{
	double	time;
	double	den;

	den = v_dot(v_norm(ray->v_dir), elem->normal);
	if (!den)
		return (false);
	time = v_dot(v_sub(elem->point, ray->p_ori), elem->normal) / den;
	if (ray->hit.time > time && time > EPSILON)
	{
		ray->hit.time = time;
		ray->hit.point = get_hit_point(*ray);
		if (v_dot(ray->v_dir, elem->normal) > 0)
			elem->normal = v_scale(elem->normal, -1);
		ray->hit.normal = elem->normal;
		ray->hit.colour = elem->colour;
		return (true);
	}
	return (false);
}

static bool	point_is_inside(t_hit hit, t_coord *vertex, short int qtd_vertex)
{
	bool	ret;
	float	det[qtd_vertex];
	t_coord	det_cross;
	int		i;

	ret = true;
	i = 0;
	while (i < qtd_vertex)
	{
		if (i == (qtd_vertex - 1))
			det_cross = v_cross(v_sub(vertex[i], vertex[0]),
								v_sub(hit.point, vertex[0]));
		else
			det_cross = v_cross(v_sub(vertex[i], vertex[i + 1]),
								v_sub(hit.point, vertex[i + 1]));
		det[i] = v_dot(det_cross, hit.normal);
		if (i > 0)
			ret &= (det[i - 1] >= 0) ^ (det[i] < 0);
		i++;
	}
	return (ret);
}

bool		hit_polyg(t_ray *ray, t_elem *elem)
{
	bool	ret;
	t_ray	ray_cpy;
	t_elem	aux_pl;

	ret = false;
	if (elem->qtd_vertex == 3)
		aux_pl.point = elem->vertex[0];
	if (elem->qtd_vertex == 4)
		aux_pl.point = elem->point;
	aux_pl.normal = elem->normal;
	aux_pl.colour = elem->colour;
	ray_cpy.p_ori = ray->p_ori;
	ray_cpy.v_dir = ray->v_dir;
	ray_cpy.hit.time = ray->hit.time;
	if (hit_pl(&ray_cpy, &aux_pl) &&
		point_is_inside(ray_cpy.hit, elem->vertex, elem->qtd_vertex))
	{
		*ray = ray_cpy;
		ret = true;
	}
	return (ret);
}
