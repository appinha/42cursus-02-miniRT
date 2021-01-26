/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:16:49 by apuchill          #+#    #+#             */
/*   Updated: 2021/01/26 11:10:26 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"

void	init_mlx(t_rt *rt)
{
	if (!(rt->mlx = mlx_init()))
		error_msg_and_exit(SYSERR);
	mlx_get_screen_size(rt->mlx, &rt->size_x, &rt->size_y);
	if (rt->scene.resol.x < rt->size_x && rt->save == 0)
		rt->size_x = rt->scene.resol.x;
	if (rt->scene.resol.y < rt->size_y && rt->save == 0)
		rt->size_y = rt->scene.resol.y;
	rt->win = mlx_new_window(rt->mlx, rt->size_x, rt->size_y, NAME);
}

int		deal_key(int key, void *param)
{
	if (key == KEY_ESC)
		win_close(param);
	return (0);
}

void	win_close(t_rt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	ft_printf("%s", MSG_QUIT);
	exit(0);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
