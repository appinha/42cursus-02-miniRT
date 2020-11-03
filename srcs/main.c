/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:53:20 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/03 17:43:18 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_file_parse(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'R')
			ft_printf("%s\n", line);
	}
	return (0);
}

int		rt_file_valid(char *file)
{
	char	*ext;

	ext = ft_substr(file, ft_strlen(file) - 3, 3);
	if (ft_strcmp(ext, ".rt") == 0)
		rt_file_parse(file);
	else
		ft_printf("Please provide a valid .rt file\n");
	free(ext);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_img	img;
	int		size_x;
	int		size_y;

	if (!(mlx.ptr = mlx_init()))
		return (-1);
	size_x = 100;
	size_y = 100;
	mlx.win = mlx_new_window(mlx.ptr, size_x, size_y, "miniRT");
	img.ptr = mlx_new_image(mlx.ptr, size_x, size_y);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size, &img.endian);

	rt_file_valid(argv[1]);

	test_put_heart(&img, 25, 25, 6);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);

	mlx_key_hook(mlx.win, deal_key, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
