/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:20:13 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:57:17 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	dot(t_v3 a, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_v3	cross(t_v3 a, t_v3 b)
{
	t_v3 v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}

double	nrm2(t_v3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_v3	nrm(t_v3 v)
{
	t_v3	vec;
	double	norm;

	norm = sqrt(nrm2(v));
	vec.x = v.x / norm;
	vec.y = v.y / norm;
	vec.z = v.z / norm;
	return (vec);
}
