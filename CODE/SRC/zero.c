/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:08:46 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/17 00:13:52 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	zero_mlx_data(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	mlx->img_data = NULL;
}

void	zero_loading_data(t_load *load)
{
	int	i;

	i = -1;
	while (++i < 5)
		load->png_ptr[i] = NULL;
	load->gol_wav[0] = NULL;
	load->gol_wav[1] = NULL;
	load->load_mus = NULL;
	load->y = 800;
}

void	zero_wolf_data(t_wolf *wolf)
{
	if (SDL_Init(SDL_INIT_AUDIO) == -1)
		destroy_wolf_data(wolf, -1);
	if ((Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)) == -1)
	{
		SDL_Quit();
		destroy_wolf_data(wolf, -1);
	}
	wolf->load = NULL;
	wolf->mlx = NULL;
	wolf->map = NULL;
	wolf->boy = NULL;
	wolf->sta = NULL;
	wolf->gen = NULL;
	wolf->mmap = NULL;
	wolf->mus = NULL;
	if (!(wolf->load = (t_load *)malloc(sizeof(t_load))) ||\
		!(wolf->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		destroy_wolf_data(wolf, 1);
}
