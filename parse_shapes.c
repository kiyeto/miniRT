/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:46:26 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:57:23 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		parse_sp(char *line, t_sc *s)
{
	char	**content;
	t_sp	*sp;

	if (!(sp = (t_sp*)malloc(sizeof(t_sp))))
		return (-1);
	content = ft_split(line, ' ');
	if (nb_parts(content) != 3)
		return (-1);
	sp->c = get_position(content[0]);
	if (!numcheck(content[1]))
		return (-1);
	sp->r = getfloat(content[1]);
	sp->rgb = get_rgb(content[2]);
	ft_free(content);
	if (valid_p(&sp->c) && sp->r > 0 && valcolor(&sp->rgb))
	{
		lstadd_back(&s->shapes, lstnew(sp, 1));
		return (1);
	}
	return (-1);
}

int		parse_pl(char *line, t_sc *s)
{
	char	**content;
	t_pl	*pl;

	if (!(pl = (t_pl*)malloc(sizeof(t_pl))))
		return (-1);
	content = ft_split(line, ' ');
	if (nb_parts(content) != 3)
		return (-1);
	pl->c = get_position(content[0]);
	pl->n = get_normal(content[1]);
	pl->rgb = get_rgb(content[2]);
	ft_free(content);
	if (valid_p(&pl->c) && valid_p(&pl->n) && valcolor(&pl->rgb))
	{
		lstadd_back(&s->shapes, lstnew(pl, 2));
		return (1);
	}
	return (-1);
}

int		parse_sq(char *line, t_sc *s)
{
	char	**content;
	t_sq	*sq;

	if (!(sq = (t_sq*)malloc(sizeof(t_sq))))
		return (-1);
	content = ft_split(line, ' ');
	if (nb_parts(content) != 4)
		return (-1);
	if (!numcheck(content[2]))
		return (-1);
	sq->p = get_position(content[0]);
	sq->n = get_normal(content[1]);
	sq->h = getfloat(content[2]);
	sq->rgb = get_rgb(content[3]);
	ft_free(content);
	if (valid_p(&sq->p) && valid_p(&sq->n) && sq->h > 0 && valcolor(&sq->rgb))
	{
		lstadd_back(&s->shapes, lstnew(sq, 4));
		return (1);
	}
	return (-1);
}

int		parse_tr(char *line, t_sc *s)
{
	char	**content;
	t_tr	*tr;

	if (!(tr = (t_tr*)malloc(sizeof(t_tr))))
		return (-1);
	content = ft_split(line, ' ');
	if (nb_parts(content) != 4)
		return (-1);
	tr->p1 = get_position(content[0]);
	tr->p2 = get_position(content[1]);
	tr->p3 = get_position(content[2]);
	tr->rgb = get_rgb(content[3]);
	ft_free(content);
	if (valid_p(&tr->p1) && valid_p(&tr->p2) && valid_p(&tr->p3)
				&& valcolor(&tr->rgb))
	{
		lstadd_back(&s->shapes, lstnew(tr, 3));
		return (1);
	}
	return (-1);
}

int		parse_cy(char *line, t_sc *s)
{
	char	**content;
	t_cy	*cy;

	if (!(cy = (t_cy*)malloc(sizeof(t_cy))))
		return (-1);
	content = ft_split(line, ' ');
	if (nb_parts(content) != 5)
		return (-1);
	if (!numcheck(content[2]) || !numcheck(content[3]))
		return (-1);
	cy->p = get_position(content[0]);
	cy->n = get_normal(content[1]);
	cy->d = getfloat(content[2]) / 2;
	cy->h = getfloat(content[3]);
	cy->rgb = get_rgb(content[4]);
	ft_free(content);
	if (valid_p(&cy->p) && valid_p(&cy->n) && cy->d > 0 && cy->h > 0
				&& valcolor(&cy->rgb))
	{
		lstadd_back(&s->shapes, lstnew(cy, 5));
		return (1);
	}
	return (-1);
}
