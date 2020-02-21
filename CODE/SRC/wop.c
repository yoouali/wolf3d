/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 02:53:05 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 09:10:07 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	draw_wop(t_wolf *wolf, t_evt *evt, t_wop *wop)
{
	int		x;
	int		y;
	int		gos;

	x = 700;
	y = 700;
	gos = wolf->map->wopn[wolf->map->mapn];
	if (wolf->map->wopn[gos] == 0)
	{
		x = 0;
		y = 0;
	}
	if (evt->wap == 1)
		mlx_put_image_to_window(wolf->mlx->mlx_ptr,\
				wolf->mlx->win_ptr, wop->wop[gos][wop->frm], x, y);
	if (evt->wop != 0)
	{
		wop->frm += 1;
		if (wop->frm == 7)
		{
			wop->frm = 0;
			evt->wop = 0;
		}
	}
}
