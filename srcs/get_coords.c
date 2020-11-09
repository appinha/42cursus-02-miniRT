/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:39:31 by appinha           #+#    #+#             */
/*   Updated: 2020/11/08 19:51:16 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	get_normal(t_scene *scene, char *str, t_tuple *tuple, char *msg_nbr)
{
	get_tuple(scene, str, tuple, msg_nbr);
	if (ft_isnormal(*tuple) == 0)
		error_msg(msg_nbr, scene, 0);
}
