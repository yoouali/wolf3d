/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:34:03 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 06:57:02 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void		move_mouse_p2(t_wolf *f)
{
	if (f->evt.mx - f->player.cord[0] > 0)
	{
		f->player.direction = rotat(f->player.direction, -2);
		f->player.plane = rotat(f->player.plane, -2);
	}
	if (f->evt.mx - f->player.cord[0] < 0)
	{
		f->player.direction = rotat(f->player.direction, 2);
		f->player.plane = rotat(f->player.plane, 2);
	}
}

void		move_mouse_p1(t_wolf *f)
{
	if (f->evt.my - f->player.cord[1] > 0)
	{
		if (f->player.up_dw > -600)
			f->player.up_dw -= 20;
	}
	if (f->evt.my - f->player.cord[1] < 0)
	{
		if (f->player.up_dw < 600)
			f->player.up_dw += 20;
	}
}

void		mouse_wolf(t_wolf *f)
{
	if (f->player.cord[0] && f->player.cord[1])
	{
		move_mouse_p1(f);
		move_mouse_p2(f);
	}
	if (f->evt.mx < 0 || f->evt.mx > SW || f->evt.my < 0 || f->evt.my > SH)
	{
		mlx_mouse_move(f->mlx->win_ptr, SW / 2, SH / 2);
		f->player.cord[0] = 1;
		f->player.cord[1] = 1;
	}
	else
	{
		f->player.cord[0] = f->evt.mx;
		f->player.cord[1] = f->evt.my;
	}
}
