/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:04:32 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/21 01:01:31 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

int		mouse_move(int x, int y, t_wolf *wolf)
{
	t_evt *evt;

	evt = &wolf->evt;
	evt->mx = x;
	evt->my = y;
	if (wolf->evt.evt == 2)
		mouse_wolf(wolf);
	return (0);
}

void	mouse_event_pres2(int bot, int x, int y, t_wolf *wolf)
{
	if (bot == 1 && x >= UX && x <= UMX && y >= UY && y <= UMY &&\
	(wolf->evt.evt == 0 || wolf->evt.evt == 1) && wolf->evt.man == 0)
		wolf->evt.man = 1;
	else
		wolf->evt.man = 0;
	if (wolf->evt.evt == 2 && bot == 1 && wolf->evt.wop ==\
			0 && wolf->evt.wap == 1)
	{
		if (wolf->evt.sound == 1)
		{
			if (wolf->map->wopn[wolf->map->mapn])
				Mix_PlayChannel(2, wolf->mus->spear, 0);
			else
				Mix_PlayChannel(2, wolf->mus->gun, 0);
		}
		wolf->evt.wop = 1;
	}
	if (wolf->evt.evt == -2)
		wolf->evt.evt = 2;
}

int		mouse_event_pres(int bot, int x, int y, t_wolf *wolf)
{
	if (wolf->evt.evt == 0 && bot == 1)
	{
		if (wolf->evt.sound == 1)
			Mix_PlayChannel(2, wolf->sta->click, 0);
		event_start_mouse(wolf, &wolf->evt, x, y);
	}
	if (wolf->evt.evt == 1 && (bot == 1 || bot == 2))
	{
		if (wolf->evt.sound == 1)
			Mix_PlayChannel(2, wolf->sta->click, 0);
		gen_event_mouse(wolf, bot, x, y);
	}
	if (wolf->evt.evt == -1)
		wolf->evt.evt = 1;
	mouse_event_pres2(bot, x, y, wolf);
	return (0);
}

int		update_wolf(t_wolf *wolf)
{
	mlx_mouse_hide();
	mlx_clear_window(wolf->mlx->mlx_ptr, wolf->mlx->win_ptr);
	if (wolf->evt.evt == 0)
		draw_start(wolf->sta, wolf);
	else if (wolf->evt.evt == 1)
		draw_gen(wolf->gen, wolf);
	else if (wolf->evt.evt == 2 || wolf->evt.evt == -2)
	{
		update_move(wolf, &wolf->evt);
		draw_rayc(wolf);
		draw_wop(wolf, &wolf->evt, &wolf->boy->wop);
	}
	return (0);
}

int		main(void)
{
	t_wolf	*wolf;

	wolf = loading_wolf_data();
	mlx_loop_hook(wolf->mlx->mlx_ptr, update_wolf, wolf);
	mlx_hook(wolf->mlx->win_ptr, 4, 0, mouse_event_pres, wolf);
	mlx_hook(wolf->mlx->win_ptr, 2, 0, key_event_pres, wolf);
	mlx_hook(wolf->mlx->win_ptr, 3, 0, key_event_relese, wolf);
	mlx_hook(wolf->mlx->win_ptr, 6, 0, mouse_move, wolf);
	mlx_loop(wolf->mlx->mlx_ptr);
	return (0);
}
