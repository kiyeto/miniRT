/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:57:56 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/18 12:13:29 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_rt(char *file)
{
	char	**p;

	if (ft_strlen(file) > 3)
	{
		p = ft_split(file, '.');
		if (nb_parts(p) != 2)
		{
			ft_free(p);
			return (0);
		}
		if (!ft_strncmp(p[1], "rt", 2))
		{
			ft_free(p);
			return (1);
		}
	}
	return (0);
}

void	window_render(char *file, t_sc *sc)
{
	t_mlx			mlx;
	t_camlist		*cams;
	t_param			*p;

	cams = NULL;
	if (!check_rt(file))
	{
		write(1, "Error\nFile Not Valid!\n", 23);
		exit(0);
	}
	parse(file, sc);
	mlx.mlx_p = mlx_init();
	mlx.mlx_w = mlx_new_window(mlx.mlx_p, sc->w, sc->h, "K's MiniRT");
	mlx.img = mlx_new_image(mlx.mlx_p, sc->w, sc->h);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.l_length, &mlx.endian);
	cams = sc->c;
	p = fill_param(&cams, sc, &mlx);
	raytrace(setupcamera(sc->c), sc, &mlx);
	mlx_put_image_to_window(mlx.mlx_p, mlx.mlx_w, mlx.img, 0, 0);
	mlx_key_hook(mlx.mlx_w, esc_key, mlx.mlx_w);
	mlx_hook(mlx.mlx_w, 17, 0, ft_exit, 0);
	mlx_hook(mlx.mlx_w, 2, 0, keys, p);
	mlx_loop(mlx.mlx_p);
}

void	bmp_render(unsigned char *p, unsigned char *h, char *file, t_sc *sc)
{
	t_mlx	mlx;

	if (!check_rt(file))
	{
		write(1, "Error\nFile Not Valid!\n", 23);
		exit(0);
	}
	parse(file, sc);
	mlx.mlx_p = mlx_init();
	mlx.img = mlx_new_image(mlx.mlx_p, sc->w, sc->h);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.l_length, &mlx.endian);
	p = malloc(sc->w * sc->h * 4);
	fill_header(header_info(sc), h);
	raytracebmp(setupcamera(sc->c), sc, &mlx, p);
	create_bmp(h, p, sc->w * sc->h * 4);
	mlx_destroy_image(mlx.mlx_p, mlx.img);
	free(mlx.mlx_p);
	exit(0);
}

int		main(int argc, char **argv)
{
	unsigned char	*pixels;
	unsigned char	header[54];
	t_sc			sc;

	pixels = NULL;
	if (argc == 2)
		window_render(argv[1], &sc);
	if (argc == 3
		&& !ft_strncmp(argv[2], "--save", 6) && ft_strlen(argv[2]) == 6)
		bmp_render(pixels, header, argv[1], &sc);
	else
		write(0, "Arguments error!\n", 17);
}
