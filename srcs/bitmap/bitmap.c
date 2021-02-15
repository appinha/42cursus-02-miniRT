/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:30:07 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/14 22:02:02 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

/*
** File structure of bitmap/DIB (device independent bitmap):
**
** -> FILE HEADER
** OFFSET	| DESCRIPTION
** 00		| Type of BMP file
** 02		| Total size of BMP file in bytes
** 06-08	| Reserved, value depends on the application that creates the image
** 10		| Starting address of bitmap image data (= header size)
**
** -> BMP/DIB HEADER (bitmap information header) - Windows BITMAPINFOHEADER
** OFFSET	| DESCRIPTION
** 14		| Size of this header in bytes (40)
** 18		| Width of image in pixels
** 22		| Height of image in pixels
** 26		| Number of colour planes, must be 1
** 28		| Number of bits per pixel, i.e. colour depth (1, 4, 8, 16, 24, 32)
** 30		| Compression method being used
** 34		| Image size
** 38		| Horizontal resolution of image (pixel per metre)
** 42		| Vertical resolution of image (pixel per metre)
** 46		| Number of colours in the colour palette (0 = maximum)
** 50		| Number of important colours used (0 = every colour is important)
**
** More information: https://en.wikipedia.org/wiki/BMP_file_format
*/

static int	put_headers(int fd, unsigned int size_x, unsigned int size_y)
{
	t_file_h	fh;
	t_bmp_h		bh;
	int			ret;

	ret = 0;
	fh.type = BM;
	fh.size = HEADER_SIZE + 4 * size_x * size_y;
	fh.reserved = 0;
	fh.offset = HEADER_SIZE;
	if (write(fd, (void *)&fh, FILE_HEADER_SIZE) < 0)
		ret = -1;
	bh.size = BMP_HEADER_SIZE;
	bh.width = size_x;
	bh.height = size_y;
	bh.planes = 1;
	bh.bpp = 32;
	bh.compression = BI_RGB;
	bh.image_size = 4 * size_x * size_y;
	bh.ppm_x = 2000;
	bh.ppm_y = 2000;
	bh.clr_used = 0;
	bh.clr_important = 0;
	if (write(fd, (void *)&bh, BMP_HEADER_SIZE) < 0)
		ret = -1;
	return (ret);
}

int			export_bitmap(char *filename, int size_x, int size_y, t_img img)
{
	int		fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd < 0 || (put_headers(fd, size_x, size_y)) < 0)
		return (-1);
	while (--size_y >= 0)
	{
		if ((write(fd, &img.addr[size_y * img.size], img.size)) < 0)
			return (-1);
	}
	if (close(fd) < 0)
		return (-1);
	return (0);
}
