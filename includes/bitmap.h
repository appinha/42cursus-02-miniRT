/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:11:24 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/14 21:59:40 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "minirt.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define BM					0x4D42
# define HEADER_SIZE		54
# define FILE_HEADER_SIZE	14
# define BMP_HEADER_SIZE	40
# define BI_RGB				0

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
**
** #pragma pack instructs the compiler to pack structure members with particular
** alignment. Here we want to ensure that the compiler does not insert padding
** into the data and each member follows the previous one. For more information:
** https://stackoverflow.com/questions/3318410/pragma-pack-effect
*/
# pragma pack(push, 1)

typedef struct		s_file_h
{
	short int		type;
	int				size;
	int				reserved;
	unsigned int	offset;
}					t_file_h;

typedef struct		s_bmp_h
{
	unsigned int	size;
	int				width;
	int				height;
	short int		planes;
	short int		bpp;
	unsigned int	compression;
	unsigned int	image_size;
	int				ppm_x;
	int				ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bmp_h;

# pragma pack(pop)

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** FILE: bitmap.c
*/
int					export_bitmap(char *filename, int size_x, int size_y,
									t_img img);

#endif
