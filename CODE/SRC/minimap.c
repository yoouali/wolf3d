/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:44:54 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 07:04:48 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void		draw_mmap2(t_wolf *wolf, t_mmap *map, int mapn)
{
	map->a = 0;
	while (map->a < 10)
	{
		map->b = 0;
		while (map->b < 10)
		{
			if (wolf->map->map[mapn][map->i][map->j] == 0)
				wolf->mlx->img_data[(map->j * 10 + map->b) +\
					(map->i * 10 + map->a) * SW] = map->flor[mapn];
			else
				wolf->mlx->img_data[(map->j * 10 + map->b) +\
					(map->i * 10 + map->a) * SW] = map->walc[mapn];
			map->b += 1;
		}
		map->a += 1;
	}
}

void		draw_mmap(t_wolf *wolf, t_mmap *map)
{
	int		mapn;

	mapn = wolf->map->mapn;
	map->i = 0;
	while (map->i < 20)
	{
		map->j = 0;
		while (map->j < 25)
		{
			draw_mmap2(wolf, map, mapn);
			map->j += 1;
		}
		map->i += 1;
	}
}
