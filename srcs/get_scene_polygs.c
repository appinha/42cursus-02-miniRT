/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_objs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:44:38 by appinha           #+#    #+#             */
/*   Updated: 2020/11/08 19:55:29 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_scene_sphere(t_scene *scene)
{
	t_elem	*sphere_new;

	scene_line_split(scene, 4, "150");
	sphere_new = malloc_ver(sizeof(t_elem), scene, 0);
	get_tuple(scene, scene->split[1], &sphere_new->coord, "151");
	get_float(scene, scene->split[2], &sphere_new->diam, "152");
	if (!(sphere_new->diam > 0))
		error_msg("152", scene, 0);
	get_rgb(scene, scene->split[3], &sphere_new->rgb, "153");
	lstadd_front_elem(&scene->sphere, sphere_new, &scene->qtys.sphere);
}

void	get_scene_plane(t_scene *scene)
{
	t_elem	*plane_new;

	scene_line_split(scene, 4, "160");
	plane_new = malloc_ver(sizeof(t_elem), scene, 0);
	get_tuple(scene, scene->split[1], &plane_new->coord, "161");
	get_normal(scene, scene->split[2], &plane_new->normal, "162");
	get_rgb(scene, scene->split[3], &plane_new->rgb, "163");
	lstadd_front_elem(&scene->plane, plane_new, &scene->qtys.plane);
}

void	get_scene_square(t_scene *scene)
{
	t_elem	*square_new;

	scene_line_split(scene, 5, "170");
	square_new = malloc_ver(sizeof(t_elem), scene, 0);
	get_tuple(scene, scene->split[1], &square_new->coord, "171");
	get_normal(scene, scene->split[2], &square_new->normal, "172");
	get_float(scene, scene->split[3], &square_new->height, "173");
	get_rgb(scene, scene->split[4], &square_new->rgb, "174");
	lstadd_front_elem(&scene->square, square_new, &scene->qtys.square);
}

void	get_scene_cylind(t_scene *scene)
{
	t_elem	*cylind_new;

	scene_line_split(scene, 6, "180");
	cylind_new = malloc_ver(sizeof(t_elem), scene, 0);
	get_tuple(scene, scene->split[1], &cylind_new->coord, "181");
	get_normal(scene, scene->split[2], &cylind_new->normal, "182");
	get_float(scene, scene->split[3], &cylind_new->diam, "183");
	get_float(scene, scene->split[3], &cylind_new->height, "184");
	get_rgb(scene, scene->split[4], &cylind_new->rgb, "185");
	lstadd_front_elem(&scene->cylind, cylind_new, &scene->qtys.cylind);
}

void	get_scene_triang(t_scene *scene)
{
	t_elem	*triang_new;

	scene_line_split(scene, 5, "190");
	triang_new = malloc_ver(sizeof(t_elem), scene, 0);
	get_tuple(scene, scene->split[2], &triang_new->p1, "191");
	get_tuple(scene, scene->split[2], &triang_new->p2, "191");
	get_tuple(scene, scene->split[2], &triang_new->p3, "191");
	get_rgb(scene, scene->split[4], &triang_new->rgb, "192");
	lstadd_front_elem(&scene->triang, triang_new, &scene->qtys.triang);
}
