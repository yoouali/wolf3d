/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:50:52 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/21 01:08:33 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	update_move1(t_wolf *wolf, t_evt *evt)
{
	if (evt->mright == 1)
	{
		if (wolf->map->map[wolf->map->mapn][(int)(wolf->player.pos.x +\
			wolf->player.direction.y * 0.1)][(int)wolf->player.pos.y] == 0)
			wolf->player.pos.x += wolf->player.direction.y * 0.05;
		if (wolf->map->map[wolf->map->mapn][(int)(wolf->player.pos.x)][\
			(int)(wolf->player.pos.y - wolf->player.direction.x * 0.1)] == 0)
			wolf->player.pos.y -= wolf->player.direction.x * 0.05;
	}
	if (evt->mlift == 1)
	{
		if (wolf->map->map[wolf->map->mapn][(int)(wolf->player.pos.x\
			- wolf->player.direction.y * 0.1)][(int)wolf->player.pos.y] == 0)
			wolf->player.pos.x -= wolf->player.direction.y * 0.05;
		if (wolf->map->map[wolf->map->mapn][(int)(wolf->player.pos.x)]\
			[(int)(wolf->player.pos.y + wolf->player.direction.x * 0.1)] == 0)
			wolf->player.pos.y += wolf->player.direction.x * 0.05;
	}
	if (evt->lup == 1)
	{
		if (wolf->player.up_dw < 400)
			wolf->player.up_dw += 20;
	}
}

void	update_move2(t_wolf *wolf, t_evt *evt)
{
	if (evt->ldown == 1)
	{
		if (wolf->player.up_dw > -400)
			wolf->player.up_dw -= 20;
	}
	if (evt->lright == 1)
	{
		wolf->player.direction = rotat(wolf->player.direction, -5);
		wolf->player.plane = rotat(wolf->player.plane, -5);
		evt->x -= 62;
		if (evt->x <= 2100)
			evt->x = 0;
	}
	if (evt->llift == 1)
	{
		wolf->player.direction = rotat(wolf->player.direction, 5);
		wolf->player.plane = rotat(wolf->player.plane, 5);
		evt->x += 62;
		if (evt->x >= 0)
			evt->x = -2100;
	}
}

void	update_move3(t_wolf *wolf, t_evt *evt)
{
	if (evt->jump != 0)
	{
		if (evt->jumpc == 1)
			wolf->player.up_dw += 30;
		if (evt->jumpc == -1)
			wolf->player.up_dw -= 30;
		evt->jumpt += evt->jumpc;
		if (evt->jumpc == 1 && evt->jumpt == 4)
			evt->jumpc = -1;
		if (evt->jumpc == -1 && evt->jumpt == 0)
		{
			evt->jump = 0;
			evt->jumpc = 1;
		}
	}
	if (evt->crow != 0 && evt->crowt > -6)
	{
		evt->crowt -= 1;
		wolf->player.up_dw -= 25;
	}
	if (evt->crow == 0 && evt->crowt < 0)
	{
		evt->crowt += 1;
		wolf->player.up_dw += 25;
	}
}

void	update_move(t_wolf *wolf, t_evt *evt)
{
	if (evt->mup == 1)
	{
		if (wolf->map->map[wolf->map->mapn][(int)(wolf->player.pos.x\
			+ wolf->player.direction.x * 0.1)][(int)wolf->player.pos.y] == 0)
			wolf->player.pos.x += wolf->player.direction.x * 0.05;
		if (wolf->map->map[wolf->map->mapn][(int)wolf->player.pos.x]\
			[(int)(wolf->player.pos.y + wolf->player.direction.y * 0.1)] == 0)
			wolf->player.pos.y += wolf->player.direction.y * 0.05;
	}
	if (evt->mdown == 1)
	{
		if (wolf->map->map[wolf->map->mapn][(int)(wolf->player.pos.x -\
			wolf->player.direction.x * 0.1)][(int)wolf->player.pos.y] == 0)
			wolf->player.pos.x -= wolf->player.direction.x * 0.05;
		if (wolf->map->map[wolf->map->mapn][(int)wolf->player.pos.x][\
			(int)(wolf->player.pos.y - wolf->player.direction.y * 0.1)] == 0)
			wolf->player.pos.y -= wolf->player.direction.y * 0.05;
	}
	update_move1(wolf, evt);
	update_move2(wolf, evt);
	update_move3(wolf, evt);
}
