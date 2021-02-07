/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_oper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:28:54 by appinha           #+#    #+#             */
/*   Updated: 2021/02/07 09:27:47 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_coord		v_add(t_coord v, t_coord u)
{
	return (gen_coord((v.x + u.x), (v.y + u.y), (v.z + u.z)));
}

t_coord		v_sub(t_coord v, t_coord u)
{
	return (gen_coord((v.x - u.x), (v.y - u.y), (v.z - u.z)));
}

t_coord		v_scale(t_coord v, double f)
{
	return (gen_coord((f * v.x), (f * v.y), (f * v.z)));
}

t_coord		v_cross(t_coord v, t_coord u)
{
	return (gen_coord(((v.y * u.z) - (v.z * u.y)),
						((v.z * u.x) - (v.x * u.z)),
						((v.x * u.y) - (v.y * u.x))));
}

double		v_dot(t_coord v, t_coord u)
{
	return ((v.x * u.x) + (v.y * u.y) + (v.z * u.z));
}
