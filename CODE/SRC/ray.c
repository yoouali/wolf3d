/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:57:27 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 09:33:47 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

int			get_color(int color, double dist)
{
	int r;
	int g;
	int b;

	r = ((color >> 16) & 255);
	g = ((color >> 8) & 255);
	b = (color & 255);
	r = (r * (1.0 - dist / 4) > 0.0) ? r * (1.0 - dist / 4) : 0;
	g = (g * (1.0 - dist / 4) > 0.0) ? g * (1.0 - dist / 4) : 0;
	b = (b * (1.0 - dist / 4) > 0.0) ? b * (1.0 - dist / 4) : 0;
	return ((r << 16) | (g << 8) | b);
}

t_point		rotat(t_point p, double angle)
{
	t_point r;
	t_point	old;
	double	v;

	v = angle * PI / 180;
	old.x = p.x;
	old.y = p.y;
	r.x = p.x * cos(v) - p.y * sin(v);
	r.y = old.x * sin(v) + old.y * cos(v);
	return (r);
}

void		draw_wolf(t_wolf *wolf)
{
	pthread_t	trd[4];
	int			i;

	wolf->flo = NULL;
	wolf->cel = NULL;
	wolf->flo = wolf->boy->wals[wolf->map->boyn[wolf->map->mapn]].f.data_img;
	wolf->cel = wolf->boy->wals[wolf->map->boyn[wolf->map->mapn]].c.data_img;
	pthread_create(&trd[0], NULL, part1, (void*)wolf);
	pthread_create(&trd[1], NULL, part2, (void*)wolf);
	pthread_create(&trd[2], NULL, part3, (void*)wolf);
	pthread_create(&trd[3], NULL, part4, (void*)wolf);
	i = -1;
	while (++i < 4)
		pthread_join(trd[i], NULL);
}

void		clear_data_img(int *tab)
{
	int i;

	i = 0;
	while (i < SW * SH)
	{
		tab[i] = 0;
		i++;
	}
}

void		draw_rayc(t_wolf *wolf)
{
	clear_data_img(wolf->mlx->img_data);
	mlx_clear_window(wolf->mlx->mlx_ptr, wolf->mlx->win_ptr);
	draw_box(wolf, &wolf->boy->box, &wolf->evt);
	draw_wolf(wolf);
	draw_mmap(wolf, wolf->mmap);
	mlx_put_image_to_window(wolf->mlx->mlx_ptr, wolf->mlx->win_ptr,\
	wolf->mlx->img_ptr, 0, 0);
	mlx_put_image_to_window(wolf->mlx->mlx_ptr, wolf->mlx->win_ptr,\
	wolf->mmap->wolf, wolf->player.pos.y * 10 - 5, wolf->player.pos.x * 10 - 5);
}
