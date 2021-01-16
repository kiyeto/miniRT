/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:40:39 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 18:56:32 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_cam	*setupcamera(t_camlist *c_list)
{
	t_cam *cam;

	if (!c_list)
		return (NULL);
	cam = (t_cam*)c_list->cam;
	return (cam);
}

void	next_cam(t_camlist **list)
{
	if (!*list)
		return ;
	if ((*list)->next != NULL)
		(*list) = (*list)->next;
}

void	prev_cam(t_camlist **list)
{
	if (!*list)
		return ;
	if ((*list)->prev != NULL)
		(*list) = (*list)->prev;
}

void	lstadd_c(t_camlist **alst, t_camlist *new)
{
	t_camlist	*last;

	if (!new)
		return ;
	last = *alst;
	new->next = NULL;
	if ((*alst) == NULL)
		(*alst) = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}
