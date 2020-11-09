/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:41:37 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/08 19:55:08 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_scene_resol(t_scene *scene)
{
	if (scene->qtys.resol > 0)
		error_msg("110", scene, 0);
	scene_line_split(scene, 3, "111");
	get_int(scene, scene->split[1], &scene->resol.x, "112");
	get_int(scene, scene->split[2], &scene->resol.y, "112");
	if (!(scene->resol.x > 0 && scene->resol.y > 0))
		error_msg("112", scene, 0);
	ft_split_free(scene->split);
	scene->qtys.resol = 1;
}

void	get_scene_amb_li(t_scene *scene)
{
	if (scene->qtys.amb_li > 0)
		error_msg("120", scene, 0);
	scene_line_split(scene, 3, "121");
	get_rgb(scene, scene->split[2], &scene->amb_li.rgb, "123");
	get_ratio(scene, scene->split[1], &scene->amb_li.ratio, "122");
	scene->qtys.amb_li = 1;
}

void	get_scene_cam(t_scene *scene)
{
	t_elem	*cam_new;

	scene_line_split(scene, 4, "130");
	cam_new = malloc_ver(sizeof(t_elem), scene, 0);
	get_tuple(scene, scene->split[1], &cam_new->coord, "131");
	get_normal(scene, scene->split[2], &cam_new->normal, "132");
	get_int(scene, scene->split[3], &cam_new->fov, "133");
	if (!(cam_new->fov >= 0 && cam_new->fov <= 180))
		error_msg("133", scene, 0);
	lstadd_front_elem(&scene->cam, cam_new, &scene->qtys.cam);
}

void	get_scene_light(t_scene *scene)
{
	t_elem	*light_new;

	scene_line_split(scene, 4, "140");
	light_new = malloc_ver(sizeof(t_elem), scene, 0);
	get_tuple(scene, scene->split[1], &light_new->coord, "141");
	get_ratio(scene, scene->split[2], &light_new->ratio, "142");
	get_rgb(scene, scene->split[3], &light_new->rgb, "143");
	lstadd_front_elem(&scene->light, light_new, &scene->qtys.light);
}
