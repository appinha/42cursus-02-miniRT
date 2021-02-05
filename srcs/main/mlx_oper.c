/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:16:49 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/05 09:47:20 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"

void		init_mlx(t_rt *rt)
{
	if (!(rt->mlx = mlx_init()))
		error_msg_and_exit(SYSERR);
	mlx_get_screen_size(rt->mlx, &rt->size_x, &rt->size_y);
	if (rt->save == false)
	{
		if (rt->scene.resol.x < rt->size_x)
			rt->size_x = rt->scene.resol.x;
		if (rt->scene.resol.y < rt->size_y)
			rt->size_y = rt->scene.resol.y;
	}
	rt->win = mlx_new_window(rt->mlx, rt->size_x, rt->size_y, NAME);
	rt->img.ptr = mlx_new_image(rt->mlx, rt->size_x, rt->size_x);
	rt->img.addr = mlx_get_data_addr(rt->img.ptr, &rt->img.bpp, &rt->img.size,
					&rt->img.endian);
}

static int	deal_key(int key, void *param)
{
	if (key == KEY_ESC)
		win_close(param);
	return (0);
}

void		run_mlx(t_rt *rt)
{
	mlx_key_hook(rt->win, deal_key, rt);
	mlx_loop(rt->mlx);
}

void		win_close(t_rt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	ft_printf("%s", MSG_QUIT);
	exit(0);
}

void		pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->size + x * (img->bpp / 8));
	*(unsigned int*)dst = colour;
}
