/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:36:57 by appinha           #+#    #+#             */
/*   Updated: 2020/11/27 16:31:55 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_isrgb(int n)
{
	if (n >= 0 && n <= 255)
		return (1);
	return (0);
}

t_rgb	get_rgb(t_scene *scene, char *str, char *msg_nbr)
{
	t_rgb	rgb;
	char	**split;

	split = ft_split(str, ',');
	if (ft_strlen_2(split) != 3 || !(ft_str_isint(split[0]) == 1 &&
			ft_str_isint(split[1]) == 1 && ft_str_isint(split[2]) == 1))
	{
		ft_split_free(split);
		error_msg(msg_nbr, scene, 0);
	}
	rgb.r = ft_atoi(split[0]);
	rgb.g = ft_atoi(split[1]);
	rgb.b = ft_atoi(split[2]);
	ft_split_free(split);
	if (ft_isrgb(rgb.r) == 0 || ft_isrgb(rgb.g) == 0 ||
			ft_isrgb(rgb.b) == 0)
		error_msg(msg_nbr, scene, 0);
	return (rgb);
}
