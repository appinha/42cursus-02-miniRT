/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:37:37 by appinha           #+#    #+#             */
/*   Updated: 2021/02/14 19:48:10 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <stdbool.h>
# include "libft.h"
# include "errors.h"
# include "vectors.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
typedef enum	e_type {
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}				t_type;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct		s_resol
{
	int				x;
	int				y;
}					t_resol;

typedef struct		s_amb_li
{
	double			ratio;
	int				colour;

}					t_amb_li;

typedef struct		s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_cam
{
	t_img			img;
	t_coord			point;
	t_coord			normal;
	float			fov;
	t_coord			hor;
	t_coord			ver;
	t_coord			llc;
	struct s_cam	*next;
	struct s_cam	*prev;
}					t_cam;

typedef struct		s_elem
{
	t_coord			point;
	t_coord			normal;
	t_coord			*vertex;
	short int		qtd_vertex;
	int				colour;
	double			ratio;
	double			diam;
	double			height;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_scene
{
	char			*line;
	char			**split;
	t_resol			resol;
	t_amb_li		amb_li;
	t_cam			*cam;
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
** FILE: scene.c
*/
void				init_scene(char *file, t_scene *scene);
/*
** FILE: get_scene_elem.c
*/
void				get_0_resol(t_scene *scene, t_elem **new);
void				get_1_amb_li(t_scene *scene, t_elem **new);
void				get_2_cam(t_scene *scene, t_elem **new);
void				get_cam_info(t_scene *scene, t_cam *cam);
void				get_3_light(t_scene *scene, t_elem **new);
/*
** FILE: get_scene_objs.c
*/
void				get_4_sp(t_scene *scene, t_elem **new);
void				get_5_pl(t_scene *scene, t_elem **new);
void				get_6_sq(t_scene *scene, t_elem **new);
void				get_7_cy(t_scene *scene, t_elem **new);
void				get_8_tr(t_scene *scene, t_elem **new);
/*
** FILE: get_int.c
*/
bool				ft_str_isint(char *str);
int					get_int(char *str, char *code);
int					get_posint(char *str, char *code);
float				get_fov(char *str, char *code);
/*
** FILE: get_float.c
*/
bool				ft_str_isfloat(char *str);
double				get_float(char *str, char *code);
double				get_ratio(char *str, char *code);
double				get_size(char *str, char *code);
/*
** FILE: get_colour.c
*/
bool				ft_isrgb(int n);
int					get_colour(char *str, char *code);
/*
** FILE: get_coords.c
*/
bool				ft_isnormal(t_coord normal);
t_coord				get_coord(char *str, char *code);
t_coord				get_normal(char *str, char *code);
/*
** FILE: utils.c
*/
void				lstadd_back_elem(t_elem **lst, t_elem *new,
						short int *qty);
void				lstadd_back_cam(t_cam **lst, t_cam *new,
						short int *qty);

#endif
