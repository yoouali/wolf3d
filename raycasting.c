/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:34:31 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/12/25 09:05:12 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_the_FOV_p(t_wolf *f, int worldMap[24][24])
{
	int		x;
	t_rayc	r;
	t_point p1;
	t_point p2;

	x = 0;
	while (x < w)
	{
		r.camera = 2 * x /(double)w - 1;
		r.rayDir.x = f->dir.x + f->plane.x * r.camera;
		r.rayDir.y = f->dir.y + f->plane.y * r.camera;
		r.mapX = (int)f->pos.x;
		r.mapY = (int)f->pos.y;
		r.deltaDist.x = fabs(1 / r.rayDir.x);
		r.deltaDist.y = fabs(1 / r.rayDir.y);
		r.hit = 0;
		if (r.rayDir.x < 0)
		{
			r.stepX = -1;
			r.sideDist.x = (f->pos.x - r.mapX) * r.deltaDist.x;
		}
		else
		{
			r.stepX = 1;
			r.sideDist.x = (r.mapX + 1.0 - f->pos.x) * r.deltaDist.x;
		}
		if (r.rayDir.y < 0)
		{
			r.stepY = -1;
			r.sideDist.y = (f->pos.y - r.mapY) * r.deltaDist.y;
		}
		else
		{
			r.stepY = 1;
			r.sideDist.y = (r.mapY + 1.0 - f->pos.y) * r.deltaDist.y;
		}
		while (r.hit == 0)
		{
			if (r.sideDist.x < r.sideDist.y)
			{
				r.sideDist.x += r.deltaDist.x;
				r.mapX += r.stepX;
				r.side = 0;
			}
			else
			{
				r.sideDist.y += r.deltaDist.y;
				r.mapY += r.stepY;
				r.side = 1;
			}
			if (worldMap[r.mapX][r.mapY] > 0)
				r.hit = 1;
		}
		if (r.side == 0)
			r.perpWallDist = (r.mapX - f->pos.x + (1 - r.stepX) / 2) / r.rayDir.x;
		else
			r.perpWallDist = (r.mapY - f->pos.y + (1 - r.stepY) / 2) / r.rayDir.y;
		r.lineHeight = (int)(h / r.perpWallDist);
		r.draw_start = -r.lineHeight / 2 + h / 2;
		if(r.draw_start < 0)
			r.draw_start = 0;
		r.draw_end = r.lineHeight / 2 + h / 2;
		if(r.draw_end >= h)
			r.draw_end = h - 1;
		r.color = 0;
		int k = 0;
		if (worldMap[r.mapX][r.mapY] == 1)
		{
			/*****************************TEX_********************************/
			if (r.side == 0)
				r.wallX = f->pos.y + r.perpWallDist * r.rayDir.y;
			else
				r.wallX = f->pos.x + r.perpWallDist * r.rayDir.x;
			r.wallX -= (int)r.wallX;
			int texX = (int)(r.wallX * f->tex_width);
			if ((r.side == 0 && r.rayDir.x > 0) || (r.side == 1 && r.rayDir.y < 0))
				texX = f->tex_width - texX - 1;
			int y = r.draw_start;
			while (y < r.draw_end)
			{
				k = 1;
				int texY;
				texY = (y * 2 - h + r.lineHeight) * (f->tex_height / 2) / r.lineHeight;
				r.color = f->mlx.data_png[0][texY * f->tex_width + texX];
				if (r.side == 1)
					r.color = (r.color >> 1) & 8355711;
				f->mlx.data[y * w + x] = r.color;
				y++;
			}
		}
		else if (worldMap[r.mapX][r.mapY] == 2)
		{
			/*****************************TEX_********************************/
			//r.color = 0x00ff00;
			if (r.side == 0)
				r.wallX = f->pos.y + r.perpWallDist * r.rayDir.y;
			else
				r.wallX = f->pos.x + r.perpWallDist * r.rayDir.x;
			r.wallX -= (int)r.wallX;
			int texX = (int)(r.wallX * f->tex_width);
			if ((r.side == 0 && r.rayDir.x > 0) || (r.side == 1 && r.rayDir.y < 0))
				texX = f->tex_width - texX - 1;
			int y = r.draw_start;
			while (y < r.draw_end)
			{
				k = 1;
				int texY;
				texY = (y * 2 - h + r.lineHeight) * (f->tex_height / 2) / r.lineHeight;
				if (r.side == 0 && r.rayDir.x < 0)
					r.color = 0x0fff0;
				if (r.side == 0 && r.rayDir.x > 0)
					r.color = 0xff0000;
				if (r.side == 1 && r.rayDir.y > 0)
					r.color = 0x00ff00;
				if (r.side == 1 && r.rayDir.y < 0)
					r.color = 0x0000ff;
				f->mlx.data[y * w + x] = r.color;
				y++;
			}
			/*while (y < r.draw_end)
			  {
			  k = 1;
			  int texY = (f->tex_height / r.lineHeight);
			  r.color = f->mlx.png[1][texY * f->tex_height + texX];
			  f->mlx.data[y * w + x] = r.color;
			  y++;
			  }*/
		}	
		else if (worldMap[r.mapX][r.mapY] == 3)
		{
			if (r.side == 0)
				r.wallX = f->pos.y + r.perpWallDist * r.rayDir.y;
			else
				r.wallX = f->pos.x + r.perpWallDist * r.rayDir.x;
			r.wallX -= (int)r.wallX;
			int texX = (int)(r.wallX * f->tex_width);
			if ((r.side == 0 && r.rayDir.x > 0) || (r.side == 1 && r.rayDir.y < 0))
				texX = f->tex_width - texX - 1;
			int y = r.draw_start;
			while (y < r.draw_end)
			{
				k = 1;
				int texY;
				texY = (y * 2 - h + r.lineHeight) * (f->tex_height / 2) / r.lineHeight;
				r.color = f->mlx.data_png[2][texY * f->tex_width + texX];
				if (r.side == 1)
					r.color = r.color;
				f->mlx.data[y * w + x] = r.color;
				y++;
			}

		}
		else if (worldMap[r.mapX][r.mapY] == 4)
		{
			if (r.side == 0)
				r.wallX = f->pos.y + r.perpWallDist * r.rayDir.y;
			else
				r.wallX = f->pos.x + r.perpWallDist * r.rayDir.x;
			r.wallX -= (int)r.wallX;
			int texX = (int)(r.wallX * f->tex_width);
			if ((r.side == 0 && r.rayDir.x > 0) || (r.side == 1 && r.rayDir.y < 0))
				texX = f->tex_width - texX - 1;
			int y = r.draw_start;
			while (y < r.draw_end)
			{
				k = 1;
				int texY;
				texY = (y * 2 - h + r.lineHeight) * (f->tex_height / 2) / r.lineHeight;
				r.color = f->mlx.data_png[3][texY * f->tex_width + texX];
				if (r.side == 0)
					r.color = r.color;
				f->mlx.data[y * w + x] = r.color;
				y++;
			}

		}
		else
		{
			if (r.side == 0)
				r.wallX = f->pos.y + r.perpWallDist * r.rayDir.y;
			else
				r.wallX = f->pos.x + r.perpWallDist * r.rayDir.x;
			r.wallX -= (int)r.wallX;
			int texX = (int)(r.wallX * f->tex_width);
			if ((r.side == 0 && r.rayDir.x > 0) || (r.side == 1 && r.rayDir.y < 0))
				texX = f->tex_width - texX - 1;
			int y = r.draw_start;
			while (y < r.draw_end)
			{
				k = 1;
				int texY;
				texY = (y * 2 - h + r.lineHeight) * (f->tex_height / 2) / r.lineHeight;
				r.color = f->mlx.data_png[4][texY * f->tex_width + texX];
				if (r.side == 1 && r.rayDir.y > 0)
				r.color = f->mlx.data_png[5][texY * f->tex_width + texX];
				f->mlx.data[y * w + x] = r.color;
				y++;
			}

		}
		/*		if (r.draw_start > 0)
				{
				p1 = ft_new_point(x,0);
				p2 = ft_new_point(x, r.draw_start);
				dda(p1,p2, &f->mlx, 0x00bfff);
				}
				if (r.draw_end < h)
				{
				p1 = ft_new_point(x,r.draw_end);
				p2 = ft_new_point(x, h);
				dda(p1,p2, &f->mlx, 0xff9500);
				}*/
		/***************************FLOOR******************************/
		t_point		floorWall;
		if (r.side == 0 && r.rayDir.x > 0)
		{
			floorWall.x = r.mapX;
			floorWall.y = r.mapY + r.wallX;
		}
		else if (r.side == 0 && r.rayDir.x < 0)
		{
			floorWall.x = r.mapX + 1.0;
			floorWall.y = r.mapY + r.wallX;
		}
		else if(r.side == 1 && r.rayDir.y > 0)
		{
			floorWall.x = r.mapX + r.wallX;
			floorWall.y = r.mapY;
		}
		else
		{
			floorWall.x = r.mapX + r.wallX;
			floorWall.y = r.mapY + 1.0;
		}
		double	distWall;
		double	distPlayer;
		double	currentDist;
		distWall = r.perpWallDist;
		distPlayer = 0.0;
		if (r.draw_end < 0)
			r.draw_end = h;
		int y = r.draw_end + 1;
		while (y < h)
		{
			currentDist = h / (2.0 * y - h);
			double weight = (currentDist - distPlayer) / (distWall - distPlayer);
			t_point	currentFloor;
			currentFloor.x = weight * floorWall.x + (1.0 - weight) * f->pos.x;
			currentFloor.y = weight * floorWall.y + (1.0 - weight) * f->pos.y;
			int floorTexX, floorTexY;
			floorTexX = (int)(currentFloor.x * f->tex_width) % f->tex_width;
			floorTexY = (int)(currentFloor.y * f->tex_height) % f->tex_height;
			f->mlx.data[y * w + x] = f->mlx.data_png[7][floorTexY * f->tex_width + floorTexX];
			f->mlx.data[(h - y) * w + x] = f->mlx.data_png[6][floorTexY * f->tex_width + floorTexX];
			y++;
		}
		x++;
	}
}
