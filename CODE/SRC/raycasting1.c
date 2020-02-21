/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:16:12 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 09:33:27 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	detect_side_wallh(t_ray *ray, t_wolf *f)
{
	if (ray->side.n || ray->side.s)
		ray->corrected_dist = (ray->mapx - f->player.pos.x +
				(1 - ray->stepx) / 2) / ray->direction.x;
	else
		ray->corrected_dist = (ray->mapy - f->player.pos.y +
				(1 - ray->stepy) / 2) / ray->direction.y;
	ray->line_h = (int)((SH) / ray->corrected_dist);
	ray->draw_start = -ray->line_h / 2 + SH / 2 + f->player.up_dw;
	ray->draw_end = ray->line_h / 2 + SH / 2 + f->player.up_dw;
	if (ray->draw_end >= SW)
		ray->draw_end = SW - 1;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
}

int		*detect_tex(t_ray *ray, t_wal wal)
{
	if (ray->side.n == 1)
		return (wal.n.data_img);
	else if (ray->side.s == 1)
		return (wal.s.data_img);
	else if (ray->side.e == 1)
		return (wal.e.data_img);
	return (wal.w.data_img);
}

void	draw_text2(t_wolf *f, int x, t_ray *ray, int texx)
{
	int		i;
	int		texy;
	int		*data_tex;
	t_wal	wal;

	wal = f->boy->wals[f->map->map[f->map->mapn][ray->mapx][ray->mapy] - 1];
	data_tex = detect_tex(ray, wal);
	i = ray->draw_start;
	while (i < ray->draw_end)
	{
		texy = ((i - f->player.up_dw) * 2 - SH +\
				ray->line_h) * (wal.n.h / 2) / ray->line_h;
		if (i < SH && i >= 0)
		{
			f->mlx->img_data[i * SW + x] = data_tex[texy * wal.n.w + texx];
			if (f->evt.light == 1)
				f->mlx->img_data[i * SW + x] = get_color(f->mlx->img_data\
						[i * SW + x], ray->corrected_dist);
		}
		i++;
	}
}

void	draw_text(t_wolf *f, int x, t_ray *ray)
{
	int		texx;

	if (ray->side.n == 1 || ray->side.s == 1)
		ray->pos_rdt = f->player.pos.y + ray->corrected_dist * ray->direction.y;
	else
		ray->pos_rdt = f->player.pos.x + ray->corrected_dist * ray->direction.x;
	ray->pos_rdt -= (int)ray->pos_rdt;
	texx = (int)(ray->pos_rdt * 1000);
	if (((ray->side.n == 1 || ray->side.s == 1) && ray->direction.x > 0) ||
			((ray->side.e == 1 || ray->side.o == 1) && ray->direction.y < 0))
		texx = 1000 - texx - 1;
	draw_text2(f, x, ray, texx);
}
