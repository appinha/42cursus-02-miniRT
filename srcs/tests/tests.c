#include "minirt.h"

void	print_triage_scene_info(t_scene *scene)
{
	int		i;
	t_elem	*ptr_cam;
	t_elem	*ptr_light;
	t_elem	*ptr_sp;
	t_elem	*ptr_pl;

	ft_printf("\n	• GET SCENE INFO •\n");
	ft_printf("Resolution:  %i   %i\n", scene->resol.x, scene->resol.y);
	ft_printf("Ambient Light:  %.1f   %i,%i,%i\n", scene->amb_li.ratio,
				scene->amb_li.rgb.r, scene->amb_li.rgb.g, scene->amb_li.rgb.b);
	i = 1;
	ptr_cam = scene->cam;
	while (ptr_cam != NULL)
	{
		ft_printf("Camera %i:  %.0f,%.0f,%.0f   %.0f,%.0f,%.0f   %i\n", i,
				ptr_cam->coord.x, ptr_cam->coord.y, ptr_cam->coord.z,
				ptr_cam->normal.x, ptr_cam->normal.y, ptr_cam->normal.z,
				ptr_cam->fov);
		ptr_cam = ptr_cam->next;
		i++;
	}
	i = 1;
	ptr_light = scene->light;
	while (ptr_light != NULL)
	{
		ft_printf("Light %i:  %.0f,%.0f,%.0f   %.1f   %i,%i,%i\n", i,
				ptr_light->coord.x, ptr_light->coord.y, ptr_light->coord.z,
				ptr_light->ratio,
				ptr_light->rgb.r, ptr_light->rgb.g, ptr_light->rgb.b);
		ptr_light = ptr_light->next;
		i++;
	}
	i = 1;
	ptr_sp = scene->sp;
	while (ptr_sp != NULL)
	{
		ft_printf("Sphere %i:  %.0f,%.0f,%.0f   %.1f   %i,%i,%i\n", i,
				ptr_sp->coord.x, ptr_sp->coord.y, ptr_sp->coord.z,
				ptr_sp->diam,
				ptr_sp->rgb.r, ptr_sp->rgb.g, ptr_sp->rgb.b);
		ptr_sp = ptr_sp->next;
		i++;
	}
	i = 1;
	ptr_pl = scene->pl;
	while (ptr_pl != NULL)
	{
		ft_printf("Plane %i:  %.0f,%.0f,%.0f   %.1f   %i,%i,%i\n", i,
				ptr_pl->coord.x, ptr_pl->coord.y, ptr_pl->coord.z,
				ptr_pl->diam,
				ptr_pl->rgb.r, ptr_pl->rgb.g, ptr_pl->rgb.b);
		ptr_pl = ptr_pl->next;
		i++;
	}
	ft_printf("\n");
}

void	test_put_heart(t_img *img, int offset_x, int offset_y, int ratio)
{
	int		img_heart[6][7] = {
		{0, 1, 1, 0, 1, 1, 0},
		{1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 0}
	};
	int		img_x;
	int		img_y;
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;
	int		r_x;
	int		r_y;

	r_x = ratio;
	r_y = ratio;
	img_x = 6 * ratio;
	img_y = 5 * ratio;
	pos_y = 0;
	y = offset_y;
	while (y <= img_y + offset_y)
	{
		x = offset_x;
		pos_x = 0;
		while (x <= img_x + offset_x)
		{
			r_y = ratio;
			while (r_y > 0)
			{
				r_x = ratio;
				while (r_x > 0)
				{
					if (img_heart[pos_y][pos_x] == 1)
						pixel_put(img, x, y, 0x00FF0000);
					x++;
					r_x--;
					if (r_x == 0)
						x -= ratio;
				}
				y++;
				r_y--;
				if (r_y == 0)
					y -= ratio;
			}
			pos_x++;
			x += ratio;
		}
		pos_y++;
		y += ratio;
	}
}

void	test_put_mult_hearts(t_scene *scene, t_img *img, int offset_x, int offset_y, int ratio)
{
	while ((offset_x + 10 + ratio * 7) < scene->resol.x &&
			(offset_y + 10 + ratio * 6) < scene->resol.y)
	{
		test_put_heart(img, offset_x, offset_y, ratio);
		offset_x *= 1.9;
		offset_y *= 1.8;
		ratio++;
	}
}
