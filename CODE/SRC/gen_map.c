/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:13:29 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 06:40:44 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	gen_select_event2(t_evt *evt, t_wolf *wolf, int x, int y)
{
	if (x >= E3X && x <= E3MX && y >= EY && y <= EMY)
		wolf->map->boyn[4] = 2;
	else if (x >= PX && x <= PMX && y >= P0Y && y <= P0MY)
		wolf->map->wopn[4] = 0;
	else if (x >= PX && x <= PMX && y >= P1Y && y <= P1MY)
		wolf->map->wopn[4] = 1;
	else if (x >= OSX && x <= OSMX && y >= OY && y <= OMY)
	{
		evt->evt = -2;
		zero_player(&wolf->player);
		Mix_PauseMusic();
		detect_music(wolf);
	}
	else if (x >= OBX && x <= OBMX && y >= OY && y <= OMY)
		evt->evt = 0;
}

void	gen_select_event(t_evt *evt, t_wolf *wolf, int x, int y)
{
	if (x >= WX && x <= WMX && y >= W0Y && y <= W0MY)
		wolf->map->waln[4] = 0;
	else if (x >= WX && x <= WMX && y >= W1Y && y <= W1MY)
		wolf->map->waln[4] = 1;
	else if (x >= WX && x <= WMX && y >= W2Y && y <= W2MY)
		wolf->map->waln[4] = 2;
	else if (x >= WX && x <= WMX && y >= W3Y && y <= W3MY)
		wolf->map->waln[4] = 3;
	else if (x >= E0X && x <= E0MX && y >= EY && y <= EMY)
		wolf->map->boyn[4] = 0;
	else if (x >= E1X && x <= E1MX && y >= EY && y <= EMY)
		wolf->map->boyn[4] = 1;
	else if (x >= E2X && x <= E2MX && y >= EY && y <= EMY)
		wolf->map->boyn[4] = 3;
	gen_select_event2(evt, wolf, x, y);
}

void	gen_event_mouse(t_wolf *wolf, int bot, int x, int y)
{
	int		posx;
	int		posy;

	posx = (int)((x - GX) / 30);
	posy = (int)((y - GY) / 30);
	if (x >= GX && x <= GMX && y >= GY && y <= GMY)
	{
		if (bot == 1 && (posx < 1 || posx > 3 || posy < 1 || posy > 3))
			wolf->map->map[4][posy][posx] = wolf->map->waln[4] + 1;
		else if (bot == 2 && posx != 0 && posy != 0 && posx != 24 && posy != 19)
			wolf->map->map[4][posy][posx] = 0;
	}
	else if (bot == 1)
		gen_select_event(&wolf->evt, wolf, x, y);
}

void	draw_gen_map(t_gen *gen, t_wolf *wolf)
{
	int		*data[2];
	int		c[5];

	if (!(data[0] = (int *)mlx_get_data_addr(gen->frm0, &c[2], &c[3], &c[4])))
		destroy_wolf_data(wolf, 1);
	c[0] = -1;
	while (++c[0] < 20)
	{
		c[1] = -1;
		while (++c[1] < 25)
		{
			if (!(data[1] = (int *)mlx_get_data_addr(gen->wal[wolf->map->map\
							[4][c[0]][c[1]]], &c[2], &c[3], &c[4])))
				destroy_wolf_data(wolf, 1);
			c[2] = -1;
			while (++c[2] < 30)
			{
				c[3] = -1;
				while (++c[3] < 30)
					data[0][(c[0] * 30 + c[2] + GY) * SW + (c[1] * 30 + c[3]\
						+ GX)] = data[1][c[2] * 30 + c[3]];
			}
		}
	}
}

void	draw_gen(t_gen *gen, t_wolf *wolf)
{
	draw_gen_map(gen, wolf);
	put_png_ptr(gen->frm0, 0, 0, wolf->mlx);
	if (wolf->map->boyn[wolf->map->mapn] == 0)
		put_png_ptr(gen->frm1, E0X, EY, wolf->mlx);
	else if (wolf->map->boyn[wolf->map->mapn] == 1)
		put_png_ptr(gen->frm1, E1X, EY, wolf->mlx);
	else if (wolf->map->boyn[wolf->map->mapn] == 3)
		put_png_ptr(gen->frm1, E2X, EY, wolf->mlx);
	else if (wolf->map->boyn[wolf->map->mapn] == 2)
		put_png_ptr(gen->frm1, E3X, EY, wolf->mlx);
	if (wolf->map->wopn[wolf->map->mapn] == 0)
		put_png_ptr(gen->frm1, PX, P0Y, wolf->mlx);
	else if (wolf->map->wopn[wolf->map->mapn] == 1)
		put_png_ptr(gen->frm1, PX, P1Y, wolf->mlx);
	if (wolf->map->waln[wolf->map->mapn] == 0)
		put_png_ptr(gen->frm1, WX, W0Y, wolf->mlx);
	else if (wolf->map->waln[wolf->map->mapn] == 1)
		put_png_ptr(gen->frm1, WX, W1Y, wolf->mlx);
	else if (wolf->map->waln[wolf->map->mapn] == 2)
		put_png_ptr(gen->frm1, WX, W2Y, wolf->mlx);
	else if (wolf->map->waln[wolf->map->mapn] == 3)
		put_png_ptr(gen->frm1, WX, W3Y, wolf->mlx);
	if (wolf->evt.man == 1)
		put_png_ptr(wolf->sta->man, MANX, MANY, wolf->mlx);
	put_png_ptr(wolf->sta->mous, wolf->evt.mx, wolf->evt.my, wolf->mlx);
}
