/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:37:37 by appinha           #+#    #+#             */
/*   Updated: 2021/02/07 09:22:05 by apuchill         ###   ########.fr       */
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
# include "vectors.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct		s_resol
{
	int				x;
	int				y;
}					t_resol;

typedef struct		s_cam
{
	float			fov;
	t_coord			hor;
	t_coord			ver;
	t_coord			llc;
}					t_cam;

typedef struct		s_tr
{
	t_coord			p1;
	t_coord			p2;
	t_coord			p3;

}					t_tr;

typedef struct		s_elem
{
	t_coord			point;
	t_coord			normal;
	int				colour;
	double			ratio;
	double			diam;
	double			height;
	t_cam			cam;
	t_tr			tr;
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
** FILE: scene.c
*/
void				init_scene(char *file, t_scene *scene);
void				get_scene_elem(t_scene *scene, short int elem_id,
						void (*ft)(t_scene *, t_elem **));
/*
** FILE: get_scene_elem.c
*/
void				get_0_resol(t_scene *scene, t_elem **new);
void				get_1_amb_li(t_scene *scene, t_elem **new);
void				get_2_cam(t_scene *scene, t_elem **new);
void				get_cam_info(t_scene *scene, t_elem *cam);
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
** FILE: get_scene_aux.c
*/
void				lstadd_back_elem(t_elem **lst, t_elem *new,
						short int *qty);
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

#endif
