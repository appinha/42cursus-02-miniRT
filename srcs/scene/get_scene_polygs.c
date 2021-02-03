/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_polygs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:44:38 by appinha           #+#    #+#             */
/*   Updated: 2021/02/03 08:03:22 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "scene.h"

void	get_4_sp(t_scene *scene, t_elem **new)
{
	(*new)->coord = get_coord(scene->split[1], "142");
	(*new)->diam = get_size(scene->split[2], "145");
	(*new)->rgb = get_rgb(scene->split[3], "144");
}

void	get_5_pl(t_scene *scene, t_elem **new)
{
	(*new)->coord = get_coord(scene->split[1], "152");
	(*new)->normal = get_normal(scene->split[2], "152");
	(*new)->rgb = get_rgb(scene->split[3], "154");
}

void	get_6_sq(t_scene *scene, t_elem **new)
{
	(*new)->coord = get_coord(scene->split[1], "162");
	(*new)->normal = get_normal(scene->split[2], "162");
	(*new)->height = get_size(scene->split[3], "165");
	(*new)->rgb = get_rgb(scene->split[4], "164");
}

void	get_7_cy(t_scene *scene, t_elem **new)
{
	(*new)->coord = get_coord(scene->split[1], "172");
	(*new)->normal = get_normal(scene->split[2], "173");
	(*new)->diam = get_size(scene->split[3], "175");
	(*new)->height = get_size(scene->split[3], "176");
	(*new)->rgb = get_rgb(scene->split[4], "174");
}

void	get_8_tr(t_scene *scene, t_elem **new)
{
	(*new)->p1 = get_coord(scene->split[2], "182");
	(*new)->p2 = get_coord(scene->split[2], "182");
	(*new)->p3 = get_coord(scene->split[2], "182");
	(*new)->rgb = get_rgb(scene->split[4], "184");
}
