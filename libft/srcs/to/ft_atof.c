/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:29:59 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/05 15:01:07 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdlib.h>
** SYNOPSIS: convert ASCII string to double
**
** DESCRIPTION:
** 		The atof() function converts the initial portion of the string pointed
**	to by str to double.
*/

#include "libft.h"
#include <math.h>

#include <stdio.h>

double	ft_atof(const char *str)
{
	double	int_part;
	double	dec_part;
	double	sign;
	int		i;

	int_part = 0.0;
	dec_part = 0.0;
	sign = 1.0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1.0;
	while (ft_isdigit(*str))
		int_part = int_part * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			dec_part += (pow(10, i--) * (*str++ - '0'));
	}
	return (sign * (int_part + dec_part));
}
