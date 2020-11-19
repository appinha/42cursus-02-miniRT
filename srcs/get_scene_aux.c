/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:45:07 by appinha           #+#    #+#             */
/*   Updated: 2020/11/09 09:49:59 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_isvalidchar(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9') || (c == '-') || (c == '.') || (c == ',') ||
		(c == ' ') || (c == '\n'))
		return (1);
	return (0);
}

void	scene_line_split(t_scene *scene, short int qty, char *msg_nbr)
{
	int		i;

	i = 0;
	while (scene->line[i])
	{
		if (ft_isvalidchar(scene->line[i]) == 0)
			error_msg("101", scene, 0);
		i++;
	}
	scene->split = ft_split(scene->line, ' ');
	if (ft_strlen_2(scene->split) != (size_t)qty)
		error_msg(msg_nbr, scene, 0);
}

void	lstadd_front_elem(t_elem **lst, t_elem *new, int *qty)
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
