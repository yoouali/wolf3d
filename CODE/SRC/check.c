/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 06:18:49 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 06:30:22 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	check_moves(int key, t_wolf *wolf, t_evt *evt)
{
	if ((key == UP || key == DOWN || key == RIGHT || key == LEFT)\
			&& evt->sound == 1 && evt->evt == 2 && evt->moves == 0)
	{
		Mix_PlayChannel(3, wolf->mus->move, -1);
		evt->moves = 1;
	}
	if (key == UP)
		evt->mup = 1;
	if (key == DOWN)
		evt->mdown = 1;
	if (key == RIGHT)
		evt->mright = 1;
	if (key == LEFT)
		evt->mlift = 1;
	if (key == 124)
		evt->lright = 1;
	if (key == 123)
		evt->llift = 1;
	if (key == LOOK_UP)
		evt->lup = 1;
	if (key == LOOK_DW)
		evt->ldown = 1;
}

void	check_rotation(int key, t_evt *evt)
{
	if (key == 124)
		evt->lright = 1;
	if (key == 123)
		evt->llift = 1;
	if (key == LOOK_UP)
		evt->lup = 1;
	if (key == LOOK_DW)
		evt->ldown = 1;
	if (key == SPACE && evt->jump == 0)
		evt->jump = 1;
	if (key == 257 && evt->crow == 0)
		evt->crow = 1;
	if (key == T)
		evt->light = evt->light == 0 ? 1 : 0;
}

void	check_seting2(int key, t_wolf *wolf, t_evt *evt)
{
	if (key == N)
	{
		evt->sound = evt->sound == 1 ? 0 : 1;
		if (evt->moves == 1)
		{
			if (evt->sound == 0)
				Mix_HaltChannel(3);
			else
				Mix_PlayChannel(3, wolf->mus->move, -1);
		}
	}
	if (key == Y)
		evt->wap = evt->wap == 0 ? 1 : 0;
}

void	check_seting(int key, t_wolf *wolf, t_evt *evt)
{
	if (key == M)
	{
		if (evt->music == 1)
		{
			Mix_PauseMusic();
			evt->music = 0;
		}
		else
		{
			evt->music = 1;
			if (evt->evt == 1 || evt->evt == 0)
				Mix_PlayMusic(wolf->sta->sound, -1);
			else
				detect_music(wolf);
		}
	}
	check_seting2(key, wolf, evt);
}
