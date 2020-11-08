/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:45:07 by appinha           #+#    #+#             */
/*   Updated: 2020/11/07 22:40:40 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_line_split(t_scene *scene, short int qty, char *msg_nbr)
{
	scene->split = ft_split(scene->line, ' ');
	if (ft_strlen_2(scene->split) != (size_t)qty)
		error_msg(msg_nbr, scene, 0);
}

void	get_rgb(t_scene *scene, char *str, t_rgb *rgb, char *msg_nbr)
{
	char	**split;

	split = ft_split(str, ',');
	if (ft_strlen_2(split) != 3 || !(ft_str_isint(split[0]) == 1 &&
			ft_str_isint(split[1]) == 1 && ft_str_isint(split[2]) == 1))
	{
		ft_split_free(split);
		error_msg(msg_nbr, scene, 0);
	}
	rgb->r = ft_atoi(split[0]);
	rgb->g = ft_atoi(split[1]);
	rgb->b = ft_atoi(split[2]);
	ft_split_free(split);
	if (ft_isrgb(rgb->r) == 0 || ft_isrgb(rgb->g) == 0 ||
			ft_isrgb(rgb->b) == 0)
		error_msg(msg_nbr, scene, 0);
}

void	get_tuple(t_scene *scene, char *str, t_tuple *tuple, char *msg_nbr)
{
	char	**split;

	split = ft_split(str, ',');
	if (ft_strlen_2(split) != 3 || !(ft_str_isfloat(split[0]) == 1 &&
			ft_str_isfloat(split[1]) == 1 && ft_str_isfloat(split[2]) == 1))
	{
		ft_split_free(split);
		error_msg(msg_nbr, scene, 0);
	}
	tuple->x = ft_atof(split[0]);
	tuple->y = ft_atof(split[1]);
	tuple->z = ft_atof(split[2]);
	ft_split_free(split);
}

void	get_int(t_scene *scene, char *str, int *n, char *msg_nbr)
{
	if (ft_str_isint(str) == 0)
		error_msg(msg_nbr, scene, 0);
	*n = ft_atoi(str);
}

void	get_float(t_scene *scene, char *str, double *n, char *msg_nbr)
{
	if (ft_str_isfloat(str) == 0)
		error_msg(msg_nbr, scene, 0);
	*n = ft_atof(str);
}

void	get_ratio(t_scene *scene, char *str, double *n, char *msg_nbr)
{
	get_float(scene, str, n, msg_nbr);
	if (ft_isratio(*n) == 0)
		error_msg(msg_nbr, scene, 0);
}

void	get_normal(t_scene *scene, char *str, t_tuple *tuple, char *msg_nbr)
{
	get_tuple(scene, str, tuple, msg_nbr);
	if (ft_isnormal(*tuple) == 0)
		error_msg(msg_nbr, scene, 0);
}
/*
void	scene_lstadd_front(void *lst, void *new, int qty)
{
	new->next = NULL;
	if (qty == 0)
		lst = new;
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
}
*/
