/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shadows.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:43:29 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:56:41 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	light_inter_helper(t_inter *v, t_ray r)
{
	if (v->l->id == 1)
	{
		v->t = intersp(r, (t_sp*)(v->l->content), &v->cp, &v->cn);
		if (v->t > 0 && v->t < v->mint)
			v->mint = v->t;
	}
	if (v->l->id == 2)
	{
		v->t = interpl(r, (t_pl*)(v->l->content), &v->cp, &v->cn);
		if (v->t > 0 && v->t < v->mint)
			v->mint = v->t;
	}
	if (v->l->id == 3)
	{
		v->t = intertr(r, (t_tr*)(v->l->content), &v->cp, &v->cn);
		if (v->t > 0 && v->t < v->mint)
			v->mint = v->t;
	}
	if (v->l->id == 4)
	{
		v->t = intersq(r, (t_sq*)(v->l->content), &v->cp, &v->cn);
		if (v->t > 0 && v->t < v->mint)
			v->mint = v->t;
	}
}

double	light_inter(t_ray r, t_sc *sc)
{
	t_inter	v;

	initialize_inter(&v, sc);
	while (v.l != NULL)
	{
		light_inter_helper(&v, r);
		if (v.l->id == 5)
		{
			v.t = intercy(r, (t_cy *)v.l->content, &v.cp, &v.cn);
			if (v.t > 0 && v.t < v.mint)
				v.mint = v.t;
		}
		v.l = v.l->next;
	}
	return (v.mint);
}

t_v3	mix_colors(t_v3 obj_clr, t_v3 light_clr)
{
	t_v3	clr;

	clr = vdiv(vplus(obj_clr, light_clr), 2);
	clr = vdiv(clr, 255);
	return (clr);
}

t_v3	cpt(t_v3 color, t_sc *sc, t_v3 *p, t_v3 *n)
{
	t_cmp_l	v;

	v.pixel = vpro(mix_colors(sc->amb.rgb, color), sc->amb.lr);
	v.lights = sc->l;
	while (v.lights)
	{
		v.l = (t_l*)v.lights->content;
		v.ldir = nrm(vmin(v.l->o, *p));
		v.lrs = vplus(*p, vpro(v.ldir, 0.000009));
		v.lray = new_ray(v.lrs, v.ldir);
		v.dlight2 = nrm2(vmin(v.l->o, *p));
		v.x = light_inter(v.lray, sc);
		v.s = vplus(v.lrs, vpro(v.ldir, v.x));
		v.dobj2 = nrm2(vmin(v.s, *p));
		if (!(v.x && (v.dobj2 < v.dlight2)))
			v.pixel = vplus(v.pixel, vpro(mix_colors(color, v.l->rgb),
			v.l->lr * max(0, dot(v.ldir, *n))));
		v.lights = v.lights->next;
	}
	return (v.pixel);
}
