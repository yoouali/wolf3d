/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:46:20 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/12/24 05:44:05 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include <math.h>
# define w 1024
# define h 700
# define U 256
# define FOV 60
# define PI 3.14159265
# define mapw 24
# define maph 24
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0


typedef	struct	s_point
{
	double x;
	double y;
}				t_point;

typedef struct	s_dda
{
	t_point	p;
	double	xinc;
	double	yinc;
	int		steps;
	int		dx;
	int		dy;
}				t_dda;

typedef struct	s_mini_map
{
	void	*img_map;
	int		*data_map;
}				mini_map;

typedef struct	s_mlx
{
	int			hi;
	int			wi;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*png[10];
	int			bpp;
	int			size_line;
	int			endian;
	int			*data;
	int			*data_png[10];
}				t_mlx;

typedef struct	s_wolf
{
	t_mlx		mlx;
	Mix_Music 	*mus;
	int			musi;
	mini_map	map;
	t_point		dir;
	t_point		pos;
	t_point		plane;
	int			tex_width;
	int			tex_height;
}				t_wolf;

typedef struct	s_rayc
{
	int			hit;
	int			side;
	double		camera;
	t_point		rayDir;
	int			mapX;
	int			mapY;
	t_point		sideDist;
	t_point		deltaDist;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			lineHeight;
	int			draw_start;
	int			draw_end;
	int			color;
	double		wallX;
}				t_rayc;

typedef struct	s_bres
{
	int			abs;
	int			ord;
	int			dx;
	int			dy;
	int			stepx;
	int			stepy;
	int			e;
	int			i;
	t_point		beg;
	t_point		end;
}				t_bres;


int			 key_press(int key, t_wolf *f);
t_point			rotat(t_point p, t_point p2, double angle);
t_point			ft_find_ip(t_point pos, t_point dir);
void			dda(t_point p1, t_point p2, t_mlx *mlx, int color);
t_point			ft_new_point(double x, double y);
t_point			ft_intersection(t_point pos, t_point dir, t_point p1, t_point p2);
void			ft_draw_dir(t_point p1, t_point p2, t_mlx *mlx, int color);
void			draw_car(t_mlx *mlx, t_point res);
void			draw_line(t_point p1, t_point p2, t_mlx *f, int color);
void			draw_walls(t_mlx *mlx);
void			ft_clear_data(int **tab);
void			draw_player(t_wolf *f);
void			draw_the_FOV_p(t_wolf *f, int map[24][24]);
int				mouse_move(int x, int y, t_wolf *f);
#endif
