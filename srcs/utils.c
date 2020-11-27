/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:29:22 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/27 17:12:30 by appinha          ###   ########.fr       */
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
