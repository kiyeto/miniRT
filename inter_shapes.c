/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:51:10 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:56:37 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	intersp(t_ray r, t_sp *sp, t_v3 *p, t_v3 *n)
{
	double b;
	double c;
	double delta;
	double t;

	b = 2 * dot(r.d, vmin(r.o, sp->c));
	c = nrm2(vmin(r.o, sp->c)) - sp->r * sp->r;
	delta = b * b - 4 * c;
	if (delta < 0)
		return (0);
	if (((-b + sqrt(delta)) / 2) < EPSILON)
		return (0);
	if (((-b - sqrt(delta)) / 2) > EPSILON)
		t = (-b - sqrt(delta)) / 2;
	else
		t = (-b + sqrt(delta)) / 2;
	*p = vplus(r.o, vpro(r.d, t));
	*n = nrm(vmin(*p, sp->c));
	return (t);
}

double	interpl(t_ray r, t_pl *pl, t_v3 *p, t_v3 *n)
{
	double	dom;
	double	t;
	t_v3	dif;

	dom = dot(pl->n, r.d);
	if (fabs(dom) > EPSILON)
	{
		dif = vmin(pl->c, r.o);
		t = dot(dif, pl->n) / dom;
		if (t > EPSILON)
		{
			*p = vplus(r.o, vpro(r.d, t));
			*n = pl->n;
			return (t);
		}
	}
	return (0);
}

double	intertr(t_ray r, t_tr *tr, t_v3 *p, t_v3 *n)
{
	t_var_tr	vr;

	vr.edge1 = vmin(tr->p2, tr->p1);
	vr.edge2 = vmin(tr->p3, tr->p1);
	vr.h = cross(r.d, vr.edge2);
	vr.a = dot(vr.edge1, vr.h);
	if (vr.a > -EPSILON && vr.a < EPSILON)
		return (0);
	vr.f = 1 / vr.a;
	vr.s = vmin(r.o, tr->p1);
	vr.u = vr.f * dot(vr.s, vr.h);
	if (vr.u < 0.0 || vr.u > 1.0)
		return (0);
	vr.q = cross(vr.s, vr.edge1);
	vr.v = vr.f * dot(r.d, vr.q);
	if (vr.v < 0.0 || vr.u + vr.v > 1.0)
		return (0);
	vr.t = vr.f * dot(vr.edge2, vr.q);
	if (vr.t > EPSILON)
	{
		*p = vplus(r.o, vpro(r.d, vr.t));
		*n = nrm(cross(vr.edge1, vr.edge2));
		return (vr.t);
	}
	return (0);
}

double	intersq(t_ray r, t_sq *sq, t_v3 *p, t_v3 *n)
{
	t_var_sq	o;

	o.t = dot(vmin(sq->p, r.o), vdiv(sq->n, dot(r.d, sq->n)));
	if (o.t > EPSILON)
	{
		*p = vplus(r.o, vpro(r.d, o.t));
		*n = sq->n;
		o.sqx = cross(sq->n, pt(0, 1, 0));
		if (o.sqx.x == 0 && o.sqx.y == 0 && o.sqx.z == 0)
			o.sqx = cross(sq->n, pt(1, 0, 0));
		o.sqy = cross(sq->n, vpro(o.sqx, -1));
		o.corner = vplus(sq->p, vpro(o.sqx, -sq->h / 2));
		o.corner = vplus(o.corner, vpro(o.sqy, -sq->h / 2));
		o.v = vmin(*p, o.corner);
		o.prj1 = dot(o.v, o.sqx);
		o.prj2 = dot(o.v, o.sqy);
		if ((o.prj1 < sq->h && o.prj1 > 0) && (o.prj2 < sq->h && o.prj2 > 0))
			return (o.t);
	}
	return (0);
}
