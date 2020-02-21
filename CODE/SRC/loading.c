/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:29:49 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/21 00:36:35 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void		loading_data(t_wolf *wolf)
{
	mlx_hook(wolf->mlx->win_ptr, 17, 0, close_wolf, wolf);
	Mix_PlayMusic(wolf->load->load_mus, -1);
	loading_bar(wolf->mlx, wolf->load, 750);
	if (!(wolf->map = install_map_data()))
		loading_gool(wolf, wolf->load, 1);
	loading_bar(wolf->mlx, wolf->load, 700);
	if (!(wolf->sta = install_sta_data(wolf)))
		loading_gool(wolf, wolf->load, 1);
	loading_bar(wolf->mlx, wolf->load, 650);
	if (!(wolf->gen = install_gen_data(wolf)))
		loading_gool(wolf, wolf->load, 1);
	loading_bar(wolf->mlx, wolf->load, 600);
	if (!(wolf->mmap = install_mmap_data(wolf)))
		loading_gool(wolf, wolf->load, 1);
	if (!(wolf->boy = install_boy_data(wolf)))
		loading_gool(wolf, wolf->load, 1);
	loading_bar(wolf->mlx, wolf->load, 400);
	if (!(wolf->mus = install_mus_data()))
		loading_gool(wolf, wolf->load, 1);
	loading_bar(wolf->mlx, wolf->load, 370);
	loading_gool(wolf, wolf->load, 0);
	wolf->load->y = 0;
	Mix_PlayMusic(wolf->sta->sound, -1);
}

void		loading_bar(t_mlx *mlx, t_load *load, int maxy)
{
	while (load->y > maxy)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		put_png_ptr(load->png_ptr[1], 0, load->y, mlx);
		put_png_ptr(load->png_ptr[0], 0, 0, mlx);
		mlx_do_sync(mlx->mlx_ptr);
		load->y -= 10;
	}
}

void		loading_gool(t_wolf *wolf, t_load *load, int gool)
{
	Mix_PauseMusic();
	mlx_clear_window(wolf->mlx->mlx_ptr, wolf->mlx->win_ptr);
	if (gool == 1)
	{
		Mix_PlayChannel(2, load->gol_wav[0], 1);
		put_png_ptr(load->png_ptr[2], 0, load->y, wolf->mlx);
		put_png_ptr(load->png_ptr[0], 0, 0, wolf->mlx);
		put_png_ptr(load->png_ptr[3], 0, 0, wolf->mlx);
		mlx_do_sync(wolf->mlx->mlx_ptr);
		SDL_Delay(1000);
		destroy_wolf_data(wolf, 1);
	}
	if (gool == 0)
	{
		Mix_PlayChannel(2, load->gol_wav[1], 0);
		put_png_ptr(load->png_ptr[1], 0, load->y, wolf->mlx);
		put_png_ptr(load->png_ptr[0], 0, 0, wolf->mlx);
		put_png_ptr(load->png_ptr[4], 0, 0, wolf->mlx);
		mlx_do_sync(wolf->mlx->mlx_ptr);
		SDL_Delay(1000);
	}
}
