/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:16:49 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:27 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		deal_key(int key, void *param)
{
	if (key == KEY_ESC)
		win_close(param);
	return (0);
}

void	win_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	ft_printf("%s", MSG_QUIT);
	exit(0);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
