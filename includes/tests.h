#ifndef TESTS_H
# define TESTS_H

# include "minirt.h"

// !!! APAGAR !!! TEST FUNCTIONS
void			test_put_heart(t_img *img, int offset_x, int offset_y,
							int ratio);
void			test_put_mult_hearts(t_scene *scene, t_img *img,
							int offset_x, int offset_y, int ratio);
void			print_triage_scene_info(t_scene *scene);


#endif