/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:55:22 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/08 19:53:15 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define KEY_ESC	65307

# define MSG_QUIT	"Exiting miniRT. À bientôt !\n\n"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct		s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_tuple
{
	double			x;
	double			y;
	double			z;
	//int				w;
}					t_tuple;

/*
**                              RT file - Scene description
*/
typedef struct		s_resol
{
	int				x;
	int				y;
}					t_resol;

typedef struct		s_elem
{
	t_tuple			coord;
	t_tuple			normal;
	t_tuple			p1;
	t_tuple			p2;
	t_tuple			p3;
	t_rgb			rgb;
	int				fov;
	double			ratio;
	double			diam;
	double			height;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_qtys
{
	int				resol;
	int				amb_li;
	int				cam;
	int				light;
	int				sphere;
	int				plane;
	int				square;
	int				cylind;
	int				triang;
}					t_qtys;

typedef struct		s_scene
{
	int				fd;
	char			*line;
	char			**split;
	t_resol			resol;
	t_elem			amb_li;
	t_elem			*cam;
	t_elem			*light;
	t_elem			*sphere;
	t_elem			*plane;
	t_elem			*square;
	t_elem			*cylind;
	t_elem			*triang;
	t_qtys			qtys;
}					t_scene;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** File: mlx_oper.c
*/
int					deal_key(int key, void *param);
void				win_close(t_mlx *mlx);
void				error_msg(char *msg_nbr, t_scene *scene, t_mlx *mlx);
void				pixel_put(t_img *img, int x, int y, int color);
/*
** File: get_scene.c
*/
void				get_scene_resol(t_scene *scene);
void				get_scene_amb_li(t_scene *scene);
void				get_scene_cam(t_scene *scene);
void				get_scene_light(t_scene *scene);
/*
** File: get_scene_objs.c
*/
void				get_scene_sphere(t_scene *scene);
void				get_scene_plane(t_scene *scene);
void				get_scene_square(t_scene *scene);
void				get_scene_cylind(t_scene *scene);
void				get_scene_triang(t_scene *scene);
/*
** File: get_scene_aux.c
*/
void				scene_line_split(t_scene *scene, short int qty,
						char *msg_nbr);
void				lstadd_front_elem(t_elem **lst, t_elem *new, int *qty);
/*
** File: get_nbrs.c
*/
int					ft_str_isint(char *str);
int					ft_str_isfloat(char *str);
void				get_int(t_scene *scene, char *str, int *n,
						char *msg_nbr);
void				get_float(t_scene *scene, char *str, double *n,
						char *msg_nbr);
void				get_ratio(t_scene *scene, char *str, double *n,
						char *msg_nbr);
/*
** File: get_rgb.c
*/
int					ft_isrgb(int n);
void				get_rgb(t_scene *scene, char *str, t_rgb *rgb,
						char *msg_nbr);
/*
** File: get_coords.c
*/
void				get_tuple(t_scene *scene, char *str, t_tuple *tuple,
						char *msg_nbr);
int					ft_isnormal(t_tuple normal);
void				get_normal(t_scene *scene, char *str, t_tuple *tuple,
						char *msg_nbr);
/*
** File: utils_1.c
*/
void				*malloc_ver(size_t size, t_scene *scene, t_mlx *mlx);

// !!! APAGAR !!! TEST FUNCTIONS
void				test_put_heart(t_img *img, int offset_x, int offset_y,
							int ratio);
void				test_put_mult_hearts(t_scene *scene, t_img *img,
							int offset_x, int offset_y, int ratio);

#endif
