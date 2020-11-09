/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:38:39 by appinha           #+#    #+#             */
/*   Updated: 2020/11/08 19:54:37 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_str_isint(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int		ft_str_isfloat(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) == 1 || str[i] == '-' || str[i] == '.'))
			return (0);
		i++;
	}
	return (1);
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
	if (!((*n) >= 0.0 && (*n) <= 1.0))
		error_msg(msg_nbr, scene, 0);
}
