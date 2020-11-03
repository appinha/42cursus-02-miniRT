/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:55:22 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/02 16:12:38 by apuchill         ###   ########.fr       */
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

// !!! APAGAR !!!
# include <stdio.h>


/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define KEY_ESC		65307
# define MSG_QUIT		"\nExiting miniRT. À bientôt !\n\n"


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
** RT file
*/
typedef struct		s_resol
{
	int				x_width;
	int				y_height;
}					t_reso;

typedef struct		s_amb_li
{
	double			ratio;
	t_rgb			rgb;
}					t_amb_li;

typedef struct		s_cam
{
	t_tuple			point;
	t_tuple			ori;
	int				fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_tuple			point;
	double			ratio;
	t_rgb			rgb;
	struct s_light	*next;
}					t_light;


/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
void	pixel_put(t_img *img, int x, int y, int color);
int		deal_key(int key, void *param);
void	win_close(t_mlx *mlx);

// !!! APAGAR !!! TEST FUNCTIONS
void	test_put_heart(t_img *img, int offset_x, int offset_y, int ratio);


#endif
