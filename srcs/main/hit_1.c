/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:48 by appinha           #+#    #+#             */
/*   Updated: 2021/02/08 09:18:13 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vectors.h"

t_coord			get_hit_point(t_ray ray)
{
	return (v_add(ray.p_ori, v_scale(ray.v_dir, ray.hit.time)));
}

static void	sp_bhaskara(t_ray ray, t_elem sp, float *res)
{
	t_coord		sphere_to_ray;
	float		a;
	float		b;
	float		c;
	float		sqrt_discriminant;

	sphere_to_ray = v_sub(ray.p_ori, sp.point);
	a = v_len_sqr(ray.v_dir);
	b = 2 * v_dot(ray.v_dir, sphere_to_ray);
	c = v_dot(sphere_to_ray, sphere_to_ray) - 1;
	sqrt_discriminant = sqrt(pow(b, 2) - 4 * a * c);
	res[0] = (-b - sqrt_discriminant) / (2 * a);
	res[1] = (-b + sqrt_discriminant) / (2 * a);
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
