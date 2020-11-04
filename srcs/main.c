/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:53:20 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/03 23:02:02 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_split_free(char **split)
{
	int		i;

	i = 0;
	while (i < ft_strlen(*split))
		free(split[i++]);
	free(split);
}

void	get_resol(char *line)
{
	t_resol	resol;
	char	**split;

	split = ft_split(line, ' ');
	resol.x_width = ft_atoi(split[1]);
	resol.y_height = ft_atoi(split[2]);
	ft_split_free(split);
}

void	get_rt_file_info(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "R", 1) == 0)
			get_resol(line);
		if (ft_strncmp(line, "A", 1) == 0)
			ft_printf("%s\n", line);
		if (ft_strncmp(line, "c", 1) == 0)
			ft_printf("%s\n", line);
		if (ft_strncmp(line, "l", 1) == 0)
			ft_printf("%s\n", line);
	}
	close (fd);
}

int		check_rt_file(char *file)
{
	char	*ext;

	ext = ft_substr(file, ft_strlen(file) - 3, 3);
	if (ft_strcmp(ext, ".rt") == 0)
		get_rt_file_info(file);
	else
		error_msg(ERR_02, 0);
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
		error_msg(ERR_01, 0);
	check_rt_file(argv[1]);

	size_x = 100;
	size_y = 100;
	mlx.win = mlx_new_window(mlx.ptr, size_x, size_y, "miniRT");
	img.ptr = mlx_new_image(mlx.ptr, size_x, size_y);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size, &img.endian);


	test_put_heart(&img, 25, 25, 6);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);

	mlx_key_hook(mlx.win, deal_key, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
