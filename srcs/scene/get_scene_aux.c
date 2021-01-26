/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:45:07 by appinha           #+#    #+#             */
/*   Updated: 2021/01/26 12:18:36 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "scene.h"

int		ft_isvalidchar(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9') || (c == '-') || (c == '.') || (c == ',') ||
		(c == ' ') || (c == '\n'))
		return (1);
	return (0);
}

void	scene_check_qty(t_scene *scene, short int elem_id, short int err_id)
{
	if (scene->qtys[elem_id] > 0)
		error_msg_and_exit(get_error_code(1, elem_id, err_id));
}

void	scene_line_split(t_scene *scene, short int elem_id, short int err_id)
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

void	lstadd_front_elem(t_elem **lst, t_elem *new, short int *qty)
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
