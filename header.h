/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:55:59 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/16 17:56:57 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "structs.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdint.h>

# define EPSILON .000000001

t_v3		vplus(t_v3 a, t_v3 b);

t_v3		vpro(t_v3 a, double b);

t_v3		vmin(t_v3 a, t_v3 b);

t_v3		vdiv(t_v3 a, double b);

t_v3		nrm(t_v3 v);

double		nrm2(t_v3 v);

double		dot(t_v3 a, t_v3 b);

t_v3		cross(t_v3 a, t_v3 b);

t_v3		new_vector(void);

t_v3		pt(double x, double y, double z);

t_ray		new_ray(t_v3 o, t_v3 dir);

t_cam		new_c(t_v3 o, t_v3 d, float fov);

t_sp		new_sp(t_v3 v, double r, t_v3 color);
t_pl		new_pl(t_v3 c, t_v3 n, t_v3 rgb);
t_tr		new_tr(t_v3 p1, t_v3 p2, t_v3 p3, t_v3 rgb);
t_sq		new_sq(t_v3 p, t_v3 n, double h, t_v3 rgb);
t_cy		new_cy(t_v3 p, t_v3 n, double d, double h, t_v3 rgb);
t_amb		new_amb(double t, t_v3 clr);
t_l			new_l(t_v3 o, double r, t_v3 clr);
//
double		intersp(t_ray r, t_sp *sp, t_v3 *p, t_v3 *n);
double		interpl(t_ray r, t_pl *pl, t_v3 *p, t_v3 *n);
double		intertr(t_ray r, t_tr *tr, t_v3 *p, t_v3 *n);
double		intersq(t_ray r, t_sq *sq, t_v3 *p, t_v3 *n);
double	    intercy(t_ray r, t_cy *cy, t_v3 *p, t_v3 *n);
//
char		**ft_split(char const *s, char c);
void		ft_free(char **str);
int			color(int r, int g, int b);
t_list		*lstnew(void *content, int id);
void		lstadd_back(t_list **alst, t_list *new);
t_camlist	*lstnewc(void *cam);
void		lstadd_c(t_camlist **alst, t_camlist *new);
//
void		parse(char *pl, t_sc *scene);
int			parse_r(char *line, t_sc *s);
int			parse_a(char *line, t_sc *s);
int			parse_l(char *line, t_sc *s);
int			parse_c(char *line, t_sc *s);
int			parse_sp(char *line, t_sc *s);
int			parse_pl(char *line, t_sc *s);
int			parse_sq(char *line, t_sc *s);
int			parse_tr(char *line, t_sc *s);
int			parse_cy(char *line, t_sc *s);
//
double		get_pr(char *ptr, double nb);
double		getfloat(char *s);
t_v3		get_rgb(char *s);
int			nb_parts(char **s);
int			check(char *s, char c);
int			ft_atoi(const char *str);
int			numcheck(char *s);
t_v3		get_position(char *s);
t_v3		get_normal(char *s);
int			valid_n(t_v3 *p);
int			valid_p(t_v3 *p);
t_v3		*valcolor(t_v3 *clr);
//
void	    printv3(char *s, t_v3 v);
//
int 		esc_key(int key, void *param);
int			ft_exit(void);
int			keys(int key, void *param);
t_param		*fill_param(t_camlist **cams, t_sc *sc, t_mlx *img);
//
t_cam		*setupcamera(t_camlist *c_list);
void		next_cam(t_camlist **list);
void		prev_cam(t_camlist **list);
void		lstadd_c(t_camlist **alst, t_camlist *new);
//
void		raytrace(t_cam *c, t_sc *sc, t_mlx *img);
void	    raytracebmp(t_cam *c, t_sc *sc, t_mlx *img, unsigned char *pixels);
void	    initialize_inter(t_inter *var, t_sc *sc);
t_v3		inter(t_ray r, t_sc *sc);
//
double		minmax(double x);
double		max(double a, double b);
double		min(double a, double b);
int		    ft_strncmp(const char *s1, const char *s2, size_t n);
//
t_v3	    cpt(t_v3 color, t_sc *sc, t_v3 *p, t_v3 *n);
//
t_header	header_info(t_sc *sc);
void		fill_header(t_header h, unsigned char *header);
void		create_bmp(unsigned char *header, unsigned char *pixels, int size);

#endif
