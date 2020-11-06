/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:53:20 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/05 22:00:03 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_scene_info(t_scene *scene)
{
	while (get_next_line(scene->fd, &scene->line) > 0)
	{
		if (ft_strncmp(scene->line, "R", 1) == 0)
			get_scene_resol(scene);
		if (ft_strncmp(scene->line, "A", 1) == 0)
			get_scene_amb_li(scene);
		if (ft_strncmp(scene->line, "c", 1) == 0)
			ft_printf("%s\n", scene->line);
		if (ft_strncmp(scene->line, "l", 1) == 0)
			ft_printf("%s\n", scene->line);
		if (ft_strncmp(scene->line, "sp", 2) == 0)
			ft_printf("%s\n", scene->line);
		if (ft_strncmp(scene->line, "pl", 2) == 0)
			ft_printf("%s\n", scene->line);
		if (ft_strncmp(scene->line, "sq", 2) == 0)
			ft_printf("%s\n", scene->line);
		if (ft_strncmp(scene->line, "cy", 2) == 0)
			ft_printf("%s\n", scene->line);
		if (ft_strncmp(scene->line, "tr", 2) == 0)
			ft_printf("%s\n", scene->line);
	}
	free(scene->line);
}

void	init_scene_qtys(t_scene *scene)
{
	scene->qtys.resol = 0;
	scene->qtys.amb_li = 0;
	scene->qtys.cam = 0;
	scene->qtys.light = 0;
	scene->qtys.sp = 0;
	scene->qtys.pl = 0;
	scene->qtys.sq = 0;
	scene->qtys.cy = 0;
	scene->qtys.tr = 0;
}

void	parse_rt_file(char *file, t_scene *scene)
{
	char	*ext;
	int		cmp;

	ext = ft_substr(file, ft_strlen(file) - 3, 3);
	cmp = ft_strcmp(ext, ".rt");
	free(ext);
	if (cmp == 0)
	{
		scene->fd = open(file, O_RDONLY);
		init_scene_qtys(scene);
		get_scene_info(scene);
		close(scene->fd);
	}
	else
		error_msg("100", 0, 0);
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
	parse_rt_file(argv[1], &scene);
	mlx.win = mlx_new_window(mlx.ptr, scene.resol.x, scene.resol.y, "miniRT");
	img.ptr = mlx_new_image(mlx.ptr, scene.resol.x, scene.resol.y);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size, &img.endian);
	test_put_heart(&img, 25, 25, 6);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);
	mlx_key_hook(mlx.win, deal_key, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
