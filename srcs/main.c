/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:53:20 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/27 20:24:37 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	triage_scene_info(t_scene *scene)
{
	static t_arr_sc	ft_scene[9] = {get_scene_0_resol, get_scene_1_amb_li,
		get_scene_2_cam, get_scene_3_light, get_scene_4_sp, get_scene_5_pl,
		get_scene_6_sq, get_scene_7_cy, get_scene_8_tr};
	static char		*elem[9] = {"R ", "A ", "c ", "l ",
								"sp", "pl", "sq", "cy", "tr"};
	int				id;
	int				ret;

	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(scene->fd, &scene->line);
		id = 0;
		while (id < 9 && ft_strncmp(scene->line, elem[id], 2))
			id++;
		if (id < 9)
			get_scene_elem(scene, id, *ft_scene[id]);
		free(scene->line);
	}
	if (scene->qtys[0] == 0 || scene->qtys[1] == 0 || scene->qtys[2] == 0)
		error_msg("013", scene, 0);
	print_triage_scene_info(scene);
}

void	parse_rt_file(char *file, t_scene *scene)
{
	if (ft_strnrcmp(file, ".rt", 3) == 0)
	{
		if ((scene->fd = open(file, O_RDONLY)) > 2)
		{
			triage_scene_info(scene);
			close(scene->fd);
		}
		else
			error_msg("011", 0, 0);
	}
	else
		error_msg("010", 0, 0);
}

int		main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_img	img;
	t_scene	scene;

	if (argc == 1)
		error_msg("000", 0, 0);
	if (argc > 2)
		error_msg("001", 0, 0);
	if (!(mlx.ptr = mlx_init()))
		error_msg("002", 0, 0);
	scene = (t_scene) {0};
	parse_rt_file(argv[1], &scene);
	mlx.win = mlx_new_window(mlx.ptr, scene.resol.x, scene.resol.y, "miniRT");
	img.ptr = mlx_new_image(mlx.ptr, scene.resol.x, scene.resol.y);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size, &img.endian);
	test_put_mult_hearts(&scene, &img, 10, 10, 1);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);
	mlx_key_hook(mlx.win, deal_key, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
