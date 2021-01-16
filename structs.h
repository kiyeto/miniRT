/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:41:38 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:56:53 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>

int						g_a;
int 					g_r;

typedef struct			s_v3
{
	double				x;
	double				y;
	double				z;
}						t_v3;

typedef struct			s_ray
{
	t_v3				o;
	t_v3				d;
}						t_ray;

typedef struct			s_cam
{
	t_v3				o;
	t_v3				d;
	double				fov;
	t_v3				camx;
	t_v3				camy;
	t_v3				scrncntr;
}						t_cam;

typedef	struct			s_list
{
	int					id;
	double				t;
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct			s_camlist
{
	void				*cam;
	struct s_camlist	*prev;
	struct s_camlist	*next;
}						t_camlist;

typedef struct			s_amb
{
	double				lr;
	t_v3				rgb;
}						t_amb;

typedef struct			s_l
{
	t_v3				o;
	double				lr;
	t_v3				rgb;
}						t_l;

typedef	struct			s_sp
{
	t_v3				c;
	double				r;
	t_v3				rgb;
}						t_sp;

typedef struct			s_pl
{
	t_v3				c;
	t_v3				n;
	t_v3				rgb;
}						t_pl;

typedef struct			s_tr
{
	t_v3				p1;
	t_v3				p2;
	t_v3				p3;
	t_v3				rgb;
}						t_tr;

typedef struct			s_sq
{
	t_v3				p;
	t_v3				n;
	double				h;
	t_v3				rgb;
}						t_sq;

typedef struct			s_cy
{
	t_v3				p;
	t_v3				n;
	double				d;
	double				h;
	t_v3				rgb;
}						t_cy;

typedef struct			s_mlx
{
	void				*mlx_p;
	void				*mlx_w;
	void				*img;
	char				*addr;
	int					bpp;
	int					l_length;
	int					endian;
}						t_mlx;

typedef struct			s_sc
{	int					h;
	int					w;
	t_amb				amb;
	t_camlist			*c;
	t_list				*l;
	t_list				*shapes;
}						t_sc;

typedef struct			s_param
{
	void				**mlxptr;
	void				**mlxwin;
	t_camlist			**cams;
	t_sc				*sc;
	t_mlx				*img;
}						t_param;

typedef struct			s_var_tr
{
	t_v3				edge1;
	t_v3				edge2;
	t_v3				h;
	t_v3				s;
	t_v3				q;
	double				a;
	double				f;
	double				u;
	double				v;
	double				t;
}						t_var_tr;

typedef struct			s_var_sq
{
	double				t;
	double				prj1;
	double				prj2;
	t_v3				v;
	t_v3				sqx;
	t_v3				sqy;
	t_v3				corner;
}						t_var_sq;

typedef struct			s_var_cy
{
	double				a;
	double				b;
	double				c;
	t_v3				x;
	double				delta;
	double				s1;
	double				s2;
	double				m;
	t_v3				p1;
	t_v3				p2;
}						t_var_cy;

typedef struct			s_cmp_l
{
	t_v3				pixel;
	t_v3				ldir;
	t_v3				lrs;
	t_ray				lray;
	double				dlight2;
	double				dobj2;
	double				x;
	t_list				*lights;
	t_l					*l;
	t_v3				s;
}						t_cmp_l;

typedef struct			s_inter
{
	t_list				*l;
	double				mint;
	double				t;
	t_v3				cl;
	t_v3				cp;
	t_v3				cn;
}						t_inter;

typedef struct			s_rt
{
	double				i;
	double				j;
	double				x;
	double				y;
	int					final;
	t_v3				pixel;
	t_ray				r;
	t_v3				clr;
	int					bmp_y;
}						t_rt;

typedef struct			s_header
{
	int					size;
	int32_t				width;
	int32_t				height;
	int16_t				bitcount;
	int					width_b;
	int32_t				imagesize;
	uint32_t			bisize;
	uint32_t			bfoffbits;
	uint32_t			filesize;
	uint16_t			biplanes;
}						t_header;

#endif
