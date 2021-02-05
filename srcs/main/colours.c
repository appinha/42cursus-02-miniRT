/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: appinha <appinha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:54:03 by appinha           #+#    #+#             */
/*   Updated: 2021/02/05 10:04:00 by appinha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_rgb(int nbr)
{
	if (nbr > 0xFF)
		return (0xFF);
	else if (nbr < 0)
		return (0);
	else
		return (nbr);
}

int			c_scale(int colour, float f)
{
	int		r;
	int		g;
	int		b;

	r = check_rgb(f * (colour >> 0x10));
	g = check_rgb(f * ((colour >> 0x08) & 0xFF));
	b = check_rgb(f * (colour & 0xFF));
	return ((r << 0x10) | (g << 0x08) | b);
}

int			c_prod(int c1, int c2)
{
	int		r;
	int		g;
	int		b;

	r = (((float)(c1 >> 0x10) / 0xFF) *
			((float)(c2 >> 0x10) / 0xFF)) * 0xFF;
	g = (((float)((c1 >> 0x08) & 0xFF) / 0xFF) *
			((float)((c2 >> 0x08) & 0xFF) / 0xFF)) * 0xFF;
	b = (((float)(c1 & 0xFF) / 0xFF) *
			((float)(c2 & 0xFF) / 0xFF)) * 0xFF;
	return ((r << 0x10) | (g << 0x08) | b);
}

int			c_add(int c1, int c2)
{
	int		r;
	int		g;
	int		b;

	r = check_rgb((c1 >> 0x10) + (c2 >> 0x10));
	g = check_rgb((c1 >> 0x08 & 0xFF) + (c2 >> 0x08 & 0xFF));
	b = check_rgb((c1 & 0xFF) + (c2 & 0xFF));
	return ((r << 0x10) | (g << 0x08) | b);
}
