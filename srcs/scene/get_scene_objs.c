/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_objs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:44:38 by appinha           #+#    #+#             */
/*   Updated: 2021/02/14 19:31:53 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	get_4_sp(t_scene *scene, t_elem **new)
{
	(*new)->point = get_coord(scene->split[1], "142");
	(*new)->diam = get_size(scene->split[2], "145");
	(*new)->colour = get_colour(scene->split[3], "144");
}

void	get_5_pl(t_scene *scene, t_elem **new)
{
	(*new)->point = get_coord(scene->split[1], "152");
	(*new)->normal = get_normal(scene->split[2], "152");
	(*new)->colour = get_colour(scene->split[3], "154");
}

void	get_6_sq(t_scene *scene, t_elem **new)
{
	t_coord		p_x;
	t_coord		p_y;

	(*new)->qtd_vertex = 4;
	(*new)->point = get_coord(scene->split[1], "162");
	(*new)->normal = get_normal(scene->split[2], "162");
	(*new)->height = get_size(scene->split[3], "165");
	(*new)->colour = get_colour(scene->split[4], "164");
	p_x = v_cross((*new)->normal,
			gen_coord((*new)->normal.z, (*new)->normal.x, (*new)->normal.y));
	p_y = v_cross((*new)->normal, p_x);
	p_x = v_scale(p_x, (*new)->height / 2);
	p_y = v_scale(p_y, (*new)->height / 2);
	(*new)->vertex = malloc_ver(4 * sizeof(t_coord));
	(*new)->vertex[0] = v_add(v_add((*new)->point, p_x), p_y);
	(*new)->vertex[1] = v_sub(v_add((*new)->point, p_x), p_y);
	(*new)->vertex[2] = v_sub(v_sub((*new)->point, p_x), p_y);
	(*new)->vertex[3] = v_add(v_sub((*new)->point, p_x), p_y);
}

void	get_7_cy(t_scene *scene, t_elem **new)
{
	(*new)->point = get_coord(scene->split[1], "172");
	(*new)->normal = v_norm(get_normal(scene->split[2], "173"));
	(*new)->diam = get_size(scene->split[3], "175");
	(*new)->height = get_size(scene->split[4], "176");
	(*new)->colour = get_colour(scene->split[5], "174");
}

void	get_8_tr(t_scene *scene, t_elem **new)
{
	(*new)->qtd_vertex = 3;
	(*new)->vertex = malloc_ver(3 * sizeof(t_coord));
	(*new)->vertex[0] = get_coord(scene->split[1], "182");
	(*new)->vertex[1] = get_coord(scene->split[2], "182");
	(*new)->vertex[2] = get_coord(scene->split[3], "182");
	(*new)->normal = v_norm(v_cross(v_sub((*new)->vertex[1], (*new)->vertex[0]),
								v_sub((*new)->vertex[2], (*new)->vertex[0])));
	(*new)->colour = get_colour(scene->split[4], "184");
}
