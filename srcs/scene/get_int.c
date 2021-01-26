/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:38:39 by appinha           #+#    #+#             */
/*   Updated: 2021/01/26 11:11:47 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "scene.h"

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

int		get_int(char *str, char *code)
{
	if (ft_str_isint(str) == 0)
		error_msg_and_exit(code);
	return (ft_atoi(str));
}

int		get_posint(char *str, char *code)
{
	int		posint;

	posint = get_int(str, code);
	if (!(posint > 0))
		error_msg_and_exit(code);
	return (posint);
}

int		get_fov(char *str, char *code)
{
	int		fov;

	fov = get_int(str, code);
	if (!(fov >= 0 && fov <= 180))
		error_msg_and_exit(code);
	return (fov);
}
