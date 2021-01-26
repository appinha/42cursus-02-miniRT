/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:53:20 by apuchill          #+#    #+#             */
/*   Updated: 2021/01/26 11:34:54 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"
#include "scene.h"

int		main(int argc, char *argv[])
{
	t_rt	rt;

	if (argc < 2)
		error_msg_and_exit("001");
	if (argc > 3)
		error_msg_and_exit("002");
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7) != 0)
		error_msg_and_exit("003");
	rt.save = (argc == 3);
	init_scene(argv[1], &rt.scene);
	init_mlx(&rt);
	render_img(&rt);
	mlx_key_hook(rt.win, deal_key, &rt);
	mlx_loop(rt.mlx);
	return (0);
}
