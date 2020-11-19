/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:53:20 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/19 18:45:26 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	triage_scene_info(t_scene *scene)
{
	while (get_next_line(scene->fd, &scene->line) > 0)
	{
		if (ft_strncmp(scene->line, "R", 1) == 0)
			get_scene_resol(scene);
		if (ft_strncmp(scene->line, "A", 1) == 0)
			get_scene_amb_li(scene);
		if (ft_strncmp(scene->line, "c", 1) == 0)
			get_scene_cam(scene);
		if (ft_strncmp(scene->line, "l", 1) == 0)
			get_scene_light(scene);
		if (ft_strncmp(scene->line, "sp", 2) == 0)
			get_scene_sphere(scene);
		if (ft_strncmp(scene->line, "pl", 2) == 0)
			get_scene_plane(scene);
		if (ft_strncmp(scene->line, "sq", 2) == 0)
			get_scene_square(scene);
		if (ft_strncmp(scene->line, "cy", 2) == 0)
			get_scene_cylind(scene);
		if (ft_strncmp(scene->line, "tr", 2) == 0)
			get_scene_triang(scene);
	}
	free(scene->line);
	print_triage_scene_info(scene);
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
		//init_scene(scene);
		scene->fd = open(file, O_RDONLY);
		if (scene->fd > 2)
		{
			triage_scene_info(scene);
			close(scene->fd);
		}
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
