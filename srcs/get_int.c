/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:38:39 by appinha           #+#    #+#             */
/*   Updated: 2020/11/27 17:08:33 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_str_isint(char *str)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0 || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int		get_int(t_scene *scene, char *str, char *msg_nbr)
{
	if (ft_str_isint(str) == 0)
		error_msg(msg_nbr, scene, 0);
	return (ft_atoi(str));
}

int		get_posint(t_scene *scene, char *str, char *msg_nbr)
{
	int		posint;

	posint = get_int(scene, str, msg_nbr);
	if (!(posint > 0))
		error_msg(msg_nbr, scene, 0);
	return (posint);
}

int		get_fov(t_scene *scene, char *str, char *msg_nbr)
{
	int		fov;

	fov = get_int(scene, str, msg_nbr);
	if (!(fov >= 0 && fov <= 180))
		error_msg(msg_nbr, scene, 0);
	return (fov);
}
