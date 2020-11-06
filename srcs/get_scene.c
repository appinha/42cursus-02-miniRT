/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:41:37 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/05 21:59:32 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_rgb(char *str, t_rgb *rgb)
{
	char	**split;

	split = ft_split(str, ',');
	if (ft_strlen_2(split) != 3)
	{
		ft_split_free(split);
		return (-1);
	}
	rgb->r = ft_atoi(split[0]);
	rgb->g = ft_atoi(split[1]);
	rgb->b = ft_atoi(split[2]);
	ft_split_free(split);
	if (ft_isrgb(rgb->r) == 0 || ft_isrgb(rgb->g) == 0 ||
			ft_isrgb(rgb->b) == 0)
		return (-1);
	return (0);
}

void	get_scene_resol(t_scene *scene)
{
	t_resol		resol;

	if (scene->qtys.resol > 0)
		error_msg("110", scene, 0);
	scene->split = ft_split(scene->line, ' ');
	if (ft_strlen_2(scene->split) != 3)
		error_msg("111", scene, 0);
	resol.x = ft_atoi(scene->split[1]);
	resol.y = ft_atoi(scene->split[2]);
	if (!(resol.x > 0 && resol.y > 0))
		error_msg("112", scene, 0);
	ft_split_free(scene->split);
	scene->qtys.resol = 1;
	scene->resol = resol;
}

void	get_scene_amb_li(t_scene *scene)
{
	t_amb_li	amb_li;
	t_rgb		rgb;

	if (scene->qtys.amb_li > 0)
		error_msg("120", scene, 0);
	scene->split = ft_split(scene->line, ' ');
	if (ft_strlen_2(scene->split) != 3)
		error_msg("121", scene, 0);
	if (get_rgb(scene->split[2], &rgb) < 0)
		error_msg("123", scene, 0);
	amb_li.rgb = rgb;
	amb_li.ratio = ft_atof(scene->split[1]);
	if (ft_isratio(amb_li.ratio) == 0)
		error_msg("122", scene, 0);
	scene->qtys.amb_li = 1;
	scene->amb_li = amb_li;
}
