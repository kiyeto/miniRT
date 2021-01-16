/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:41:23 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:57:15 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_v3	vplus(t_v3 a, t_v3 b)
{
	t_v3 v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_v3	vmin(t_v3 a, t_v3 b)
{
	t_v3 v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_v3	vpro(t_v3 a, double b)
{
	t_v3 v;

	v.x = a.x * b;
	v.y = a.y * b;
	v.z = a.z * b;
	return (v);
}

t_v3	vdiv(t_v3 a, double b)
{
	t_v3 v;

	v.x = a.x / b;
	v.y = a.y / b;
	v.z = a.z / b;
	return (v);
}
