/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:20:42 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/14 19:21:29 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void		lstadd_back_elem(t_elem **lst, t_elem *new, short int *qty)
{
	t_elem	*aux;

	aux = (*lst);
	if (!new)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	(*qty)++;
}

void		lstadd_back_cam(t_cam **lst, t_cam *new, short int *qty)
{
	t_cam	*aux;

	aux = (*lst);
	if (!new)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		new->prev = aux;
		aux->next = new;
	}
	(*qty)++;
}
