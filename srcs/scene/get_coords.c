/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:39:31 by appinha           #+#    #+#             */
/*   Updated: 2021/02/14 19:32:14 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

bool	ft_isnormal(t_coord normal)
{
	if (normal.x >= -1.0 && normal.x <= 1.0 &&
			normal.y >= -1.0 && normal.y <= 1.0 &&
			normal.z >= -1.0 && normal.z <= 1.0)
		return (true);
	return (false);
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
	if (ft_isnormal(coord) == false)
		error_msg_and_exit(code);
	return (coord);
}
