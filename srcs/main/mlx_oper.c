/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:16:49 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/13 18:27:45 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"

void		init_mlx(t_rt *rt)
{
	ft_printf("%s", MSG_START);
	if (!(rt->mlx = mlx_init()))
		error_msg_and_exit(SYSERR);
	if (rt->save == false)
	{
		mlx_get_screen_size(rt->mlx, &rt->size_x, &rt->size_y);
		if (rt->scene.resol.x < rt->size_x)
			rt->size_x = rt->scene.resol.x;
		if (rt->scene.resol.y < rt->size_y)
			rt->size_y = rt->scene.resol.y;
	}
	else
	{
		rt->size_x = rt->scene.resol.x;
		rt->size_y = rt->scene.resol.y;
	}
	rt->win = mlx_new_window(rt->mlx, rt->size_x, rt->size_y, NAME);
	if (!(rt->img.ptr = mlx_new_image(rt->mlx, rt->size_x, rt->size_x)) ||
		!(rt->img.addr = mlx_get_data_addr(rt->img.ptr, &rt->img.bpp,
					&rt->img.size, &rt->img.endian)))
		error_msg_and_exit(SYSERR);
}

static int		win_close(t_rt *rt)
{
	mlx_clear_window(rt->mlx, rt->win);
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_destroy_image(rt->mlx, rt->img.ptr);
	ft_printf("%s", MSG_QUIT);
	exit(0);
	return(0);
}

static int	deal_key(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		win_close(param);
	// else if (keycode == KEY_CAM_R)
	// 	cam_change(param, 1);
	// else if (keycode == KEY_CAM_L)
	// 	cam_change(param, -1);
	return (0);
}

void		run_mlx_win(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
	mlx_key_hook(rt->win, deal_key, rt);
	mlx_hook(rt->win, DestroyNotify, StructureNotifyMask, win_close, rt);
	mlx_loop(rt->mlx);
}

void		pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->size + x * (img->bpp / 8));
	*(unsigned int*)dst = colour;
}
