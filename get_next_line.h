/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:53:17 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/18 17:22:26 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 1024

size_t	ft_strlen(const char *str);

int		newline(const char *str);

char	*ft_strchr(const char *s, int c);

void	ft_bzero(void *s, size_t n);

char	*ft_strdup(const char *s);

char	*ft_strjoin(char const *s1, char *s2);

int		get_next_line(int fd, char **line);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		free_memory(char **p1, char **p2, int nb, int ret);

#endif
