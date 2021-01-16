/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:48:10 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:57:41 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	get_pr(char *ptr, double nb)
{
	double coef;

	coef = 0.1;
	while (*ptr >= '0' && *ptr <= '9')
	{
		if (nb >= 0)
			nb += (*ptr - '0') * coef;
		else
			nb -= (*ptr - '0') * coef;
		ptr++;
		coef *= 0.1;
	}
	return (nb);
}

double	getfloat(char *s)
{
	char	**res;
	double	nb;
	int		sign;

	nb = 0;
	sign = 1;
	if (s[0] == '-')
	{
		sign = -1;
		if (s[1] >= '0' && s[1] <= '9')
			nb = ft_atoi(s + 1);
		else
			return (0.069);
	}
	else
		nb = ft_atoi(s);
	if (check(s, '.') == 1)
	{
		res = ft_split(s, '.');
		nb = get_pr(res[1], nb);
		ft_free(res);
	}
	else if (check(s, '.') > 1)
		return (0.069);
	return (nb * sign);
}

t_v3	get_rgb(char *s)
{
	t_v3 clr;
	char **parts;

	clr = new_vector();
	parts = ft_split(s, ',');
	if (nb_parts(parts) != 3)
	{
		ft_free(parts);
		return (pt(0.069, 0.069, 0.069));
	}
	if (!numcheck(parts[0]) || !numcheck(parts[1]) || !numcheck(parts[2]))
	{
		ft_free(parts);
		return (pt(0.069, 0.069, 0.069));
	}
	clr = pt(ft_atoi(parts[0]), ft_atoi(parts[1]), ft_atoi(parts[2]));
	ft_free(parts);
	return (clr);
}

int		nb_parts(char **s)
{
	int nb;

	nb = 0;
	while (*s != NULL)
	{
		nb++;
		s++;
	}
	return (nb);
}

int		check(char *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}
