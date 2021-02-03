/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:17:20 by appinha           #+#    #+#             */
/*   Updated: 2021/02/03 08:47:13 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "scene.h"
#include "tests.h"

void		init_scene(char *file, t_scene *scene)
{
	static t_arr_sc	ft_scene[9] = {get_0_resol, get_1_amb_li, get_2_cam,
				get_3_light, get_4_sp, get_5_pl, get_6_sq, get_7_cy, get_8_tr};
	static char		*elem[9] = {"R ", "A ", "c ", "l ",
								"sp", "pl", "sq", "cy", "tr"};
	int				id;
	int				fd;

	if (ft_strnrcmp(file, ".rt", 3) != 0)
		error_msg_and_exit("010");
	*scene = (t_scene) {0};
	if ((fd = open(file, O_RDONLY)) < 0)
		error_msg_and_exit(SYSERR);
	while (get_next_line(fd, &scene->line) == 1)
	{
		id = 0;
		while (id < 9 && ft_strncmp(scene->line, elem[id], 2))
			id++;
		if (id < 9)
			get_scene_elem(scene, id, *ft_scene[id]);
		free(scene->line);
	}
	close(fd);
	if (scene->qtys[0] == 0 || scene->qtys[1] == 0 || scene->qtys[2] == 0)
		error_msg_and_exit("012");
	print_triage_scene_info(scene);
}

static int	ft_isvalidchar(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9') || (c == '-') || (c == '.') || (c == ',') ||
		(c == ' ') || (c == '\n'))
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

void		get_scene_elem(t_scene *scene, short int elem_id,
						void (*ft)(t_scene *, t_elem **))
{
	t_elem	*new;

	new = 0;
	if (elem_id < 2)
	{
		if (scene->qtys[elem_id] > 0)
			error_msg_and_exit(get_error_code(1, elem_id, 0));
	}
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

void		lstadd_front_elem(t_elem **lst, t_elem *new, short int *qty)
{
	new->next = NULL;
	if ((*qty) == 0)
		(*lst) = new;
	else
	{
		while ((*lst)->next != NULL)
			(*lst) = (*lst)->next;
		(*lst)->next = new;
	}
	(*qty)++;
}
