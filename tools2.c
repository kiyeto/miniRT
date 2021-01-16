/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:31:13 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:57:39 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double		minmax(double x)
{
	return (min(255, max(0, x)));
}

double		max(double a, double b)
{
	double res;

	if (a > b)
		res = a;
	else
		res = b;
	return (res);
}

double		min(double a, double b)
{
	double res;

	if (a > b)
		res = b;
	else
		res = a;
	return (res);
}
