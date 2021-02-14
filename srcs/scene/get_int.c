/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:38:39 by appinha           #+#    #+#             */
/*   Updated: 2021/02/14 19:32:22 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

bool			ft_str_isint(char *str)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0 || str[i] == '-')
			return (false);
		i++;
	}
	return (true);
}

int				get_int(char *str, char *code)
{
	if (ft_str_isint(str) == false)
		error_msg_and_exit(code);
	return (ft_atoi(str));
}

int				get_posint(char *str, char *code)
{
	int		posint;

	posint = get_int(str, code);
	if (!(posint > 0))
		error_msg_and_exit(code);
	return (posint);
}

static float	deg2rad(float deg)
{
	return ((M_PI / 180) * deg);
}

float			get_fov(char *str, char *code)
{
	float	fov;

	fov = get_int(str, code);
	if (!(fov >= 0 && fov <= 180))
		error_msg_and_exit(code);
	fov = deg2rad(fov);
	return (fov);
}
