/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:29:59 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/05 15:19:54 by apuchill         ###   ########.fr       */
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

double	ft_atof(const char *str)
{
	double	res;
	char	**split;

	split = ft_split(str, '.');
	res = (double)ft_atoi(split[0]);
	res += (double)ft_atoi(split[1]) / ((double)ft_strlen(split[1]) * 10);
	ft_split_free(split);
	return (res);
}
