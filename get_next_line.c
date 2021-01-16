/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:55:04 by abenouda          #+#    #+#             */
/*   Updated: 2020/12/16 23:17:54 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;
	int		j;

	j = 0;
	while (s[j])
		j++;
	dup = (char *)malloc(sizeof(char) * (j + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < j)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*p;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		p = (char*)malloc(1 * sizeof(char));
	p = (char*)malloc(len + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	*(p + i) = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*joinstr;

	len = 0;
	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len = (s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0);
	if ((joinstr = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (s1 && s1[i] != 0)
	{
		joinstr[j++] = s1[i++];
	}
	i = 0;
	while (s2 && s2[i] != 0)
	{
		joinstr[j++] = s2[i++];
	}
	joinstr[j] = '\0';
	ft_bzero(s2, ft_strlen(s2));
	return (joinstr);
}

int		get_next_line(int fd, char **line)
{
	static char	*txt[20000];
	char		*b;
	char		*p;
	int			r;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(b = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!txt[fd])
		txt[fd] = ft_strdup("");
	while (!(ft_strchr(txt[fd], '\n')) && ((r = read(fd, b, BUFFER_SIZE)) > 0))
	{
		b[r] = '\0';
		p = txt[fd];
		txt[fd] = ft_strjoin(txt[fd], b);
		free(p);
	}
	if (ft_strchr(txt[fd], '\n'))
	{
		*line = ft_substr(txt[fd], 0, newline(txt[fd]));
		p = txt[fd];
		txt[fd] = ft_strdup(txt[fd] + newline(txt[fd]) + 1);
		return (free_memory(&p, &b, 2, 1));
	}
	*line = ft_strdup(txt[fd]);
	return (free_memory(&txt[fd], &b, 2, (r != -1 ? 0 : -1)));
}
