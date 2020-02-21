/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 04:15:06 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 08:52:25 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	draw_start_selection(t_sta *sta, t_wolf *wolf, int x, int y)
{
	if (x >= SX && x <= SMX && y >= SY && y <= SMY)
		put_png_ptr(sta->frm4, SX, SY, wolf->mlx);
	else if (x >= XX && x <= XMX && y >= XY && y <= XMY)
		put_png_ptr(sta->frm3, XX, XY, wolf->mlx);
	else if (x >= M0X && x <= M0MX && y >= M0Y && y <= M0MY)
		put_png_ptr(sta->frm2, M0X, M0Y, wolf->mlx);
	else if (x >= M1X && x <= M1MX && y >= M1Y && y <= M1MY)
		put_png_ptr(sta->frm2, M1X, M1Y, wolf->mlx);
	else if (x >= M2X && x <= M2MX && y >= M2Y && y <= M2MY)
		put_png_ptr(sta->frm2, M2X, M2Y, wolf->mlx);
	else if (x >= M3X && x <= M3MX && y >= M3Y && y <= M3MY)
		put_png_ptr(sta->frm2, M3X, M3Y, wolf->mlx);
	else if (x >= M4X && x <= M4MX && y >= M4Y && y <= M4MY)
		put_png_ptr(sta->frm2, M4X, M4Y, wolf->mlx);
}

void	event_start_mouse(t_wolf *wolf, t_evt *evt, int x, int y)
{
	if (x >= SX && x <= SMX && y >= SY && y <= SMY)
	{
		evt->evt = -2;
		zero_player(&wolf->player);
		Mix_PauseMusic();
		detect_music(wolf);
	}
	else if (x >= XX && x <= XMX && y >= XY && y <= XMY)
		destroy_wolf_data(wolf, 0);
	else if (x >= M0X && x <= M0MX && y >= M0Y && y <= M0MY)
		wolf->map->mapn = 0;
	else if (x >= M1X && x <= M1MX && y >= M1Y && y <= M1MY)
		wolf->map->mapn = 1;
	else if (x >= M2X && x <= M2MX && y >= M2Y && y <= M2MY)
		wolf->map->mapn = 2;
	else if (x >= M3X && x <= M3MX && y >= M3Y && y <= M3MY)
		wolf->map->mapn = 3;
	else if (x >= M4X && x <= M4MX && y >= M4Y && y <= M4MY)
	{
		wolf->map->mapn = 4;
		draw_gen(wolf->gen, wolf);
		evt->evt = -1;
	}
}

void	draw_start(t_sta *sta, t_wolf *wolf)
{
	put_png_ptr(wolf->load->png_ptr[1], 0, wolf->load->y, wolf->mlx);
	put_png_ptr(wolf->load->png_ptr[2], 0, wolf->load->y - SH, wolf->mlx);
	put_png_ptr(wolf->load->png_ptr[0], 0, 0, wolf->mlx);
	put_png_ptr(sta->frm0, 0, 0, wolf->mlx);
	if (wolf->map->mapn == 0)
		put_png_ptr(sta->frm1, M0X, M0Y, wolf->mlx);
	if (wolf->map->mapn == 1)
		put_png_ptr(sta->frm1, M1X, M1Y, wolf->mlx);
	if (wolf->map->mapn == 2)
		put_png_ptr(sta->frm1, M2X, M2Y, wolf->mlx);
	if (wolf->map->mapn == 3)
		put_png_ptr(sta->frm1, M3X, M3Y, wolf->mlx);
	if (wolf->map->mapn == 4)
		put_png_ptr(sta->frm1, M4X, M4Y, wolf->mlx);
	draw_start_selection(sta, wolf, wolf->evt.mx, wolf->evt.my);
	if (wolf->evt.man == 1)
		put_png_ptr(sta->man, MANX, MANY, wolf->mlx);
	put_png_ptr(sta->mous, wolf->evt.mx, wolf->evt.my, wolf->mlx);
	wolf->load->y = wolf->load->y == SH ? 0 : wolf->load->y + 10;
}
