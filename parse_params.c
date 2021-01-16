/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:47:22 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:57:20 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_v3	*valcolor(t_v3 *clr)
{
	if (clr)
	{
		if ((clr->x >= 0 && clr->x <= 255)
			&& (clr->y >= 0 && clr->y <= 255)
			&& (clr->z >= 0 && clr->z <= 255)
			&& clr->x != 0.069 && clr->z != 0.069
			&& clr->z != 0.069)
			return (clr);
	}
	return (NULL);
}

int		parse_r(char *line, t_sc *s)
{
	char	**content;
	int		w;
	int		h;

	content = ft_split(line, ' ');
	if (nb_parts(content) != 2)
		return (-1);
	w = ft_atoi(content[0]);
	h = ft_atoi(content[1]);
	ft_free(content);
	if (w > 0 && h > 0)
	{
		if (w > 2560)
			w = 2560;
		if (h > 1440)
			h = 1440;
		s->w = w;
		s->h = h;
		return (1);
	}
	return (-1);
}

int		parse_a(char *line, t_sc *s)
{
	char	**content;
	t_amb	amb;

	content = ft_split(line, ' ');
	if (nb_parts(content) != 2)
		return (-1);
	if (!numcheck(content[0]) || check(content[1], ',') != 2)
		return (-1);
	amb.lr = getfloat(content[0]);
	amb.rgb = get_rgb(content[1]);
	ft_free(content);
	if ((amb.lr <= 1 && amb.lr >= 0 && amb.lr != 0.069)
			&& valcolor(&amb.rgb))
	{
		s->amb = amb;
		return (1);
	}
	return (-1);
}

int		parse_c(char *line, t_sc *s)
{
	char	**content;
	t_cam	*c;
	t_v3	p;
	t_v3	n;
	float	fov;

	if (!(c = (t_cam*)malloc(sizeof(t_cam))))
		return (-1);
	content = ft_split(line, ' ');
	if (nb_parts(content) != 3)
		return (-1);
	p = get_position(content[0]);
	n = get_normal(content[1]);
	if (!numcheck(content[2]))
		return (-1);
	fov = getfloat(content[2]);
	ft_free(content);
	if (valid_p(&p) && valid_n(&n) && (fov <= 180 && fov >= 0))
	{
		*c = new_c(p, n, fov);
		lstadd_c(&s->c, lstnewc(c));
		return (1);
	}
	return (-1);
}

int		parse_l(char *line, t_sc *s)
{
	char	**content;
	t_l		*l;

	if (!(l = (t_l*)malloc(sizeof(t_l))))
		return (-1);
	content = ft_split(line, ' ');
	if (nb_parts(content) != 3)
		return (-1);
	l->o = get_position(content[0]);
	if (!numcheck(content[1]))
		return (-1);
	l->lr = getfloat(content[1]);
	l->rgb = get_rgb(content[2]);
	ft_free(content);
	if (valid_p(&l->o) && (l->lr >= 0 && l->lr <= 1) && valcolor(&l->rgb))
	{
		lstadd_back(&s->l, lstnew(l, 8));
		return (1);
	}
	return (-1);
}
