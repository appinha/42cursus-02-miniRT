/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_objs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:44:38 by appinha           #+#    #+#             */
/*   Updated: 2021/02/07 09:23:52 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
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
	(*new)->point = get_coord(scene->split[1], "162");
	(*new)->normal = get_normal(scene->split[2], "162");
	(*new)->height = get_size(scene->split[3], "165");
	(*new)->colour = get_colour(scene->split[4], "164");
}

void	get_7_cy(t_scene *scene, t_elem **new)
{
	(*new)->point = get_coord(scene->split[1], "172");
	(*new)->normal = get_normal(scene->split[2], "173");
	(*new)->diam = get_size(scene->split[3], "175");
	(*new)->height = get_size(scene->split[3], "176");
	(*new)->colour = get_colour(scene->split[4], "174");
}

void	get_8_tr(t_scene *scene, t_elem **new)
{
	(*new)->tr.p1 = get_coord(scene->split[1], "182");
	(*new)->tr.p2 = get_coord(scene->split[2], "182");
	(*new)->tr.p3 = get_coord(scene->split[3], "182");
	(*new)->colour = get_colour(scene->split[4], "184");
}
