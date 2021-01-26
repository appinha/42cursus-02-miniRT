/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:41:37 by apuchill          #+#    #+#             */
/*   Updated: 2021/01/26 11:12:08 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "scene.h"

void	get_scene_elem(t_scene *scene, short int elem_id,
						void (*ft)(t_scene *, t_elem **))
{
	t_elem	*new;

	new = 0;
	if (elem_id < 2)
		scene_check_qty(scene, elem_id, 0);
	else
		new = malloc_ver(sizeof(t_elem));
	scene_line_split(scene, elem_id, 1);
	(*ft)(scene, &new);
	if (elem_id >= 2)
		lstadd_front_elem(&scene->cam + elem_id - 2, new,
							&scene->qtys[elem_id]);
	ft_split_free(scene->split);
	scene->qtys[elem_id]++;
}

void	get_scene_0_resol(t_scene *scene, t_elem **new)
{
	scene->resol.x = get_posint(scene->split[1], "106");
	scene->resol.y = get_posint(scene->split[2], "106");
	if (new)
		return ;
}

void	get_scene_1_amb_li(t_scene *scene, t_elem **new)
{
	scene->amb_li.ratio = get_ratio(scene->split[1], "116");
	scene->amb_li.rgb = get_rgb(scene->split[2], "114");
	if (new)
		return ;
}

void	get_scene_2_cam(t_scene *scene, t_elem **new)
{
	(*new)->coord = get_coord(scene->split[1], "122");
	(*new)->normal = get_normal(scene->split[2], "123");
	(*new)->fov = get_fov(scene->split[3], "126");
}

void	get_scene_3_light(t_scene *scene, t_elem **new)
{
	(*new)->coord = get_coord(scene->split[1], "132");
	(*new)->ratio = get_ratio(scene->split[2], "136");
	(*new)->rgb = get_rgb(scene->split[3], "134");
}
