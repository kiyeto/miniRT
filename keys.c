/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:11:10 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/18 19:26:36 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		esc_key(int key, void *param)
{
	if (key == 53 && param)
	{
		write(1, "The Window is closed.\n", 22);
		exit(0);
	}
	return (0);
}

int		ft_exit(void)
{
	write(1, "The Window is closed.\n", 22);
	exit(0);
}

void	n_key(void *param)
{
	t_camlist	**cams;
	t_sc		*sc;
	t_mlx		*img;
	void		*ptr;
	void		*win;

	cams = ((t_param*)param)->cams;
	sc = ((t_param*)param)->sc;
	img = ((t_param*)param)->img;
	ptr = *((t_param*)param)->mlxptr;
	win = *((t_param*)param)->mlxwin;
	write(0, "Rendering next image... Please wait.\n", 38);
	next_cam(cams);
	raytrace(setupcamera(*cams), sc, img);
	mlx_put_image_to_window(ptr, win, img->img, 0, 0);
	write(0, "Done!\n", 7);
}

void	b_key(void *param)
{
	t_camlist	**cams;
	t_sc		*sc;
	t_mlx		*img;
	void		*ptr;
	void		*win;

	cams = ((t_param*)param)->cams;
	sc = ((t_param*)param)->sc;
	img = ((t_param*)param)->img;
	ptr = *((t_param*)param)->mlxptr;
	win = *((t_param*)param)->mlxwin;
	write(0, "Rendering previous image... Please wait.\n", 42);
	prev_cam(cams);
	raytrace(setupcamera(*cams), sc, img);
	mlx_put_image_to_window(ptr, win, img->img, 0, 0);
	write(0, "Done!\n", 7);
}

int		keys(int key, void *param)
{
	if (key == 45)
		n_key(param);
	if (key == 11)
		b_key(param);
	return (0);
}
