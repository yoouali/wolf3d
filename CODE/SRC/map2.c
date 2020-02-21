/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:59:11 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/10 17:19:48 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

int		free_map(t_map *map)
{
	int		i;
	int		line;

	i = -1;
	while (++i < 5 && map->map[i])
	{
		line = -1;
		while (++line < 20 && map->map[i][line])
			free(map->map[i][line]);
		free(map->map[i]);
	}
	free(map);
	return (0);
}

int		alloc_map(t_map *map)
{
	int		line;
	int		i;

	map->map[0] = NULL;
	map->map[1] = NULL;
	map->map[2] = NULL;
	map->map[3] = NULL;
	map->map[4] = NULL;
	i = -1;
	while (++i < 5)
	{
		if (!(map->map[i] = (int **)malloc(sizeof(int *) * 20)))
			return (free_map(map));
		line = -1;
		while (++line < 20)
		{
			if (!(map->map[i][line] = (int *)malloc(sizeof(int) * 25)))
				return (free_map(map));
		}
	}
	return (1);
}
