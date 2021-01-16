/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:38:57 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:56:23 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_header	header_info(t_sc *sc)
{
	t_header	h;

	h.size = sc->w * sc->h * 4;
	h.width = sc->w;
	h.height = sc->h;
	h.bitcount = 32;
	h.width_b = ((h.width * h.bitcount + 31) / 32) * 4;
	h.imagesize = h.width_b * h.height;
	h.bisize = 40;
	h.bfoffbits = 54;
	h.filesize = 54 + h.imagesize;
	h.biplanes = 1;
	return (h);
}

void		fill_header(t_header h, unsigned char *header)
{
	memcpy(header, "BM", 2);
	memcpy(header + 2, &h.size, 4);
	memcpy(header + 10, &h.bfoffbits, 4);
	memcpy(header + 14, &h.bisize, 4);
	memcpy(header + 18, &h.width, 4);
	memcpy(header + 22, &h.height, 4);
	memcpy(header + 26, &h.biplanes, 2);
	memcpy(header + 28, &h.bitcount, 2);
	memcpy(header + 34, &h.imagesize, 4);
}

void		create_bmp(unsigned char *header, unsigned char *pixels, int size)
{
	int fd;

	fd = open("sceneshot.bmp", O_CREAT | O_RDWR, S_IRWXU);
	if (fd != -1)
	{
		write(fd, header, 54);
		write(fd, pixels, size);
		free(pixels);
		close(fd);
		write(1, "Image saved !\n", 14);
	}
	else
		write(1, "couldn't create the bmp file", 28);
}
