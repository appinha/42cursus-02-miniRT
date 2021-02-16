/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:17:20 by appinha           #+#    #+#             */
/*   Updated: 2021/02/15 16:35:09 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static int	ft_isvalidchar(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9') || (c == '-') || (c == '+') || (c == '.') ||
		(c == ',') || (c == ' ') || (c == '\n'))
		return (1);
	return (0);
}

static void	scene_line_split(t_scene *scene, short int elem_id,
								short int err_id)
{
	static int	info_qty[9] = {3, 3, 4, 4, 4, 4, 5, 6, 5};
	int			i;

	i = 0;
	while (scene->line[i])
	{
		if (ft_isvalidchar(scene->line[i]) == 0)
			error_msg_and_exit("011");
		i++;
	}
	scene->split = ft_split(scene->line, ' ');
	if (ft_strlen_2(scene->split) != (size_t)info_qty[elem_id])
		error_msg_and_exit(get_error_code(1, elem_id, err_id));
}

static void	get_scene_elem(t_scene *scene, short int elem_id)
{
	static t_arr_sc	ft_scene[9] = {get_0_resol, get_1_amb_li, get_2_cam,
				get_3_light, get_4_sp, get_5_pl, get_6_sq, get_7_cy, get_8_tr};
	t_elem			*new;

	new = NULL;
	if (elem_id < 2)
	{
		if (scene->qtys[elem_id] > 0)
			error_msg_and_exit(get_error_code(1, elem_id, 0));
	}
	else
	{
		new = malloc_ver(sizeof(t_elem));
		ft_bzero(new, 0);
		new->next = NULL;
	}
	scene_line_split(scene, elem_id, 1);
	ft_scene[elem_id](scene, &new);
	if (elem_id >= 3)
		lstadd_back_elem(&scene->light + elem_id - 3, new,
							&scene->qtys[elem_id]);
	ft_split_free(scene->split);
	scene->qtys[elem_id]++;
}

void		init_scene(char *file, t_scene *scene)
{
	static char	*s[9] = {"R ", "A ", "c ", "l ", "sp", "pl", "sq", "cy", "tr"};
	int			elem_id;
	int			fd;
	int			ret;

	if (ft_strnrcmp(file, ".rt", 3) != 0)
		error_msg_and_exit("010");
	*scene = (t_scene) {0};
	fd = open_ver(file);
	while ((ret = get_next_line(fd, &scene->line)) >= 0)
	{
		elem_id = 0;
		while (elem_id < 9 && ft_strncmp(scene->line, s[elem_id], 2))
			elem_id++;
		if (elem_id < 9)
			get_scene_elem(scene, elem_id);
		free(scene->line);
		if (ret == 0)
			break ;
	}
	close_ver(fd);
	if (scene->qtys[0] == 0 || scene->qtys[1] == 0 || scene->qtys[2] == 0)
		error_msg_and_exit("012");
	get_cam_info(scene, scene->cam);
}
