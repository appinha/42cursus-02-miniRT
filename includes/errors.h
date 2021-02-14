/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:07:24 by appinha           #+#    #+#             */
/*   Updated: 2021/02/14 17:39:41 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define SYSERR		"000"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** FILE: errors.c
*/
void			error_msg_and_exit(char *code);
char			*get_error_code(short int categ, short int elem_id,
						short int err_id);
/*
** FILE: utils.c
*/
void			*malloc_ver(size_t size);
int				open_ver(char *file);
void			close_ver(int fd);

#endif
