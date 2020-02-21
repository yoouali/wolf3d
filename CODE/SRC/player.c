/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 03:58:36 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 06:58:33 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	zero_player(t_player *player)
{
	player->pos.x = 2;
	player->pos.y = 2;
	player->direction.x = -1;
	player->direction.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.57;
	player->up_dw = 0;
	player->cord[0] = 0;
	player->cord[1] = 0;
}

void	zero_event(t_evt *evt)
{
	evt->music = 1;
	evt->sound = 1;
	evt->jumpt = 0;
	evt->light = 0;
	evt->jump = 0;
	evt->jumpc = 1;
	evt->moves = 0;
	evt->crow = 0;
	evt->crowt = 0;
	evt->mup = 0;
	evt->mdown = 0;
	evt->mright = 0;
	evt->mlift = 0;
	evt->lup = 0;
	evt->ldown = 0;
	evt->lright = 0;
	evt->llift = 0;
	evt->mx = 0;
	evt->my = 0;
	evt->evt = 0;
	evt->man = 0;
	evt->x = -1500;
	evt->wap = 1;
}
