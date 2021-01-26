/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:30:41 by appinha           #+#    #+#             */
/*   Updated: 2021/01/26 12:52:17 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"
#include "tests.h"

void	render_img(t_rt *rt)
{
	rt->img.ptr = mlx_new_image(rt->mlx, rt->size_x, rt->size_x);
	rt->img.addr = mlx_get_data_addr(rt->img.ptr, &rt->img.bpp, &rt->img.size,
					&rt->img.endian);
	test_put_mult_hearts(&rt->scene, &rt->img, 10, 10, 1);
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
}
