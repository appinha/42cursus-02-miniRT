/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:41:37 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/13 12:42:48 by apuchill         ###   ########.fr       */
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
	ft_bzero(&scene->amb_li, 0);
	scene->amb_li.elem_type = AMBIENT_LIGHT;
	scene->amb_li.ratio = get_ratio(scene->split[1], "116");
	scene->amb_li.colour = get_colour(scene->split[2], "114");
	if (new)
		return ;
}

void	get_2_cam(t_scene *scene, t_elem **new)
{
	(*new)->elem_type = CAMERA;
	(*new)->point = get_coord(scene->split[1], "122");
	(*new)->normal = v_norm(get_normal(scene->split[2], "123"));
	(*new)->cam.fov = get_fov(scene->split[3], "126");
}

void	get_cam_info(t_scene *scene, t_elem *cam)
{
	float	vp[2];
	t_coord	w;
	t_coord	u;
	t_coord	v;

	while (cam)
	{
		vp[0] = 2 * tan(cam->cam.fov / 2);
		vp[1] = vp[0] * (float)scene->resol.y / scene->resol.x;
		w = v_norm(v_scale(cam->normal, -1));
		u = v_cross(gen_coord(0, 1, 0), w);
		v = v_cross(w, u);
		cam->cam.hor = v_scale(u, vp[0]);
		cam->cam.ver = v_scale(v, vp[1]);
		cam->cam.llc = v_sub(cam->point, v_scale(cam->cam.hor, 0.5));
		cam->cam.llc = v_sub(cam->cam.llc, v_scale(cam->cam.ver, 0.5));
		cam->cam.llc = v_sub(cam->cam.llc, w);
		cam = cam->next;
	}
}

void	get_3_light(t_scene *scene, t_elem **new)
{
	(*new)->elem_type = LIGHT;
	(*new)->point = get_coord(scene->split[1], "132");
	(*new)->ratio = get_ratio(scene->split[2], "136");
	(*new)->colour = get_colour(scene->split[3], "134");
}
