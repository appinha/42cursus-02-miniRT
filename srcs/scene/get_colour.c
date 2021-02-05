/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:36:57 by appinha           #+#    #+#             */
/*   Updated: 2021/02/04 17:25:47 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "scene.h"

bool	ft_isrgb(int n)
{
	if (n >= 0 && n <= 255)
		return (true);
	return (false);
}

int		get_colour(char *str, char *code)
{
	int		colour;
	int		aux;
	char	**split;
	int		i;

	split = ft_split(str, ',');
	if (ft_strlen_2(split) != 3)
		error_msg_and_exit(code);
	colour = 0;
	i = 0;
	while (i < 3)
	{
		if (ft_str_isint(split[i]) == false)
			error_msg_and_exit(code);
		aux = ft_atoi(split[i]);
		if (ft_isrgb(aux) == false)
			error_msg_and_exit(code);\
		colour = (colour << 8) | aux;
		i++;
	}
	ft_split_free(split);
	return (colour);
}
