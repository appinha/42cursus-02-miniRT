/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:48 by appinha           #+#    #+#             */
/*   Updated: 2021/02/07 22:08:28 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vectors.h"

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
		ray->hit.obj_type = PLANE;
		ray->hit.obj = elem;
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
	if (elem->obj_type == SQUARE)
		aux_pl.point = elem->point;
	if (elem->obj_type == TRIANGLE)
		aux_pl.point = elem->vertex[0];
	aux_pl.normal = elem->normal;
	aux_pl.colour = elem->colour;
	ray_cpy.p_ori = ray->p_ori;
	ray_cpy.v_dir = ray->v_dir;
	ray_cpy.hit.time = ray->hit.time;
	if (hit_pl(&ray_cpy, &aux_pl) &&
		point_is_inside(ray_cpy.hit, elem->vertex, elem->qtd_vertex))
	{
		*ray = ray_cpy;
		ray->hit.obj = elem;
		ret = true;
	}
	return (ret);
}

static void	sp_bhaskara(t_ray ray, t_elem sp, float *res)
{
	t_coord		sphere_to_ray;
	float		a;
	float		b;
	float		c;
	float		discriminant;

	sphere_to_ray = v_sub(ray.p_ori, sp.point);
	a = v_dot(ray.v_dir, ray.v_dir);
	b = 2 * v_dot(ray.v_dir, sphere_to_ray);
	c = v_dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = pow((b), 2) - 4 * a * c;
	res[0] = (-b - sqrt(discriminant)) / (2 * a);
	res[1] = (-b + sqrt(discriminant)) / (2 * a);
}

bool		hit_sp(t_ray *ray, t_elem *elem)
{
	float		time[2];
	short int	i;

	sp_bhaskara(*ray, *elem, time);
	i = 0;
	while (i < 2)
	{
		if (ray->hit.time > time[i] && time[i] > 0)
		{
			ray->hit.time = time[i];
			ray->hit.point = get_hit_point(*ray);
			ray->hit.normal = v_norm(v_sub(ray->hit.point, elem->point));
			ray->hit.colour = elem->colour;
			ray->hit.obj_type = SPHERE;
			return (true);
		}
		i++;
	}
	return (false);
}
