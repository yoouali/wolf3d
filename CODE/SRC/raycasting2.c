/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:29:07 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 09:33:25 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void		init_floor_cel(t_ray *ray)
{
	if ((ray->side.n == 1 || ray->side.s) && ray->direction.x > 0)
	{
		ray->floor.x = ray->mapx;
		ray->floor.y = ray->mapy + ray->pos_rdt;
	}
	else if ((ray->side.n == 1 || ray->side.s == 1) && ray->direction.x < 0)
	{
		ray->floor.x = ray->mapx + 1.0;
		ray->floor.y = ray->mapy + ray->pos_rdt;
	}
	else if ((ray->side.e == 1 || ray->side.o == 1) && ray->direction.y > 0)
	{
		ray->floor.x = ray->mapx + ray->pos_rdt;
		ray->floor.y = ray->mapy;
	}
	else
	{
		ray->floor.x = ray->mapx + ray->pos_rdt;
		ray->floor.y = ray->mapy + 1.0;
	}
	if (ray->draw_end < 0)
		ray->draw_end = SH;
}

void		aplly_flo(t_ray *ray, t_wolf *f, int x, int *flo)
{
	int		y;

	y = ray->draw_end;
	while (y < SH)
	{
		ray->current_dist = SH / (2.0 * (y - f->player.up_dw) - SH);
		ray->per_s = (ray->current_dist) / (ray->corrected_dist);
		ray->current_floor.x = ray->per_s * ray->floor.x +
			(1.0 - ray->per_s) * f->player.pos.x;
		ray->current_floor.y = ray->per_s * ray->floor.y +
			(1.0 - ray->per_s) * f->player.pos.y;
		ray->floor_tex_x = (int)(ray->current_floor.x * 1000) % 1000;
		ray->floor_tex_y = (int)(ray->current_floor.y * 1000) % 1000;
		f->mlx->img_data[y * SW + x] = flo[1000 * ray->floor_tex_y\
	+ ray->floor_tex_x];
		if (f->evt.light == 1)
			f->mlx->img_data[y * SW + x] = get_color(f->mlx->img_data\
					[y * SW + x], ray->current_dist);
		y++;
	}
}

void		aplly_cel(t_ray *ray, t_wolf *f, int x, int *cel)
{
	int		y;

	y = 0;
	while (y < ray->draw_start)
	{
		ray->current_dist = SH / (2.0 * (y - f->player.up_dw) - SH);
		ray->per_s = -1 * (ray->current_dist) / (ray->corrected_dist);
		ray->current_floor.x = ray->per_s * ray->floor.x +
			(1.0 - ray->per_s) * f->player.pos.x;
		ray->current_floor.y = ray->per_s * ray->floor.y +
			(1.0 - ray->per_s) * f->player.pos.y;
		ray->floor_tex_x = (int)(ray->current_floor.x * 1000) % 1000;
		ray->floor_tex_y = (int)(ray->current_floor.y * 1000) % 1000;
		if (f->map->boyn[f->map->mapn] < 2)
		{
			f->mlx->img_data[y * SW + x] =\
	cel[1000 * ray->floor_tex_y + ray->floor_tex_x];
			if (f->evt.light == 1)
				f->mlx->img_data[y * SW + x] = get_color(f->mlx->img_data\
						[y * SW + x], -1.0 * ray->current_dist);
		}
		else
			f->mlx->img_data[y * SW + x] = 0xffffffff;
		y++;
	}
}
