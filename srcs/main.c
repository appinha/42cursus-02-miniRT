/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:53:20 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/08 00:22:07 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_get_scene_info(t_scene *scene)
{
	int			i;
	t_cam		*ptr_cam;
	t_light		*ptr_light;
	t_sphere	*ptr_sphere;

	ft_printf("\n	• GET SCENE INFO •\n");
	ft_printf("Resolution:  %i   %i\n", scene->resol.x, scene->resol.y);
	ft_printf("Ambient Light:  %.1f   %i,%i,%i\n", scene->amb_li.ratio,
				scene->amb_li.rgb.r, scene->amb_li.rgb.g, scene->amb_li.rgb.b);
	i = 1;
	ptr_cam = scene->cam;
	while (ptr_cam != NULL)
	{
		ft_printf("Camera %i:  %.1f,%.1f,%.1f   %.0f,%.0f,%.0f   %i\n", i,
				ptr_cam->coord.x, ptr_cam->coord.y, ptr_cam->coord.z,
				ptr_cam->normal.x, ptr_cam->normal.y, ptr_cam->normal.z,
				ptr_cam->fov);
		ptr_cam = ptr_cam->next;
		i++;
	}
	i = 1;
	ptr_light = scene->light;
	while (ptr_light != NULL)
	{
		ft_printf("Light %i:  %.1f,%.1f,%.1f   %.1f   %i,%i,%i\n", i,
				ptr_light->coord.x, ptr_light->coord.y, ptr_light->coord.z,
				ptr_light->ratio,
				ptr_light->rgb.r, ptr_light->rgb.g, ptr_light->rgb.b);
		ptr_light = ptr_light->next;
		i++;
	}
	i = 1;
	ptr_sphere = scene->sphere;
	while (ptr_sphere != NULL)
	{
		ft_printf("Sphere %i:  %.1f,%.1f,%.1f   %.1f   %i,%i,%i\n", i,
				ptr_sphere->coord.x, ptr_sphere->coord.y, ptr_sphere->coord.z,
				ptr_sphere->diam,
				ptr_sphere->rgb.r, ptr_sphere->rgb.g, ptr_sphere->rgb.b);
		ptr_sphere = ptr_sphere->next;
		i++;
	}
	ft_printf("\n");
}

void	get_scene_info(t_scene *scene)
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
			ft_printf("%s\n", scene->line);
		if (ft_strncmp(scene->line, "cy", 2) == 0)
			ft_printf("%s\n", scene->line);
		if (ft_strncmp(scene->line, "tr", 2) == 0)
			ft_printf("%s\n", scene->line);
	}
	free(scene->line);
	print_get_scene_info(scene);
}

void	init_scene(t_scene *scene)
{
	scene->line = NULL;
	scene->split = NULL;
	scene->qtys.resol = 0;
	scene->qtys.amb_li = 0;
	scene->qtys.cam = 0;
	scene->qtys.light = 0;
	scene->qtys.sphere = 0;
	scene->qtys.plane = 0;
	scene->qtys.square = 0;
	scene->qtys.cylind = 0;
	scene->qtys.triang = 0;
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
		init_scene(scene);
		scene->fd = open(file, O_RDONLY);
		if (scene->fd > 2)
		{
			get_scene_info(scene);
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
