/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:09:42 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/06 22:13:02 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_error_msg(char *msg_nbr)
{
	int		fd;
	char	*line;
	char	*msg;

	fd = open("srcs/errors.txt", O_RDONLY);
	if (fd > 2)
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (ft_strncmp(msg_nbr, line, 3) == 0)
			{
				msg = ft_substr(line, 4, ft_strlen(line) - 4);
				ft_printf("\033[1m\033[38;5;199mERROR:\033[0m %s\n", msg);
				free(msg);
				break ;
			}
		}
		free(line);
		close(fd);
	}
}

void		error_msg(char *msg_nbr, t_scene *scene, t_mlx *mlx)
{
	print_error_msg(msg_nbr);
	if (scene)
	{
		if (scene->fd > 2)
			close(scene->fd);
		if (scene->line)
			free(scene->line);
		if (scene->split)
			ft_split_free(scene->split);
	}
	if (mlx)
		mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}
