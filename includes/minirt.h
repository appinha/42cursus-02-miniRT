/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:55:22 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/05 21:58:28 by apuchill         ###   ########.fr       */
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
	int				w;
}					t_tuple;

/*
**                              RT file - Scene description
*/
typedef struct		s_resol
{
	int				x;
	int				y;
}					t_resol;

typedef struct		s_amb_li
{
	double			ratio;
	t_rgb			rgb;
}					t_amb_li;

typedef struct		s_cam
{
	t_tuple			coord;
	t_tuple			ori;
	int				fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_tuple			coord;
	double			ratio;
	t_rgb			rgb;
	struct s_light	*next;
}					t_light;

typedef struct		s_sphere
{
	t_tuple			coord;
	double			diam;
	double			radius;
	t_rgb			rgb;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_plane
{
	t_tuple			coord;
	double			ori;
	t_rgb			rgb;
	struct s_plane	*next;
}					t_plane;

typedef struct		s_square
{
	t_tuple			coord;
	double			ori;
	double			size;
	t_rgb			rgb;
	struct s_square	*next;
}					t_square;

typedef struct		s_cylind
{
	t_tuple			coord;
	double			ori;
	double			diam;
	double			height;
	t_rgb			rgb;
	struct s_cylind	*next;
}					t_cylind;

typedef struct		s_triang
{
	t_tuple			p1;
	t_tuple			p2;
	t_tuple			p3;
	t_rgb			rgb;
	struct s_triang	*next;
}					t_triang;

typedef struct		s_qtys
{
	int				resol;
	int				amb_li;
	int				cam;
	int				light;
	int				sp;
	int				pl;
	int				sq;
	int				cy;
	int				tr;
}					t_qtys;

typedef struct		s_scene
{
	int				fd;
	char			*line;
	char			**split;
	t_resol			resol;
	t_amb_li		amb_li;
	t_cam			*cam;
	t_light			*light;
	t_sphere		*sp;
	t_plane			*pl;
	t_square		*sq;
	t_cylind		*cy;
	t_triang		*tr;
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
int					get_rgb(char *str, t_rgb *rgb);
void				get_scene_resol(t_scene *scene);
void				get_scene_amb_li(t_scene *scene);
/*
** File: utils_1.c
*/
void				*malloc_ver(size_t size, t_mlx *mlx);
int					ft_isrgb(int n);
int					ft_isratio(double n);

// !!! APAGAR !!! TEST FUNCTIONS
void				test_put_heart(t_img *img, int offset_x, int offset_y,
							int ratio);

#endif
