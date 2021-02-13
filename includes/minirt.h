/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:55:22 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/13 20:37:26 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <X11/X.h>
# include <stdbool.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "scene.h"
# include "vectors.h"

# include <stdio.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define NAME		"miniRT"
# define KEY_ESC	65307
# define KEY_CAM_R	65363
# define KEY_CAM_L	65361
# define MSG_START	"\nBonjour ! The scene will be rendered very soon.\n"
# define MSG_QUIT	"\nExiting miniRT. À bientôt !\n"

# define EPSILON	0.0001
# define ALBEDO		1000

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct	s_rt
{
	bool		save;
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	t_img		img;
	t_scene		scene;
}				t_rt;

typedef struct	s_hit
{
	float		time;
	t_coord		point;
	t_coord		normal;
	void		*obj;
	int			colour;
}				t_hit;

typedef struct	s_ray
{
	t_coord		p_ori;
	t_coord		v_dir;
	t_hit		hit;
}				t_ray;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** FILE: main.c
*/
void			render_img(t_rt *rt);
/*
** FILE: mlx_oper.c
*/
int				mlx_win_close(t_rt *rt);
int				mlx_deal_key(int keycode, void *param);
void			mlx_put_pixel2img(t_img *img, int x, int y, int colour);
/*
** FILE: raytrace.c
*/
int				raytrace(t_rt *rt, t_ray *ray);
t_ray			gen_ray(t_elem *cam, float x, float y);
/*
** FILE: hit_1.c
*/
t_coord			get_hit_point(t_ray ray);
bool			hit_sp(t_ray *ray, t_elem *elem);
bool			hit_cy(t_ray *ray, t_elem *elem);
/*
** FILE: hit_2.c
*/
bool			hit_pl(t_ray *ray, t_elem *elem);
bool			hit_polyg(t_ray *ray, t_elem *elem);
/*
** FILE: colours.c
*/
int				c_scale(int colour, float c);
int				c_prod(int c1, int c2);
int				c_add(int c1, int c2);
int				c_comp(t_elem *light, t_hit hit);

#endif
