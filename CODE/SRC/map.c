/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:29:13 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 06:51:15 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

int		read_map_error(char *path)
{
	put_str("the file : ");
	put_str(path);
	put_str("not valid\n");
	return (0);
}

int		read_map_line(int **map, int line, char *buf)
{
	int		i;

	i = -1;
	while (++i < 25)
	{
		map[line][i] = (buf[i] - '0');
		if (buf[i] < '0' || buf[i] > '4' || ((line == 0 || line == 20) &&\
					(i == 0 || i == 24) && (map[line][i] == 0)))
			return (0);
	}
	return (1);
}

int		read_map_file(char *path, int **map)
{
	int		fd;
	int		line;
	char	buf[26];

	if ((fd = open(path, O_RDONLY)) == -1)
		return (read_map_error(path));
	line = -1;
	while (++line < 20)
	{
		if ((read(fd, buf, 26) != 26) || buf[25] != '\n' ||\
				!(read_map_line(map, line, buf)))
		{
			close(fd);
			return (read_map_error(path));
		}
	}
	if (read(fd, buf, 1) != 0 || line != 20)
	{
		close(fd);
		return (read_map_error(path));
	}
	return (1);
}

t_map	*read_map_data(t_map *map)
{
	if (!(read_map_file("ARCH/MAPS/cave.wol", map->map[0])) ||\
		!(read_map_file("ARCH/MAPS/factor.wol", map->map[1])) ||\
		!(read_map_file("ARCH/MAPS/day.wol", map->map[2])) ||\
		!(read_map_file("ARCH/MAPS/night.wol", map->map[3])) ||\
		!(read_map_file("ARCH/MAPS/test.wol", map->map[4])))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

t_map	*install_map_data(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))) ||\
		!alloc_map(map))
		return (NULL);
	map->mapn = 0;
	map->waln[0] = 0;
	map->waln[1] = 1;
	map->waln[2] = 2;
	map->waln[3] = 3;
	map->waln[4] = 0;
	map->boyn[0] = 0;
	map->boyn[1] = 1;
	map->boyn[2] = 2;
	map->boyn[3] = 3;
	map->boyn[4] = 0;
	map->wopn[0] = 1;
	map->wopn[1] = 0;
	map->wopn[2] = 1;
	map->wopn[3] = 0;
	map->wopn[4] = 0;
	return (read_map_data(map));
}
