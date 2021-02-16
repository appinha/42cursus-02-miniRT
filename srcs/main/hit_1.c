/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:48 by appinha           #+#    #+#             */
/*   Updated: 2021/02/15 17:49:18 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord			get_hit_point(t_ray ray)
{
	return (v_add(ray.p_ori, v_scale(ray.v_dir, ray.hit.time)));
}

static void		bhaskara(float a, float b, float c, float *res)
{
	float		sqrt_discriminant;
	float		aux[2];

	sqrt_discriminant = sqrt(pow(b, 2) - 4 * a * c);
	aux[0] = (-b - sqrt_discriminant) / (2 * a);
	aux[1] = (-b + sqrt_discriminant) / (2 * a);
	if (aux[0] < aux[1])
	{
		res[0] = aux[0];
		res[1] = aux[1];
	}
	else
	{
		res[0] = aux[1];
		res[1] = aux[0];
	}
}

bool			hit_sp(t_ray *ray, t_elem *elem)
{
	t_coord		v_sp2ray;
	float		time[2];

	v_sp2ray = v_sub(ray->p_ori, elem->point);
	bhaskara(v_len_sqr(ray->v_dir), 2 * v_dot(ray->v_dir, v_sp2ray),
				v_dot(v_sp2ray, v_sp2ray) - pow(elem->diam / 2, 2), time);
	if (ray->hit.time > time[0] && time[0] > 0)
	{
		ray->hit.time = time[0];
		ray->hit.point = get_hit_point(*ray);
		ray->hit.normal = v_norm(v_sub(ray->hit.point, elem->point));
		ray->hit.colour = elem->colour;
		return (true);
	}
	return (false);
}

static float	cy_calc(t_ray ray, t_elem cy, float *y, bool ret[2])
{
	t_coord	v[2];
	t_coord	v_cy2ray;
	float	time[2];
	float	dist[2];

	v[0] = v_sub(ray.v_dir, v_scale(cy.normal, v_dot(ray.v_dir, cy.normal)));
	v[1] = v_sub(v_sub(ray.p_ori, cy.point),
			v_scale(cy.normal, v_dot(v_sub(ray.p_ori, cy.point), cy.normal)));
	bhaskara(v_len_sqr(v[0]), 2 * v_dot(v[0], v[1]),
				v_len_sqr(v[1]) - pow(cy.diam / 2, 2), time);
	v_cy2ray = v_sub(cy.point, ray.p_ori);
	dist[0] = v_dot(cy.normal, v_sub(v_scale(ray.v_dir, time[0]), v_cy2ray));
	dist[1] = v_dot(cy.normal, v_sub(v_scale(ray.v_dir, time[1]), v_cy2ray));
	ret[0] = (dist[0] >= 0 && dist[0] <= cy.height && time[0] > EPSILON);
	ret[1] = (dist[1] >= 0 && dist[1] <= cy.height && time[1] > EPSILON);
	if (ret[0] == false & ret[1] == true)
	{
		*y = dist[1];
		return (time[1]);
	}
	*y = dist[0];
	return (time[0]);
}

bool			hit_cy(t_ray *ray, t_elem *elem)
{
	bool		ret[2];
	float		time;
	float		y;

	time = cy_calc(*ray, *elem, &y, ret);
	if ((ret[0] || ret[1]) && ray->hit.time > time && time > EPSILON)
	{
		ray->hit.time = time;
		ray->hit.point = get_hit_point(*ray);
		if (ret[0] == false & ret[1] == true)
			ray->hit.normal = v_scale(ray->hit.normal, -1);
		else
			ray->hit.normal = v_norm(v_sub(ray->hit.point,
								v_add(v_scale(elem->normal, y), elem->point)));
		ray->hit.colour = elem->colour;
	}
	return (ret[0] || ret[1]);
}
