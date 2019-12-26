/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:49:03 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/12/25 09:07:39 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		worldMap[mapw][maph]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/*int		close(void *param)
{
	(void)param;
	printf("sdhlsakjdh\n");
	return (0);
}*/

int key_press(int key, t_wolf *f)
{
	if (key == 53)
		exit(0);
	if (key == UP)
	{
		printf("(%f, pos.x=%f , pos.y=%f , dir.x=%f, dir.y=%f)\n",f->pos.x + f->dir.x, f->pos.x, f->pos.y, f->dir.x, f->dir.y);
		if (worldMap[(int)(f->pos.x + f->dir.x)][(int)f->pos.y] == 0)
			f->pos.x += f->dir.x * 0.5;
		if (worldMap[(int)f->pos.x][(int)(f->pos.y + f->dir.y)] == 0)
			f->pos.y += f->dir.y * 0.5;
		ft_clear_data(&f->mlx.data);
		draw_the_FOV_p(f, worldMap);
		mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.win_ptr, f->mlx.img_ptr, 0, 0);
	}
	if (key == DOWN)
	{
		if (worldMap[(int)(f->pos.x - f->dir.x)][(int)f->pos.y] == 0)
			f->pos.x -= f->dir.x * 0.5;
		if (worldMap[(int)f->pos.x][(int)(f->pos.y - f->dir.y)] == 0)
			f->pos.y -= f->dir.y * 0.5;
		ft_clear_data(&f->mlx.data);
		draw_the_FOV_p(f, worldMap);
		mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.win_ptr, f->mlx.img_ptr, 0, 0);
	}
	if (key == 124)
	{
		f->dir = rotat(f->dir, f->pos, -10);
		f->plane = rotat(f->plane, f->pos, -10);
		ft_clear_data(&f->mlx.data);
		draw_the_FOV_p(f, worldMap);
		mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.win_ptr, f->mlx.img_ptr, 0, 0);
	}

	if (key == 123)
	{
		f->dir = rotat(f->dir, f->pos, 10);
		f->plane = rotat(f->plane, f->pos, 10);
		ft_clear_data(&f->mlx.data);
		draw_the_FOV_p(f, worldMap);
		mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.win_ptr, f->mlx.img_ptr, 0, 0);
	}
	if (key == 125)
	{
		ft_clear_data(&f->mlx.data);
		draw_the_FOV_p(f, worldMap);
		mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.win_ptr, f->mlx.img_ptr, 0, 0);
	}
	if (key == RIGHT)
	{
			printf("(%f, pos.x=%f , pos.y=%f , dir.x=%f, dir.y=%f)\n",f->pos.x + f->dir.x, f->pos.x, f->pos.y, f->dir.x, f->dir.y);
		if (worldMap[(int)(f->pos.x + f->dir.y)][(int)f->pos.y] == 0)
			f->pos.x += f->dir.y * 0.5;
		if (worldMap[(int)(f->pos.x)][(int)(f->pos.y - f->dir.x)] == 0)
			f->pos.y -= f->dir.x * 0.5;
		ft_clear_data(&f->mlx.data);
		draw_the_FOV_p(f, worldMap);
		mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.win_ptr, f->mlx.img_ptr, 0, 0);
	}
	if (key == LEFT)
	{
			printf("(%f, pos.x=%f , pos.y=%f , dir.x=%f, dir.y=%f)\n",f->pos.x + f->dir.x, f->pos.x, f->pos.y, f->dir.x, f->dir.y);
		if (worldMap[(int)(f->pos.x - f->dir.y)][(int)f->pos.y] == 0)
			f->pos.x -= f->dir.y * 0.5;
		if (worldMap[(int)(f->pos.x)][(int)(f->pos.y + f->dir.x)] == 0)
			f->pos.y += f->dir.x * 0.5;
		ft_clear_data(&f->mlx.data);
		draw_the_FOV_p(f, worldMap);
		mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.win_ptr, f->mlx.img_ptr, 0, 0);
	}
	//(18.475588, pos.x=18.475588 , pos.y=2.579425 , dir.x=-0.000000, dir.y=1.000000)
	if (f->musi == 1 && f->pos.x > 18 && f->pos.x < 19 && f->pos.y > 2 && f->pos.y < 3)
	{
		Mix_PlayMusic(f->mus, -1);
		f->musi = 0;
	}
	return (0);
	printf("dkfhdjkfh\n");
}

