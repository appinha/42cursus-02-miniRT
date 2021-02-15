/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:53:20 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/15 12:46:36 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "minirt.h"
#include "bitmap.h"

static void	run_mlx_window(t_rt *rt)
{
	ft_printf("%s%s", MSG_WIN_USE_1, MSG_WIN_USE_2);
	mlx_key_hook(rt->win, mlx_deal_key, rt);
	mlx_hook(rt->win, DestroyNotify, StructureNotifyMask, mlx_exit, rt);
	mlx_expose_hook(rt->win, expose_hook, rt);
	mlx_loop(rt->mlx);
}

void		render_img(t_rt *rt, t_cam *cam)
{
	int		x;
	int		y;
	t_ray	ray;
	int		colour;

	if (!cam)
		return ;
	if (!(cam->img.ptr = mlx_new_image(rt->mlx, rt->size_x, rt->size_y)) ||
		!(cam->img.addr = mlx_get_data_addr(cam->img.ptr, &cam->img.bpp,
					&cam->img.size, &cam->img.endian)))
		error_msg_and_exit(SYSERR);
	y = -1;
	while (y++ < (rt->size_y - 1))
	{
		x = -1;
		while (x++ < (rt->size_x - 1))
		{
			ray = gen_ray(cam, (float)x / rt->size_x, (float)y / rt->size_y);
			colour = raytrace(rt, &ray);
			mlx_put_pixel2img(&cam->img, x, (rt->size_y - 1) - y, colour);
		}
	}
	if (rt->save == false)
		mlx_put_image_to_window(rt->mlx, rt->win, cam->img.ptr, 0, 0);
}

static void	save_bitmaps(t_rt *rt)
{
	t_cam	*cam;
	char	*filename;
	char	*aux;
	int		i;

	cam = rt->scene.cam;
	i = 1;
	while (cam)
	{
		if (cam->img.ptr == NULL)
			render_img(rt, cam);
		aux = ft_itoa(i);
		filename = ft_strjoin(aux, ".bmp");
		free(aux);
		if (export_bitmap(filename, rt->size_x, rt->size_y, cam->img) < 0)
			error_msg_and_exit(SYSERR);
		free(filename);
		cam = cam->next;
		i++;
	}
	mlx_exit(rt);
}

static void	init_mlx(t_rt *rt)
{
	if (!(rt->mlx = mlx_init()))
		error_msg_and_exit(SYSERR);
	if (rt->save == false)
	{
		ft_printf("%s", MSG_WIN_START);
		mlx_get_screen_size(rt->mlx, &rt->size_x, &rt->size_y);
		if (rt->scene.resol.x < rt->size_x)
			rt->size_x = rt->scene.resol.x;
		if (rt->scene.resol.y < rt->size_y)
			rt->size_y = rt->scene.resol.y;
		rt->win = mlx_new_window(rt->mlx, rt->size_x, rt->size_y, NAME);
	}
	else
	{
		ft_printf("%s", MSG_SAVE_START);
		rt->size_x = rt->scene.resol.x;
		rt->size_y = rt->scene.resol.y;
		rt->win = NULL;
	}
}

int			main(int argc, char *argv[])
{
	t_rt	rt;

	if (argc < 2)
		error_msg_and_exit("001");
	if (argc > 3)
		error_msg_and_exit("002");
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7) != 0)
		error_msg_and_exit("003");
	rt.save = (argc == 3);
	init_scene(argv[1], &rt.scene);
	init_mlx(&rt);
	render_img(&rt, rt.scene.cam);
	if (rt.save == false)
		run_mlx_window(&rt);
	else
		save_bitmaps(&rt);
	return (0);
}
