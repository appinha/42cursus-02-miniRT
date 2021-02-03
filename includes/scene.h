/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:37:37 by appinha           #+#    #+#             */
/*   Updated: 2021/02/03 08:44:39 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include "libft.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
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
** File: scene.c
*/
void				init_scene(char *file, t_scene *scene);
void				get_scene_elem(t_scene *scene, short int elem_id,
						void (*ft)(t_scene *, t_elem **));
/*
** File: get_scene_elem.c
*/
void				get_0_resol(t_scene *scene, t_elem **new);
void				get_1_amb_li(t_scene *scene, t_elem **new);
void				get_2_cam(t_scene *scene, t_elem **new);
void				get_3_light(t_scene *scene, t_elem **new);
/*
** File: get_scene_polygs.c
*/
void				get_4_sp(t_scene *scene, t_elem **new);
void				get_5_pl(t_scene *scene, t_elem **new);
void				get_6_sq(t_scene *scene, t_elem **new);
void				get_7_cy(t_scene *scene, t_elem **new);
void				get_8_tr(t_scene *scene, t_elem **new);
/*
** File: get_scene_aux.c
*/
void				lstadd_front_elem(t_elem **lst, t_elem *new,
						short int *qty);
/*
** File: get_int.c
*/
int					ft_str_isint(char *str);
int					get_int(char *str, char *code);
int					get_posint(char *str, char *code);
int					get_fov(char *str, char *code);
/*
** File: get_float.c
*/
int					ft_str_isfloat(char *str);
double				get_float(char *str, char *code);
double				get_ratio(char *str, char *code);
double				get_size(char *str, char *code);
/*
** File: get_rgb.c
*/
int					ft_isrgb(int n);
t_rgb				get_rgb(char *str, char *code);
/*
** File: get_coords.c
*/
int					ft_isnormal(t_coord normal);
t_coord				get_coord(char *str, char *code);
t_coord				get_normal(char *str, char *code);

#endif
