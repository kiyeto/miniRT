/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:45:12 by abenouda          #+#    #+#             */
/*   Updated: 2019/11/08 22:33:36 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		newline(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int j;

	j = 0;
	while (s[j])
		j++;
	i = 0;
	while (i <= j)
		if (s[i] == (char)c)
			return ((char*)s + i);
		else
			i++;
	return (NULL);
}

int		free_memory(char **p1, char **p2, int nb, int ret)
{
	free(*p1);
	*p1 = 0;
	if (nb)
	{
		free(*p2);
		*p2 = 0;
	}
	if (ret < 0)
		return (-1);
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char*)s;
	while (n--)
		*tmp++ = 0;
}
