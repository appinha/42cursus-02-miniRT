/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:04:06 by appinha           #+#    #+#             */
/*   Updated: 2021/02/07 09:27:50 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_coord		gen_coord(double x, double y, double z)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}

double		v_len_sqr(t_coord v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double		v_len(t_coord v)
{
	return (sqrt(v_len_sqr(v)));
}

t_coord		v_norm(t_coord v)
{
	return (v_scale(v, 1 / v_len(v)));
}
