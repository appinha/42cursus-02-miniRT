#include "minirt.h"

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
	while(y <= img_y + offset_y)
	{
		x = offset_x;
		pos_x = 0;
		while(x <= img_x + offset_x)
		{
			r_y = ratio;
			while(r_y > 0)
			{
				r_x = ratio;
				while(r_x > 0)
				{
					if(img_heart[pos_y][pos_x] == 1)
						pixel_put(img, x, y, 0x00FF0000);
					x++;
					r_x--;
					if(r_x == 0)
						x -= ratio;
				}
				y++;
				r_y--;
				if(r_y == 0)
					y -= ratio;
			}
			pos_x++;
			x += ratio;
		}
		pos_y++;
		y += ratio;
	}
}
