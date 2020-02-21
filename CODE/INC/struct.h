/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:53:36 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 09:35:40 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../../SDL/SDL2.framework/Headers/SDL.h"
# include "../../SDL/SDL2_mixer.framework/Headers/SDL_mixer.h"
# include "../../MLX/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_data;
}				t_mlx;

typedef	struct	s_load
{
	void		*png_ptr[5];
	int			y;
	Mix_Chunk	*gol_wav[2];
	Mix_Music	*load_mus;
}				t_load;

typedef	struct	s_map
{
	int		**map[5];
	int		mapn;
	int		waln[5];
	int		boyn[5];
	int		wopn[5];
}				t_map;

typedef	struct	s_tex
{
	void	*img_ptr;
	int		*data_img;
	int		w;
	int		h;
}				t_tex;

typedef	struct	s_wal
{
	t_tex	n;
	t_tex	e;
	t_tex	s;
	t_tex	w;
	t_tex	c;
	t_tex	f;
}				t_wal;

typedef	struct	s_box
{
	void	*day;
	void	*night;
	int		x;
	int		y;
}				t_box;

typedef	struct	s_wop
{
	void	*wop[2][7];
	int		frm;
}				t_wop;

typedef	struct	s_boy
{
	t_wal		wals[4];
	t_box		box;
	t_wop		wop;
}				t_boy;

typedef	struct	s_sta
{
	void		*frm0;
	void		*frm1;
	void		*frm2;
	void		*frm3;
	void		*frm4;
	void		*mous;
	void		*man;
	Mix_Chunk	*click;
	Mix_Music	*sound;
}				t_sta;

typedef	struct	s_gen
{
	void		*frm0;
	void		*frm1;
	void		*wal[5];
	int			waln;
}				t_gen;

typedef	struct	s_mmap
{
	void	*wolf;
	double	rota;
	int		flor[4];
	int		walc[4];
	int		i;
	int		j;
	int		a;
	int		b;
}				t_mmap;

typedef	struct	s_mus
{
	Mix_Music	*cave;
	Mix_Music	*factor;
	Mix_Music	*day;
	Mix_Music	*night;
	Mix_Chunk	*move;
	Mix_Chunk	*gun;
	Mix_Chunk	*spear;
}				t_mus;

typedef	struct	s_evt
{
	int		music;
	int		sound;
	int		light;
	int		jump;
	int		jumpt;
	int		crow;
	int		crowt;
	int		moves;
	int		jumpc;
	int		mup;
	int		mdown;
	int		mright;
	int		mlift;
	int		lup;
	int		ldown;
	int		lright;
	int		llift;
	int		mx;
	int		my;
	int		wop;
	int		evt;
	int		man;
	int		x;
	int		wap;
}				t_evt;

typedef	struct	s_side
{
	int		n;
	int		e;
	int		s;
	int		o;
}				t_side;

typedef	struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_ray
{
	t_point	direction;
	t_point	deltadist;
	t_point	sidedist;
	t_point	current_floor;
	t_point	floor;
	t_side	side;
	double	cln_pos;
	double	pos_rdt;
	double	corrected_dist;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		line_h;
	int		draw_start;
	int		draw_end;
	double	current_dist;
	double	per_s;
	int		floor_tex_x;
	int		floor_tex_y;
}				t_ray;

typedef	struct	s_player
{
	int		up_dw;
	t_point	direction;
	t_point	pos;
	t_point	plane;
	int		cord[2];
}				t_player;

typedef	struct	s_wolf
{
	t_mlx		*mlx;
	t_load		*load;
	t_map		*map;
	t_boy		*boy;
	t_sta		*sta;
	t_gen		*gen;
	t_mmap		*mmap;
	t_mus		*mus;
	t_player	player;
	t_evt		evt;
	int			*flo;
	int			*cel;
}				t_wolf;

#endif
