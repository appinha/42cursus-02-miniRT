/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:41:37 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/03 08:03:10 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "scene.h"

void	get_0_resol(t_scene *scene, t_elem **new)
{
	scene->resol.x = get_posint(scene->split[1], "106");
	scene->resol.y = get_posint(scene->split[2], "106");
	if (new)
		return ;
}

void	get_1_amb_li(t_scene *scene, t_elem **new)
{
	scene->amb_li.ratio = get_ratio(scene->split[1], "116");
	scene->amb_li.rgb = get_rgb(scene->split[2], "114");
	if (new)
		return ;
}

void	get_2_cam(t_scene *scene, t_elem **new)
{
	(*new)->coord = get_coord(scene->split[1], "122");
	(*new)->normal = get_normal(scene->split[2], "123");
	(*new)->fov = get_fov(scene->split[3], "126");
}

void	get_3_light(t_scene *scene, t_elem **new)
{
	(*new)->coord = get_coord(scene->split[1], "132");
	(*new)->ratio = get_ratio(scene->split[2], "136");
	(*new)->rgb = get_rgb(scene->split[3], "134");
}
