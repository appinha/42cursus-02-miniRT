/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:17:20 by appinha           #+#    #+#             */
/*   Updated: 2021/01/26 12:19:06 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "scene.h"
#include "tests.h"

void	init_scene(char *file, t_scene *scene)
{
	static t_arr_sc	ft_scene[9] = {get_scene_0_resol, get_scene_1_amb_li,
		get_scene_2_cam, get_scene_3_light, get_scene_4_sp, get_scene_5_pl,
		get_scene_6_sq, get_scene_7_cy, get_scene_8_tr};
	static char		*elem[9] = {"R ", "A ", "c ", "l ",
								"sp", "pl", "sq", "cy", "tr"};
	int				id;

	if (ft_strnrcmp(file, ".rt", 3) != 0)
		error_msg_and_exit("010");
	*scene = (t_scene) {0};
	if ((scene->fd = open(file, O_RDONLY)) < 0)
		error_msg_and_exit(SYSERR);
	while (get_next_line(scene->fd, &scene->line) == 1)
	{
		id = 0;
		while (id < 9 && ft_strncmp(scene->line, elem[id], 2))
			id++;
		if (id < 9)
			get_scene_elem(scene, id, *ft_scene[id]);
		free(scene->line);
	}
	close(scene->fd);
	if (scene->qtys[0] == 0 || scene->qtys[1] == 0 || scene->qtys[2] == 0)
		error_msg_and_exit("012");
	print_triage_scene_info(scene);
}