t_point		rotat(t_point p, t_point p2, double angle)
{
	t_point r;
	t_point old;
	double	v;


	v = angle * PI / 180;
	old.x = p.x;
	r.x = p.x * cos(v) - p.y * sin(v);
	r.y = old.x * sin(v) + p.y * cos(v);
/*	p.x -= p2.x;
	p.y -= p2.y;
	r.x = p.x * cos(v) - p.y * sin(v);
	r.y = p.x * sin(v) + p.y * cos(v);
	r.x += p2.x;
	r.y += p2.y;*/
	return (r);
}

int main()
{
	t_mlx	mlx;
	t_wolf	f;
	int		x;
	int		a, b;

	x = 0;
	f.mlx.mlx_ptr = mlx_init();
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	f.mus = Mix_LoadMUS("mus.mp3");
	//Mix_PlayMusic(f.mus, -1);
	f.musi = 1;
	f.mlx.win_ptr = mlx_new_window(f.mlx.mlx_ptr, w, h, "wolf...");
	f.mlx.img_ptr = mlx_new_image(f.mlx.mlx_ptr, w, h);
	f.mlx.data = (int*)mlx_get_data_addr(f.mlx.img_ptr, &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	f.mlx.png[0] = mlx_png_file_to_image(f.mlx.mlx_ptr, "wal1.png", &a, &b);
	f.mlx.png[1] = mlx_png_file_to_image(f.mlx.mlx_ptr, "wal2.png", &a, &b);
	f.mlx.png[2] = mlx_png_file_to_image(f.mlx.mlx_ptr, "wal3.png", &a, &b);
	f.mlx.png[3] = mlx_png_file_to_image(f.mlx.mlx_ptr, "wal4.png", &a, &b);
	f.mlx.png[4] = mlx_png_file_to_image(f.mlx.mlx_ptr, "wal5.png", &a, &b);
	f.mlx.png[5] = mlx_png_file_to_image(f.mlx.mlx_ptr, "wal6.png", &a, &b);
	f.mlx.png[6] = mlx_png_file_to_image(f.mlx.mlx_ptr, "wal7.png", &a, &b);
	f.mlx.png[7] = mlx_png_file_to_image(f.mlx.mlx_ptr, "wal8.png", &a, &b);
	f.mlx.data_png[0] = (int*)mlx_get_data_addr(f.mlx.png[0], &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	f.mlx.data_png[1] = (int*)mlx_get_data_addr(f.mlx.png[1], &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	f.mlx.data_png[2] = (int*)mlx_get_data_addr(f.mlx.png[2], &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	f.mlx.data_png[3] = (int*)mlx_get_data_addr(f.mlx.png[3], &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	f.mlx.data_png[4] = (int*)mlx_get_data_addr(f.mlx.png[4], &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	f.mlx.data_png[5] = (int*)mlx_get_data_addr(f.mlx.png[5], &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	f.mlx.data_png[6] = (int*)mlx_get_data_addr(f.mlx.png[6], &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	f.mlx.data_png[7] = (int*)mlx_get_data_addr(f.mlx.png[7], &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	//printf("(%d,%d)",a,b);
	f.pos.x = 4;
	f.pos.y = 4;
	f.dir.x = -1;
	f.dir.y = 0;
	f.plane.x = 0;
	f.plane.y = 0.60;
	f.tex_width = a;
	f.tex_height = b;
/*	x = 0;
	while (x < a)
	{
		int y = 0;
		while (y < b)
		{
			mlx_pixel_put(f.mlx.mlx_ptr, f.mlx.win_ptr, x, y, f.mlx.data[x * a + y]);
			y++;
		}
		x++;
	}*/
	draw_the_FOV_p(&f, worldMap);
	mlx_put_image_to_window(f.mlx.mlx_ptr, f.mlx.win_ptr, f.mlx.img_ptr, 0, 0);
	//printf("color :%d",f.mlx.png[1][3]);
	/*************************MINI_MAP*********************/
	/*f.map.img_map = mlx_new_image(f.mlx.mlx_ptr, 144, 144);
	f.map.data_map = (int*)mlx_get_data_addr(f.map.img_map, &f.mlx.bpp, &f.mlx.size_line, &f.mlx.endian);
	mlx_put_image_to_window(f.mlx.mlx_ptr, f.mlx.win_ptr, f.map.img_map, w - 144, h - 144);*/
	/******************************************************/
	mlx_hook(f.mlx.win_ptr, 2, 0, key_press, &f);
	mlx_loop(f.mlx.mlx_ptr);
	return (0);
}
