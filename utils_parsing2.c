/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:37:39 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/18 14:25:32 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	sign = 1;
	i = -1;
	nb = 0;
	while (str[++i] != '\0')
	{
		if ((str[i] > '/' && str[i] < ':') || str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			if (str[i] == '+' || str[i] == '-')
				i++;
			while (str[i] > '/' && str[i] < ':')
				nb = nb * 10 + str[i++] - 48;
			return (nb * sign <= MAX_INT ? nb * sign : MAX_INT);
		}
		else if (str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			return (nb * sign <= MAX_INT ? nb * sign : MAX_INT);
	}
	return (nb * sign);
}

int		numcheck(char *s)
{
	int i;

	i = 1;
	if (!(s[0] <= '9' && s[0] >= '0') && s[0] != '-' && s[0] != '+')
		return (0);
	while (s[i])
	{
		if (!(s[i] <= '9' && s[i] >= '0') && s[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		valid_p(t_v3 *p)
{
	if ((p->x == 0.069) || (p->y == 0.069) || (p->z == 0.069))
		return (0);
	return (1);
}

t_v3	get_position(char *s)
{
	t_v3	pos;
	char	**parts;

	pos = new_vector();
	if (check(s, ',') != 2)
		return (pt(0.069, 0.069, 0.069));
	parts = ft_split(s, ',');
	if (nb_parts(parts) != 3 || (!numcheck(parts[0]) || !numcheck(parts[1])
							|| !numcheck(parts[2])))
	{
		ft_free(parts);
		return (pt(0.069, 0.069, 0.069));
	}
	pos.x = getfloat(parts[0]);
	pos.y = getfloat(parts[1]);
	pos.z = getfloat(parts[2]);
	ft_free(parts);
	if (!valid_p(&pos))
		return (pt(0.069, 0.069, 0.069));
	return (pos);
}

t_v3	get_normal(char *s)
{
	t_v3	pos;
	char	**parts;

	pos = new_vector();
	if (check(s, ',') != 2)
		return (pt(0.069, 0.069, 0.069));
	parts = ft_split(s, ',');
	if (nb_parts(parts) != 3 || (!numcheck(parts[0]) || !numcheck(parts[1])
							|| !numcheck(parts[2])))
	{
		ft_free(parts);
		return (pt(0.069, 0.069, 0.069));
	}
	pos.x = getfloat(parts[0]);
	pos.y = getfloat(parts[1]);
	pos.z = getfloat(parts[2]);
	ft_free(parts);
	if (!valid_n(&pos))
		return (pt(0.069, 0.069, 0.069));
	return (nrm(pos));
}
