/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 03:05:02 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 18:58:55 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = -1;
	while ((size_t)++i < n)
		if (((unsigned char)s1[i] - (unsigned char)s2[i]) != 0
				|| s1[i] == 0 || s2[i] == 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int		is_valid2(char *line, t_sc *s)
{
	int i;

	i = 1;
	if ((line[0] == (char)'c') && (line[1] != (char)'y'))
		return (i = parse_c(line + 1, s));
	else if (line[0] == (char)'l')
		return (i = parse_l(line + 1, s));
	else if (!ft_strncmp(line, (const char*)"sp ", 3))
		return (i = parse_sp(line + 2, s));
	else if (!ft_strncmp(line, (const char*)"pl ", 3))
		return (i = parse_pl(line + 2, s));
	else if (!ft_strncmp(line, (const char*)"sq ", 3))
		return (i = parse_sq(line + 2, s));
	else if (!ft_strncmp(line, (const char*)"cy ", 3))
		return (i = parse_cy(line + 2, s));
	else if (!ft_strncmp(line, (const char*)"tr ", 3))
		return (i = parse_tr(line + 2, s));
	else
		return (-1);
	return (i);
}

int		is_valid(char *line, t_sc *s)
{
	int i;

	i = 1;
	if (line[0] == (char)'R')
	{
		if (!g_r)
		{
			g_r = 1;
			return (i = parse_r(line + 1, s));
		}
		else
			return (-1);
	}
	else if (line[0] == (char)'A')
	{
		if (!g_a)
		{
			g_a = 1;
			return (i = parse_a(line + 1, s));
		}
		else
			return (-1);
	}
	i = is_valid2(line, s);
	return (i);
}

char	*get_line(int fd)
{
	char	*line;
	int		res;

	res = get_next_line(fd, &line);
	if (res || (!res && line[0] != '\0'))
		return (line);
	else
		free(line);
	return (NULL);
}

void	parse(char *pl, t_sc *scene)
{
	int		fd;
	char	*p;

	g_a = 0;
	g_r = 0;
	scene->c = NULL;
	scene->l = NULL;
	scene->shapes = NULL;
	fd = open(pl, O_RDONLY);
	while ((p = get_line(fd)))
	{
		if (is_valid(p, scene) != 1)
		{
			printf("\nParsing error!\n");
			exit(0);
		}
		free(p);
	}
	close(fd);
}
