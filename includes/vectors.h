/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:00:44 by appinha           #+#    #+#             */
/*   Updated: 2021/02/07 09:26:24 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <math.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** FILE: vectors.c
*/
t_coord				gen_coord(double x, double y, double z);
double				v_len_sqr(t_coord v);
double				v_len(t_coord v);
t_coord				v_norm(t_coord v);
/*
** FILE: vectors_oper.c
*/
t_coord				v_add(t_coord v, t_coord u);
t_coord				v_sub(t_coord v, t_coord u);
t_coord				v_scale(t_coord v, double f);
t_coord				v_cross(t_coord v, t_coord u);
double				v_dot(t_coord v, t_coord u);

#endif
