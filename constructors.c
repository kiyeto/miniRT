/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:40:56 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:56:28 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_v3	new_vector(void)
{
	t_v3 vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

t_v3	pt(double x, double y, double z)
{
	t_v3 v;

	v = new_vector();
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_ray	new_ray(t_v3 o, t_v3 dir)
{
	t_ray r;

	r.o = o;
	r.d = dir;
	return (r);
}

t_cam	new_c(t_v3 o, t_v3 d, float fov)
{
	t_cam	c;
	t_v3	camx;
	t_v3	camy;
	t_v3	swp;

	c.o = o;
	c.d = d;
	c.fov = fov;
	camx = cross(d, pt(0, -1, 0));
	if (camx.x == 0 && camx.y == 0 && camx.z == 0)
		camx = cross(d, pt(-1, 0, 0));
	nrm(camx);
	camy = cross(d, camx);
	nrm(camy);
	if (!d.x && d.y && !d.z)
	{
		swp = vpro(camx, -1);
		camx = camy;
		camy = swp;
	}
	c.camx = camx;
	c.camy = camy;
	c.scrncntr = vplus(c.o, c.d);
	return (c);
}

t_param	*fill_param(t_camlist **cams, t_sc *sc, t_mlx *img)
{
	t_param *param;

	param = (t_param*)malloc(sizeof(t_param));
	param->cams = cams;
	param->sc = sc;
	param->img = img;
	param->mlxptr = &(img->mlx_p);
	param->mlxwin = &(img->mlx_w);
	return (param);
}
