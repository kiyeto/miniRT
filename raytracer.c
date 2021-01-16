/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:15:40 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 18:57:35 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	bmp_pixel_put(t_mlx *d, unsigned char *data, t_rt t, int y)
{
	unsigned char	*dst;

	dst = data + (y * d->l_length + (int)t.j * (d->bpp / 8));
	*(unsigned int*)dst = t.final;
}

void	initialize(t_rt *rt)
{
	rt->i = -1;
	rt->j = -1;
}

void	raytracebmp(t_cam *c, t_sc *sc, t_mlx *img, unsigned char *pixels)
{
	t_rt	t;

	initialize(&t);
	while (++t.i < sc->h)
	{
		while (++t.j < sc->w)
		{
			t.x = (2 * (t.j + 0.5) / sc->w - 1)
					* tan(c->fov / 2 * M_PI / 180) * sc->w / sc->h;
			t.y = -(2 * (t.i + 0.5) / sc->h - 1) * tan(c->fov / 2 * M_PI / 180);
			t.pixel = vplus(vpro(c->camx, 0.5 * t.x), vpro(c->camy, 0.5 * t.y));
			t.pixel = vplus(c->scrncntr, t.pixel);
			t.r = new_ray(c->o, nrm(vplus(t.pixel, vpro(c->o, -1))));
			t.clr = inter(t.r, sc);
			t.final = color(minmax(t.clr.x), minmax(t.clr.y),
					minmax(t.clr.z));
			bmp_pixel_put(img, pixels, t, sc->h - 1 - t.i);
		}
		t.j = -1;
	}
}

void	raytrace(t_cam *c, t_sc *sc, t_mlx *img)
{
	t_rt	t;

	if (!c)
		return ;
	initialize(&t);
	while (++t.i < sc->h)
	{
		while (++t.j < sc->w)
		{
			t.x = (2 * (t.j + 0.5) / sc->w - 1)
					* tan(c->fov / 2 * M_PI / 180) * sc->w / sc->h;
			t.y = -(2 * (t.i + 0.5) / sc->h - 1) * tan(c->fov / 2 * M_PI / 180);
			t.pixel = vplus(vpro(c->camx, 0.5 * t.x), vpro(c->camy, 0.5 * t.y));
			t.pixel = vplus(c->scrncntr, t.pixel);
			t.r = new_ray(c->o, nrm(vplus(t.pixel, vpro(c->o, -1))));
			t.clr = inter(t.r, sc);
			t.final = color(minmax(t.clr.x), minmax(t.clr.y),
					minmax(t.clr.z));
			my_mlx_pixel_put(img, t.j, t.i, t.final);
		}
		t.j = -1;
	}
}
