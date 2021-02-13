/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:16:49 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/13 20:37:51 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "errors.h"

int			mlx_win_close(t_rt *rt)
{
	mlx_clear_window(rt->mlx, rt->win);
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_destroy_image(rt->mlx, rt->img.ptr);
	ft_printf("%s", MSG_QUIT);
	exit(0);
	return(0);
}

static void	cam_change(t_rt *rt, int step)
{
	t_elem	**cam;

	ft_printf("Changing camera...\n");
	cam = &(rt->scene.cam);
	if (step > 0)
		while (step-- && (*cam)->next)
			*cam = ((*cam)->next);
	else if (step < 0)
		while (step++ && (*cam)->prev)
			*cam = ((*cam)->prev);
	render_img(rt);
}

int			mlx_deal_key(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		mlx_win_close(param);
	else if (keycode == KEY_CAM_R)
		cam_change(param, 1);
	else if (keycode == KEY_CAM_L)
		cam_change(param, -1);
	return (0);
}

void		mlx_put_pixel2img(t_img *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->size + x * (img->bpp / 8));
	*(unsigned int*)dst = colour;
}
