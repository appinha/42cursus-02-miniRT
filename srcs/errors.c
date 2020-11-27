/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:09:42 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/27 20:22:49 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		get_error_msg_nbr(short int categ, short int elem_id,
				short int err_id, char **msg_nbr)
{
	char	new_msg[4];

	new_msg[0] = categ + '0';
	new_msg[1] = elem_id + '0';
	new_msg[2] = err_id + '0';
	new_msg[3] = '\0';
	*msg_nbr = new_msg;
}

static void	print_error_msg(char *msg_nbr)
{
	int		ret;
	int		fd;
	char	*line;
	char	*msg;

	fd = open("srcs/errors.txt", O_RDONLY);
	if (fd > 2)
	{
		ret = 1;
		while (ret == 1)
		{
			ret = get_next_line(fd, &line);
			if (ft_strncmp(msg_nbr, line, 3) == 0)
			{
				msg = ft_substr(line, 4, ft_strlen(line) - 4);
				ft_printf("\033[1m\033[38;5;199mERROR:\033[0m %s\n", msg);
				free(msg);
				free(line);
				break ;
			}
			free(line);
		}
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
