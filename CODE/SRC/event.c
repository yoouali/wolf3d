/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:07:27 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 06:36:26 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	key_event_pres2(int key, t_wolf *wolf, t_evt *evt)
{
	check_moves(key, wolf, evt);
	check_rotation(key, evt);
	if (key == 258 && evt->wop == 0 && evt->evt == 2 && evt->wap == 1)
	{
		if (evt->sound == 1)
		{
			if (wolf->map->wopn[wolf->map->mapn])
				Mix_PlayChannel(2, wolf->mus->spear, 0);
			else
				Mix_PlayChannel(2, wolf->mus->gun, 0);
		}
		evt->wop = 1;
	}
	check_seting(key, wolf, evt);
}

int		key_event_pres(int key, t_wolf *wolf)
{
	t_evt	*evt;

	evt = &wolf->evt;
	if (key == 53 && evt->evt == 0)
		destroy_wolf_data(wolf, 0);
	if (key == 53 && evt->evt == 1)
		evt->evt = 0;
	if (key == 53 && evt->evt == 2)
	{
		evt->evt = 0;
		if (evt->music == 1)
		{
			Mix_PauseMusic();
			Mix_PlayMusic(wolf->sta->sound, -1);
		}
	}
	key_event_pres2(key, wolf, evt);
	return (0);
}

void	key_event_relese2(int key, t_evt *evt)
{
	if (key == LOOK_DW)
		evt->ldown = 0;
	if (key == 257)
		evt->crow = 0;
	if (evt->mup == 0 && evt->mdown == 0 && evt->mright == 0\
			&& evt->mlift == 0 && evt->evt == 2 && evt->moves == 1)
	{
		Mix_HaltChannel(3);
		evt->moves = 0;
	}
}

int		key_event_relese(int key, t_wolf *wolf)
{
	t_evt	*evt;

	evt = &wolf->evt;
	if (key == UP)
		evt->mup = 0;
	if (key == DOWN)
		evt->mdown = 0;
	if (key == RIGHT)
		evt->mright = 0;
	if (key == LEFT)
		evt->mlift = 0;
	if (key == 124)
		evt->lright = 0;
	if (key == 123)
		evt->llift = 0;
	if (key == LOOK_UP)
		evt->lup = 0;
	key_event_relese2(key, evt);
	return (0);
}
