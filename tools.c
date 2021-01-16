/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:41:34 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:57:37 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			color(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

t_list		*lstnew(void *content, int id)
{
	t_list	*p;

	p = (t_list*)malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->id = id;
	p->t = 0;
	p->content = content;
	p->next = NULL;
	return (p);
}

void		lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	last = *alst;
	new->next = NULL;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_camlist	*lstnewc(void *cam)
{
	t_camlist	*p;

	p = (t_camlist*)malloc(sizeof(t_camlist));
	if (!p)
		return (NULL);
	p->cam = cam;
	p->next = NULL;
	p->prev = NULL;
	return (p);
}
