/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:29:22 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/08 19:53:51 by appinha          ###   ########.fr       */
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

int		ft_isnormal(t_tuple normal)
{
	if (normal.x >= -1.0 && normal.x <= 1.0 &&
			normal.y >= -1.0 && normal.y <= 1.0 &&
			normal.z >= -1.0 && normal.z <= 1.0)
		return (1);
	return (0);
}
