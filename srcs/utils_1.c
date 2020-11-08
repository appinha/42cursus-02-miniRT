/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:29:22 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/07 01:52:36 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*malloc_ver(size_t size, t_scene *scene, t_mlx *mlx)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		error_msg("900", scene, mlx);
	return (ptr);
}

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

int		ft_isrgb(int n)
{
	if (n >= 0 && n <= 255)
		return (1);
	return (0);
}

int		ft_isratio(double n)
{
	if (n >= 0.0 && n <= 1.0)
		return (1);
	return (0);
}

int		ft_isnormal(t_tuple normal)
{
	if (normal.x >= -1.0 && normal.x <= 1.0 &&
			normal.y >= -1.0 && normal.y <= 1.0 &&
			normal.z >= -1.0 && normal.z <= 1.0)
		return (1);
	return (0);
}
