/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:09:42 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/16 12:07:44 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

char		*get_error_code(short int category, short int elem_id,
							short int err_id)
{
	char	*code;

	code = malloc_ver(4 * sizeof(char));
	code[0] = category + '0';
	code[1] = elem_id + '0';
	code[2] = err_id + '0';
	code[3] = '\0';
	return (code);
}

static void	print_error_msg(char *code)
{
	int		fd;
	char	*msg;

	fd = open_ver("srcs/errors/errors.txt");
	while (get_next_line(fd, &msg) == 1)
	{
		if (ft_strncmp(code, msg, 3) == 0)
		{
			ft_putstr_fd("\033[1m\033[38;5;199mError\033[0m\n", STDERR_FILENO);
			ft_putstr_fd(msg, STDERR_FILENO);
			ft_putchar_fd('\n', STDERR_FILENO);
			break ;
		}
		free(msg);
	}
	free(msg);
	close_ver(fd);
}

void		error_msg_and_exit(char *code)
{
	if (errno && ft_strcmp(code, SYSERR) == 0)
		perror("\033[1m\033[38;5;199mSystem error\033[0m");
	else if (code != SYSERR)
		print_error_msg(code);
	else
		ft_putstr_fd("Fatal Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
