/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:09:42 by apuchill          #+#    #+#             */
/*   Updated: 2021/01/26 12:19:22 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

char		*get_error_code(short int categ, short int elem_id, short int err_id)
{
	char	*code;

	code = malloc_ver(4 * sizeof(char));
	code[0] = categ + '0';
	code[1] = elem_id + '0';
	code[2] = err_id + '0';
	code[3] = '\0';
	return code;
}

static void	print_error_msg(char *code)
{
	int		fd;
	char	*msg;

	if ((fd = open("srcs/errors/errors.txt", O_RDONLY)) < 0)
		error_msg_and_exit(SYSERR);
	while (get_next_line(fd, &msg) == 1)
	{
		if (ft_strncmp(code, msg, 3) == 0)
		{
			ft_putstr_fd("\033[1m\033[38;5;199mERROR: \033[0m", STDERR_FILENO);
			ft_putstr_fd(msg, STDERR_FILENO);
			ft_putchar_fd('\n', STDERR_FILENO);
			break ;
		}
		free(msg);
	}
	free(msg);
	close(fd);
}

void		error_msg_and_exit(char *code)
{
	// ft_printf("errno: %i\n", errno);
	// ft_printf("code: %s\n", code);
	if (errno && ft_strcmp(code, SYSERR) == 0)
		perror("\033[1m\033[38;5;199mSYSTEM ERROR\033[0m");
	else if (code != SYSERR)
		print_error_msg(code);
	else
		ft_putstr_fd("Fatal Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	*malloc_ver(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		error_msg_and_exit(SYSERR);
	return (ptr);
}
