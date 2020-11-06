/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:29:22 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/05 21:04:07 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*malloc_ver(size_t size, t_mlx *mlx)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		error_msg("900", 0, mlx);
	return (ptr);
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
