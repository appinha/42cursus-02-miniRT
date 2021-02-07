/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:48 by appinha           #+#    #+#             */
/*   Updated: 2021/02/07 18:41:38 by apuchill         ###   ########.fr       */
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
