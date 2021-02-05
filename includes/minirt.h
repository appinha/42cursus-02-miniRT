/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:55:22 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/05 10:45:06 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
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
# define MSG_QUIT	"Exiting miniRT. À bientôt !\n\n"

# define EPSILON	0.0001
# define ALBEDO		1000

typedef enum	e_type {
	__NULL,
	SPHERE,
	PLANE,
	SQUARE,
	TRIANGLE,
	CYLINDER
}				t_type;

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
	float		dot;
	t_coord		coord;
	t_coord		normal;
	t_type		obj_type;
	void		*obj;
	int			colour;
}				t_hit;

typedef struct	s_ray
{
	t_coord		coord;
	t_coord		normal;
	t_hit		hit;
}				t_ray;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** FILE: mlx_oper.c
*/
void			init_mlx(t_rt *rt);
void			run_mlx(t_rt *rt);
void			win_close(t_rt *rt);
void			pixel_put(t_img *img, int x, int y, int colour);
/*
** FILE: raytrace.c
*/
int				raytrace(t_rt *rt, t_ray *ray);
t_coord			ray_at(t_ray ray);
/*
** FILE: hit.c
*/
bool			hit_pl(t_ray *ray, t_elem *pl);
/*
** FILE: colours.c
*/
int				c_scale(int colour, float c);
int				c_prod(int c1, int c2);
int				c_add(int c1, int c2);
/*
** FILE: colours_light.c
*/
int				c_comp(t_elem *light, t_hit hit);

#endif
