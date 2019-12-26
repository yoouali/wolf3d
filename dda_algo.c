/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 05:31:08 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/12/22 05:08:56 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			abs(int n)
{
	return ((n > 0) ? n : ( n * (-1)));
}

void		dda(t_point p1, t_point p2, t_mlx *mlx, int color)
{
	t_dda a;
	int i;

	i = -1;
	a.dx = p2.x - p1.x;
	a.dy = p2.y - p1.y;
	a.steps = (abs(a.dx) > abs(a.dy)) ? abs(a.dx) : abs(a.dy);
	a.p.x = p1.x;
	a.p.y = p1.y;
	a.xinc = a.dx / a.steps;
	a.yinc = a.dy / a.steps;
	while (++i < a.steps)
	{
		mlx->data[(int)a.p.y * w + (int)a.p.x] = color;
		a.p.x += a.xinc;
		a.p.y += a.yinc;
	}
}

/********************************************************************/
/*void	part1(t_bres v, void *mlx_ptr, void *win_ptr, int *data, int color)
{
	int		inc1;
	int		inc2;

	v.e = (2 * v.dy) - v.dx;
	v.i = -1;
	inc1 = 2 * (v.dy - v.dx);
	inc2 = 2 * (v.dy);
	while (++v.i < v.dx)
	{
		if (v.e >= 0)
		{
			v.e = v.e + inc1;
			v.ord += v.stepy;
		}
		else
			v.e = v.e + inc2;
		v.abs += v.stepx;
		data[(int)v.ord * WI + (int)v.abs] = color;
	}
}

void	part2(t_bres v, void *mlx_ptr, void *win_ptr, int *data, int color)
{
	int		inc1;
	int		inc2;

	v.e = (2 * v.dx) - v.dy;
	v.i = -1;
	inc1 = 2 * (v.dx - v.dy);
	inc2 = 2 * (v.dx);
	while (++v.i < v.dy)
	{
		if (v.e >= 0)
		{
			v.e = v.e + inc1;
			v.abs += v.stepx;
		}
		else
			v.e = v.e + inc2;
		v.ord += v.stepy;
		data[(int)v.ord * WI + (int)v.abs] = color;
	}
}

void	draw_line(t_point p1, t_point p2, t_mlx *f, int color)
{
	t_bres	v;

	v.abs = p1.x;
	v.ord = p1.y;
	v.dx = p2.x - p1.x;
	v.dy = p2.y - p1.y;
	v.stepx = (v.dx > 0) ? 1 : -1;
	v.stepy = (v.dy > 0) ? 1 : -1;
	v.dx = abs(v.dx);
	v.dy = abs(v.dy);
	f->data[(int)v.ord * WI + (int)v.abs] = 0xff;
	if (v.dx > v.dy)
		part1(v, f->mlx_ptr, f->win_ptr, f->data, color);
	else
		part2(v, f->mlx_ptr, f->win_ptr, f->data, color);
}*/
