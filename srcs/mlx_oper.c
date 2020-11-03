/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:16:49 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/02 16:17:20 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		deal_key(int key, void *param)
{
	ft_putnbr(key);
	if (key == 65307)
		win_close(param);
	return (0);
}

void	win_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
