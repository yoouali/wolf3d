/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:09:58 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 09:33:28 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	init_side(t_side *s)
{
	s->o = 0;
	s->n = 0;
	s->e = 0;
	s->s = 0;
}

void	init_ray_cmp2(t_ray *ray, t_wolf *f)
{
	if (ray->direction.x < 0)
	{
		ray->sidedist.x = (f->player.pos.x - ray->mapx) * ray->deltadist.x;
		ray->stepx = -1;
	}
	else
	{
		ray->sidedist.x = (ray->mapx + 1.0 - f->player.pos.x) *
			ray->deltadist.x;
		ray->stepx = 1;
	}
	if (ray->direction.y < 0)
	{
		ray->sidedist.y = (f->player.pos.y - ray->mapy) *
			ray->deltadist.y;
		ray->stepy = -1;
	}
	else
	{
		ray->sidedist.y = (ray->mapy + 1.0 - f->player.pos.y) *
			ray->deltadist.y;
		ray->stepy = 1;
	}
}

void	init_ray_cmp(t_ray *ray, t_wolf *f, int x)
{
	ray->cln_pos = 2.0 * (double)x / (double)SW - 1.0;
	ray->direction.x = f->player.direction.x + ray->cln_pos * f->player.plane.x;
	ray->direction.y = f->player.direction.y + ray->cln_pos * f->player.plane.y;
	ray->deltadist.x = (ray->direction.x != 0) ? fabs(1 / ray->direction.x) : 0;
	ray->deltadist.y = (ray->direction.x != 0) ? fabs(1 / ray->direction.y) : 0;
	ray->mapx = (int)f->player.pos.x;
	ray->mapy = (int)f->player.pos.y;
	init_ray_cmp2(ray, f);
}

void	detect_walls(t_wolf *f, t_ray *ray)
{
	while (1)
	{
		init_side(&ray->side);
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->mapx += ray->stepx;
			if (ray->direction.x > 0)
				ray->side.s = 1;
			else
				ray->side.n = 1;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->mapy += ray->stepy;
			if (ray->direction.y > 0)
				ray->side.e = 1;
			else
				ray->side.o = 1;
		}
		if (f->map->map[f->map->mapn][ray->mapx][ray->mapy] > 0)
			break ;
	}
}
