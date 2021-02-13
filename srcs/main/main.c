/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:53:20 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/13 19:17:59 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"
#include "scene.h"
#include "tests.h"

// static void	export_bpm()
// {
// 	a
// }

void		render_img(t_rt *rt)
{
	int		x;
	int		y;
	t_ray	ray;
	int		colour;

	if (!rt->scene.cam)
		return ;
	y = -1;
	while (y++ < (rt->size_y - 1))
	{
		x = -1;
		while (x++ < (rt->size_x - 1))
		{
			ray = gen_ray(rt->scene.cam, (float)x / rt->size_x,
										(float)y / rt->size_y);
			colour = raytrace(rt, &ray);
			mlx_put_pixel2img(&rt->img, x, (rt->size_y - 1) - y, colour);
		}
	}
	if (rt->save == false)
		mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);

}

static void	run_mlx_win(t_rt *rt)
{
	mlx_key_hook(rt->win, mlx_deal_key, rt);
	mlx_hook(rt->win, DestroyNotify, StructureNotifyMask, mlx_win_close, rt);
	mlx_loop(rt->mlx);
}

static void	init_mlx(t_rt *rt)
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
	// print_triage_scene_info(&rt.scene);
	init_mlx(&rt);
	render_img(&rt);
	if (rt.save == false)
		run_mlx_win(&rt);
	// else
	// 	export_bpm();
	return (0);
}
