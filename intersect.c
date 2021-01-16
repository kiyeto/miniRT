/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:30:57 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:56:42 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialize_inter(t_inter *var, t_sc *sc)
{
	var->cl = pt(0, 0, 0);
	var->cl = new_vector();
	var->cn = new_vector();
	var->l = sc->shapes;
	var->mint = INFINITY;
	var->t = 0;
}

void	first_batch(t_inter *v, t_ray r, t_sc *sc)
{
	if (v->l->id == 1)
	{
		v->l->t = intersp(r, (t_sp*)(v->l->content), &v->cp, &v->cn);
		if (v->l->t < v->mint && v->l->t > EPSILON)
		{
			v->cl = cpt(((t_sp*)v->l->content)->rgb, sc, &v->cp, &v->cn);
			v->mint = v->l->t;
		}
	}
	if (v->l->id == 2)
	{
		v->l->t = interpl(r, (t_pl*)(v->l->content), &v->cp, &v->cn);
		if (v->l->t < v->mint && v->l->t > EPSILON)
		{
			v->cl = cpt(((t_pl*)v->l->content)->rgb, sc, &v->cp, &v->cn);
			v->mint = v->l->t;
		}
	}
}

void	scond_batch(t_inter *v, t_ray r, t_sc *sc)
{
	if (v->l->id == 3)
	{
		v->l->t = intertr(r, (t_tr*)v->l->content, &v->cp, &v->cn);
		if (v->l->t < v->mint && v->l->t > EPSILON)
		{
			v->cl = cpt(((t_tr*)v->l->content)->rgb, sc, &v->cp, &v->cn);
			v->mint = v->l->t;
		}
	}
	if (v->l->id == 4)
	{
		v->l->t = intersq(r, (t_sq*)v->l->content, &v->cp, &v->cn);
		if (v->l->t < v->mint && v->l->t > EPSILON)
		{
			v->cl = cpt(((t_sq*)v->l->content)->rgb, sc, &v->cp, &v->cn);
			v->mint = v->l->t;
		}
	}
}

t_v3	inter(t_ray r, t_sc *sc)
{
	t_inter	v;

	initialize_inter(&v, sc);
	while (v.l != NULL)
	{
		first_batch(&v, r, sc);
		scond_batch(&v, r, sc);
		if (v.l->id == 5)
		{
			v.l->t = intercy(r, (t_cy *)v.l->content, &v.cp, &v.cn);
			if (v.l->t < v.mint && v.l->t > EPSILON)
			{
				v.cl = cpt(((t_cy*)v.l->content)->rgb, sc, &v.cp, &v.cn);
				v.mint = v.l->t;
			}
		}
		v.l = v.l->next;
	}
	return (vpro(v.cl, 255));
}
