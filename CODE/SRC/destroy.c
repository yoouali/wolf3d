/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:44:58 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 05:16:42 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void		wolf_exit(int opt)
{
	if (opt != 0)
		put_str("error has accord wolf3d has STOPED\n");
	if (opt == 0)
		put_str("i hope u enjoy the wolf3d\n");
	exit(opt);
}

void		destroy_loading_data(t_wolf *wolf, t_load *load)
{
	int	i;

	i = -1;
	while (++i < 5)
		free_png_ptr(load->png_ptr[i], wolf->mlx);
	Mix_FreeChunk(load->gol_wav[0]);
	Mix_FreeChunk(load->gol_wav[1]);
	Mix_FreeMusic(load->load_mus);
}

void		destroy_mlx_data(t_mlx *mlx)
{
	free_png_ptr(mlx->img_ptr, mlx);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
}

void		destroy_data(t_wolf *wolf)
{
	if (wolf->load)
		destroy_loading_data(wolf, wolf->load);
	if (wolf->map)
		free_map(wolf->map);
	if (wolf->boy)
		destroy_boy(wolf->boy, wolf);
	if (wolf->sta)
		destroy_sta_data(wolf->sta, wolf->mlx);
	if (wolf->gen)
		destroy_gen_data(wolf->gen, wolf->mlx);
	if (wolf->mmap)
	{
		free_png_ptr(wolf->mmap->wolf, wolf->mlx);
		free(wolf->mmap);
	}
	if (wolf->mus)
		destroy_mus_data(wolf->mus);
	if (wolf->mlx)
		destroy_mlx_data(wolf->mlx);
}

void		destroy_wolf_data(t_wolf *wolf, int opt)
{
	destroy_data(wolf);
	free(wolf->mlx);
	free(wolf->load);
	if (opt != -1)
	{
		Mix_CloseAudio();
		SDL_Quit();
	}
	free(wolf);
	wolf_exit(opt);
}
