/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:51:35 by appinha           #+#    #+#             */
/*   Updated: 2020/11/27 16:51:53 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_str_isfloat(char *str)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (!(ft_isdigit(str[i]) == 1 || str[i] == '-' || str[i] == '.'))
			return (0);
		i++;
	}
	return (1);
}

double	get_float(t_scene *scene, char *str, char *msg_nbr)
{
	if (ft_str_isfloat(str) == 0)
		error_msg(msg_nbr, scene, 0);
	return (ft_atof(str));
}

double	get_ratio(t_scene *scene, char *str, char *msg_nbr)
{
	double	nbr;

	nbr = get_float(scene, str, msg_nbr);
	if (!(nbr >= 0.0 && nbr <= 1.0))
		error_msg(msg_nbr, scene, 0);
	return (nbr);
}

double	get_size(t_scene *scene, char *str, char *msg_nbr)
{
	double	nbr;

	nbr = get_float(scene, str, msg_nbr);
	if (!(nbr > 0.0))
		error_msg(msg_nbr, scene, 0);
	return (nbr);
}
