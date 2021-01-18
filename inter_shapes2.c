/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_shapes2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:09:36 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/18 17:45:03 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	sub_intercy(t_ray r, t_cy *cy, t_var_cy *var)
{
	var->x = vmin(r.o, cy->p);
	var->a = dot(r.d, r.d) - powf(dot(r.d, cy->n), 2);
	var->b = 2 * (dot(r.d, var->x) - dot(r.d, cy->n) * dot(var->x, cy->n));
	var->c = dot(var->x, var->x) - powf(dot(var->x, cy->n), 2) - pow(cy->d, 2);
	var->delta = (var->b * var->b) - (4 * var->a * var->c);
	if (var->delta < 0)
		return (0);
	var->s1 = (-var->b - sqrt(var->delta)) / (2 * var->a);
	var->s2 = (-var->b + sqrt(var->delta)) / (2 * var->a);
	var->p1 = vplus(r.o, vpro(r.d, var->s1));
	var->p2 = vplus(r.o, vpro(r.d, var->s2));
	if (var->s2 < EPSILON)
		return (0);
	return (1);
}

double	intercy(t_ray r, t_cy *cy, t_v3 *p, t_v3 *n)
{
	t_var_cy	var;

	if (sub_intercy(r, cy, &var) && var.s1 > EPSILON)
	{
		if (fabs(dot(cy->n, vmin(var.p1, cy->p))) <= cy->h &&
			dot(cy->n, vmin(var.p1, cy->p)) >= 0)
		{
			*p = var.p1;
			var.m = dot(r.d, vpro(cy->n, var.s1)) + dot(var.x, cy->n);
			*n = nrm(vmin(vmin(var.p1, cy->p), vpro(cy->n, var.m)));
			if (var.m >= 0 && var.m <= cy->h)
				return (var.s1);
		}
		else if (fabs(dot(cy->n, vmin(var.p2, cy->p))) <= cy->h
				&& dot(cy->n, vmin(var.p2, cy->p)) >= 0)
		{
			*p = var.p2;
			var.m = dot(r.d, vpro(cy->n, var.s2)) + dot(var.x, cy->n);
			*n = nrm(vmin(vmin(var.p2, cy->p), vpro(cy->n, var.m)));
			if (var.m >= 0 && var.m <= cy->h)
				return (var.s2);
		}
	}
	return (0);
}
