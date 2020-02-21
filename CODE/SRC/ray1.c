/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:10:52 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 09:20:04 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void		*part1(void *arg)
{
	t_wolf	*wolf;
	int		x;
	t_ray	ray;

	wolf = (t_wolf*)arg;
	x = 0;
	while (x < 375)
	{
		init_ray_cmp(&ray, wolf, x);
		detect_walls(wolf, &ray);
		detect_side_wallh(&ray, wolf);
		draw_text(wolf, x, &ray);
		init_floor_cel(&ray);
		aplly_flo(&ray, wolf, x, wolf->flo);
		aplly_cel(&ray, wolf, x, wolf->cel);
		x++;
	}
	return (NULL);
}

void		*part2(void *arg)
{
	t_wolf	*wolf;
	int		x;
	t_ray	ray;

	wolf = (t_wolf*)arg;
	x = 375;
	while (x < 750)
	{
		init_ray_cmp(&ray, wolf, x);
		detect_walls(wolf, &ray);
		detect_side_wallh(&ray, wolf);
		draw_text(wolf, x, &ray);
		init_floor_cel(&ray);
		aplly_flo(&ray, wolf, x, wolf->flo);
		aplly_cel(&ray, wolf, x, wolf->cel);
		x++;
	}
	return (NULL);
}

void		*part3(void *arg)
{
	t_wolf	*wolf;
	int		x;
	t_ray	ray;

	wolf = (t_wolf*)arg;
	x = 750;
	while (x < 1100)
	{
		init_ray_cmp(&ray, wolf, x);
		detect_walls(wolf, &ray);
		detect_side_wallh(&ray, wolf);
		draw_text(wolf, x, &ray);
		init_floor_cel(&ray);
		aplly_flo(&ray, wolf, x, wolf->flo);
		aplly_cel(&ray, wolf, x, wolf->cel);
		x++;
	}
	return (NULL);
}

void		*part4(void *arg)
{
	t_wolf	*wolf;
	int		x;
	t_ray	ray;

	wolf = (t_wolf*)arg;
	x = 1100;
	while (x < 1500)
	{
		init_ray_cmp(&ray, wolf, x);
		detect_walls(wolf, &ray);
		detect_side_wallh(&ray, wolf);
		draw_text(wolf, x, &ray);
		init_floor_cel(&ray);
		aplly_flo(&ray, wolf, x, wolf->flo);
		aplly_cel(&ray, wolf, x, wolf->cel);
		x++;
	}
	return (NULL);
}
