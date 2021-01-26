/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:39:31 by appinha           #+#    #+#             */
/*   Updated: 2021/01/26 11:10:49 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "scene.h"

int		ft_isnormal(t_coord normal)
{
	if (normal.x >= -1.0 && normal.x <= 1.0 &&
			normal.y >= -1.0 && normal.y <= 1.0 &&
			normal.z >= -1.0 && normal.z <= 1.0)
		return (1);
	return (0);
}

t_coord	get_coord(char *str, char *code)
{
	t_coord	coord;
	char	**split;

	split = ft_split(str, ',');
	if (ft_strlen_2(split) != 3 || !(ft_str_isfloat(split[0]) == 1 &&
			ft_str_isfloat(split[1]) == 1 && ft_str_isfloat(split[2]) == 1))
	{
		ft_split_free(split);
		error_msg_and_exit(code);
	}
	coord.x = ft_atof(split[0]);
	coord.y = ft_atof(split[1]);
	coord.z = ft_atof(split[2]);
	ft_split_free(split);
	return (coord);
}

t_coord	get_normal(char *str, char *code)
{
	t_coord	coord;

	coord = get_coord(str, code);
	if (ft_isnormal(coord) == 0)
		error_msg_and_exit(code);
	return (coord);
}
