/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:41:37 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/08 00:21:48 by appinha          ###   ########.fr       */
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
	t_cam	*cam_new;

	scene_line_split(scene, 4, "130");
	cam_new = malloc_ver(sizeof(t_cam), scene, 0);
	get_tuple(scene, scene->split[1], &cam_new->coord, "131");
	get_normal(scene, scene->split[2], &cam_new->normal, "132");
	get_int(scene, scene->split[3], &cam_new->fov, "133");
	if (!(cam_new->fov >= 0 && cam_new->fov <= 180))
		error_msg("133", scene, 0);
	cam_new->next = NULL;
	if (scene->qtys.cam == 0)
		scene->cam = cam_new;
	else
	{
		while (scene->cam->next != NULL)
			scene->cam = scene->cam->next;
		scene->cam->next = cam_new;
	}
	scene->qtys.cam++;
}

void	get_scene_light(t_scene *scene)
{
	t_light	*light_new;

	scene_line_split(scene, 4, "140");
	light_new = malloc_ver(sizeof(t_light), scene, 0);
	get_tuple(scene, scene->split[1], &light_new->coord, "141");
	get_ratio(scene, scene->split[2], &light_new->ratio, "142");
	get_rgb(scene, scene->split[3], &light_new->rgb, "143");
	light_new->next = NULL;
	if (scene->qtys.light == 0)
		scene->light = light_new;
	else
	{
		while (scene->light->next != NULL)
			scene->light = scene->light->next;
		scene->light->next = light_new;
	}
	scene->qtys.light++;
}

void	get_scene_sphere(t_scene *scene)
{
	t_sphere	*sphere_new;

	scene_line_split(scene, 4, "150");
	sphere_new = malloc_ver(sizeof(t_sphere), scene, 0);
	get_tuple(scene, scene->split[1], &sphere_new->coord, "151");
	get_float(scene, scene->split[2], &sphere_new->diam, "152");
	if (!(sphere_new->diam > 0))
		error_msg("152", scene, 0);
	get_rgb(scene, scene->split[3], &sphere_new->rgb, "153");
	sphere_new->next = NULL;
	if (scene->qtys.sphere == 0)
		scene->sphere = sphere_new;
	else
	{
		while (scene->sphere->next != NULL)
			scene->sphere = scene->sphere->next;
		scene->sphere->next = sphere_new;
	}
	scene->qtys.sphere++;
}

void	get_scene_plane(t_scene *scene)
{
	t_plane	*plane_new;

	scene_line_split(scene, 4, "160");
	plane_new = malloc_ver(sizeof(t_plane), scene, 0);
	get_tuple(scene, scene->split[1], &plane_new->coord, "161");
	get_tuple(scene, scene->split[2], &plane_new->normal, "162");
	get_rgb(scene, scene->split[3], &plane_new->rgb, "163");
	plane_new->next = NULL;
	if (scene->qtys.plane == 0)
		scene->plane = plane_new;
	else
	{
		while (scene->plane->next != NULL)
			scene->plane = scene->plane->next;
		scene->plane->next = plane_new;
	}
	scene->qtys.plane++;
}


