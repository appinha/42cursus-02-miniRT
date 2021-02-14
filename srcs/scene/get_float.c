/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:51:35 by appinha           #+#    #+#             */
/*   Updated: 2021/02/14 19:32:19 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

bool	ft_str_isfloat(char *str)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (!(ft_isdigit(str[i]) == true || str[i] == '-' || str[i] == '+' ||
							str[i] == '.'))
			return (false);
		i++;
	}
	return (true);
}

double	get_float(char *str, char *code)
{
	if (ft_str_isfloat(str) == false)
		error_msg_and_exit(code);
	return (ft_atof(str));
}

double	get_ratio(char *str, char *code)
{
	double	nbr;

	nbr = get_float(str, code);
	if (!(nbr >= 0.0 && nbr <= 1.0))
		error_msg_and_exit(code);
	return (nbr);
}

double	get_size(char *str, char *code)
{
	double	nbr;

	nbr = get_float(str, code);
	if (!(nbr > 0.0))
		error_msg_and_exit(code);
	return (nbr);
}
