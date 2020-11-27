/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:55:22 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/27 17:17:46 by appinha          ###   ########.fr       */
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

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

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
	t_coord			coord;
	t_coord			normal;
	t_coord			p1;
	t_coord			p2;
	t_coord			p3;
	t_rgb			rgb;
	int				fov;
	double			ratio;
	double			diam;
	double			height;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_scene
{
	int				fd;
	char			*line;
	char			**split;
	t_resol			resol;
	t_elem			amb_li;
	t_elem			*cam;
	t_elem			*light;
	t_elem			*sp;
	t_elem			*pl;
	t_elem			*sq;
	t_elem			*cy;
	t_elem			*tr;
	short int		qtys[9];
}					t_scene;

typedef void		(*t_arr_sc)(t_scene *, t_elem **);

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** File: mlx_oper.c
*/
int					deal_key(int key, void *param);
void				win_close(t_mlx *mlx);
void				pixel_put(t_img *img, int x, int y, int color);
/*
** File: errors.c
*/
void				error_msg(char *msg_nbr, t_scene *scene, t_mlx *mlx);
void				get_error_msg_nbr(short int categ, short int elem_id,
						short int err_id, char **msg_nbr);
/*
** File: get_scene.c
*/
void				get_scene_elem(t_scene *scene, short int elem_id,
						void (*ft)(t_scene *, t_elem **));
void				get_scene_0_resol(t_scene *scene, t_elem **new);
void				get_scene_1_amb_li(t_scene *scene, t_elem **new);
void				get_scene_2_cam(t_scene *scene, t_elem **new);
void				get_scene_3_light(t_scene *scene, t_elem **new);
/*
** File: get_scene_objs.c
*/
void				get_scene_4_sp(t_scene *scene, t_elem **new);
void				get_scene_5_pl(t_scene *scene, t_elem **new);
void				get_scene_6_sq(t_scene *scene, t_elem **new);
void				get_scene_7_cy(t_scene *scene, t_elem **new);
void				get_scene_8_tr(t_scene *scene, t_elem **new);
/*
** File: get_scene_aux.c
*/
int					ft_isvalidchar(char c);
void				scene_check_qty(t_scene *scene, short int elem_id,
						short int err_id);
void				scene_line_split(t_scene *scene, short int elem_id,
						short int err_id);
void				lstadd_front_elem(t_elem **lst, t_elem *new,
						short int *qty);
/*
** File: get_int.c
*/
int					ft_str_isint(char *str);
int					get_int(t_scene *scene, char *str, char *msg_nbr);
int					get_posint(t_scene *scene, char *str, char *msg_nbr);
int					get_fov(t_scene *scene, char *str, char *msg_nbr);
/*
** File: get_float.c
*/
int					ft_str_isfloat(char *str);
double				get_float(t_scene *scene, char *str, char *msg_nbr);
double				get_ratio(t_scene *scene, char *str, char *msg_nbr);
double				get_size(t_scene *scene, char *str, char *msg_nbr);
/*
** File: get_rgb.c
*/
int					ft_isrgb(int n);
t_rgb				get_rgb(t_scene *scene, char *str, char *msg_nbr);
/*
** File: get_coords.c
*/
int					ft_isnormal(t_coord normal);
t_coord				get_coord(t_scene *scene, char *str, char *msg_nbr);
t_coord				get_normal(t_scene *scene, char *str, char *msg_nbr);
/*
** File: utils_1.c
*/
void				*malloc_ver(size_t size, t_scene *scene, t_mlx *mlx);

// !!! APAGAR !!! TEST FUNCTIONS
void				test_put_heart(t_img *img, int offset_x, int offset_y,
							int ratio);
void				test_put_mult_hearts(t_scene *scene, t_img *img,
							int offset_x, int offset_y, int ratio);
void				print_triage_scene_info(t_scene *scene);

#endif
