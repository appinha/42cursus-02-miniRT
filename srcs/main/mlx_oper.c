/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:16:49 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/15 12:44:35 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"

int			mlx_exit(t_rt *rt)
{
	if (rt->win)
	{
		mlx_clear_window(rt->mlx, rt->win);
		mlx_destroy_window(rt->mlx, rt->win);
	}
	while (rt->scene.cam->prev)
		rt->scene.cam = rt->scene.cam->prev;
	while (rt->scene.cam && rt->scene.cam->img.ptr)
	{
		mlx_destroy_image(rt->mlx, rt->scene.cam->img.ptr);
		rt->scene.cam = rt->scene.cam->next;
	}
	if (rt->save == false)
		ft_printf("%s", MSG_WIN_QUIT);
	else
		ft_printf("%s", MSG_SAVE_QUIT);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	cam_change(t_rt *rt, int step)
{
	t_cam	*cam_orig;

	cam_orig = rt->scene.cam;
	if (step > 0)
		while (step-- && rt->scene.cam->next)
			rt->scene.cam = rt->scene.cam->next;
	else if (step < 0)
		while (step++ && rt->scene.cam->prev)
			rt->scene.cam = rt->scene.cam->prev;
	if (rt->scene.cam != cam_orig)
	{
		ft_printf("Changing camera... ");
		if (rt->scene.cam->img.ptr == NULL)
			render_img(rt, rt->scene.cam);
		else
			mlx_put_image_to_window(rt->mlx, rt->win, rt->scene.cam->img.ptr,
									0, 0);
		ft_printf("Done!\n");
	}
	else
		ft_printf("No more cameras in this direction.\n");
}

int			mlx_deal_key(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		mlx_exit(param);
	else if (keycode == KEY_CAM_R)
		cam_change(param, 1);
	else if (keycode == KEY_CAM_L)
		cam_change(param, -1);
	return (0);
}

int			expose_hook(t_rt *rt)
{
	return (mlx_put_image_to_window(rt->mlx, rt->win, rt->scene.cam->img.ptr,
									0, 0));
}

void		mlx_put_pixel2img(t_img *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->size + x * (img->bpp / 8));
	*(unsigned int*)dst = colour;
}
