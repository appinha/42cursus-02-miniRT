/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:41:37 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/14 20:05:22 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_bzero(&scene->amb_li, 0);
	scene->amb_li.ratio = get_ratio(scene->split[1], "116");
	scene->amb_li.colour = get_colour(scene->split[2], "114");
	if (new)
		return ;
}

void	get_2_cam(t_scene *scene, t_elem **new)
{
	t_cam	*new_cam;

	free(*new);
	new_cam = malloc_ver(sizeof(t_cam));
	ft_bzero(new_cam, 0);
	new_cam->point = get_coord(scene->split[1], "122");
	new_cam->normal = v_norm(get_normal(scene->split[2], "123"));
	new_cam->fov = get_fov(scene->split[3], "126");
	new_cam->img.ptr = NULL;
	new_cam->next = NULL;
	new_cam->prev = NULL;
	lstadd_back_cam(&scene->cam, new_cam, &scene->qtys[2]);
}

void	get_cam_info(t_scene *scene, t_cam *cam)
{
	float	vp[2];
	t_coord	w;
	t_coord	u;
	t_coord	v;

	while (cam)
	{
		vp[0] = 2 * tan(cam->fov / 2);
		vp[1] = vp[0] * (float)scene->resol.y / scene->resol.x;
		w = v_norm(v_scale(cam->normal, -1));
		u = v_cross(gen_coord(0, 1, 0), w);
		v = v_cross(w, u);
		cam->hor = v_scale(u, vp[0]);
		cam->ver = v_scale(v, vp[1]);
		cam->llc = v_sub(cam->point, v_scale(cam->hor, 0.5));
		cam->llc = v_sub(cam->llc, v_scale(cam->ver, 0.5));
		cam->llc = v_sub(cam->llc, w);
		cam = cam->next;
	}
}

void	get_3_light(t_scene *scene, t_elem **new)
{
	(*new)->point = get_coord(scene->split[1], "132");
	(*new)->ratio = get_ratio(scene->split[2], "136");
	(*new)->colour = get_colour(scene->split[3], "134");
}
