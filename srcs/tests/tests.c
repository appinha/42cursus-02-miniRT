#include "minirt.h"

void	print_triage_scene_info(t_scene *scene)
{
	int		i;
	t_elem	*ptr_cam;
	t_elem	*ptr_light;
	t_elem	*ptr_sp;
	t_elem	*ptr_pl;
	t_elem	*ptr_tr;

	ft_printf("\n	• GET SCENE INFO •\n\n");

	ft_printf("Resolution:  %i   %i\n", scene->resol.x, scene->resol.y);
	ft_printf("Ambient Light:  %.1f   %x\n", scene->amb_li.ratio,
				scene->amb_li.colour);
	i = 1;
	ptr_cam = scene->cam;
	while (ptr_cam)
	{
		ft_printf("Camera %i:  %.0f,%.0f,%.0f   %.0f,%.0f,%.0f   %i\
				hor.x: %.1f\n", i,
				ptr_cam->point.x, ptr_cam->point.y, ptr_cam->point.z,
				ptr_cam->normal.x, ptr_cam->normal.y, ptr_cam->normal.z,
				ptr_cam->cam.fov,
				ptr_cam->cam.hor.x);
		ptr_cam = ptr_cam->next;
		i++;
	}
	i = 1;
	ptr_light = scene->light;
	while (ptr_light != NULL)
	{
		ft_printf("Light %i:  %.0f,%.0f,%.0f   %.1f   %x\n", i,
				ptr_light->point.x, ptr_light->point.y, ptr_light->point.z,
				ptr_light->ratio,
				ptr_light->colour);
		ptr_light = ptr_light->next;
		i++;
	}
	i = 1;
	ptr_sp = scene->sp;
	while (ptr_sp != NULL)
	{
		ft_printf("Sphere %i:  %.0f,%.0f,%.0f   %.1f   %x\n", i,
				ptr_sp->point.x, ptr_sp->point.y, ptr_sp->point.z,
				ptr_sp->diam,
				ptr_sp->colour);
		ptr_sp = ptr_sp->next;
		i++;
	}
	i = 1;
	ptr_pl = scene->pl;
	while (ptr_pl != NULL)
	{
		ft_printf("Plane %i:  %.0f,%.0f,%.0f   %.1f   %x\n", i,
				ptr_pl->point.x, ptr_pl->point.y, ptr_pl->point.z,
				ptr_pl->diam,
				ptr_pl->colour);
		ptr_pl = ptr_pl->next;
		i++;
	}
	i = 1;
	ptr_tr = scene->tr;
	while (ptr_tr != NULL)
	{
		ft_printf("Triangle %i:  %.0f,%.0f,%.0f  %.0f,%.0f,%.0f  %.0f,%.0f,%.0f   %x\n", i,
				ptr_tr->tr.p1.x, ptr_tr->tr.p1.y, ptr_tr->tr.p1.z,
				ptr_tr->tr.p2.x, ptr_tr->tr.p2.y, ptr_tr->tr.p2.z,
				ptr_tr->tr.p3.x, ptr_tr->tr.p3.y, ptr_tr->tr.p3.z,
				ptr_tr->colour);
		ptr_tr = ptr_tr->next;
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
