/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   install.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:07:12 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/21 01:19:59 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	install_mlx_data(t_wolf *wolf, t_mlx *mlx)
{
	int	a;
	int	b;
	int	c;

	zero_mlx_data(mlx);
	if (!(mlx->mlx_ptr = mlx_init()) ||\
		!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SW, SH, "WOLF_3D")) ||\
		!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, SW, SH)) ||\
		!(mlx->img_data = (int *)mlx_get_data_addr(mlx->img_ptr, &a, &b, &c)))
		destroy_wolf_data(wolf, 1);
}

void	install_loading_data(t_wolf *wolf, t_load *load)
{
	zero_loading_data(load);
	if (!(load->png_ptr[0] = get_png_ptr("ARCH/LOAD/bak0.png",\
	wolf->mlx, SW, SH)) ||\
	!(load->png_ptr[1] = get_png_ptr("ARCH/LOAD/bak1.png", wolf->mlx, W, H)) ||\
	!(load->png_ptr[2] = get_png_ptr("ARCH/LOAD/bak2.png", wolf->mlx, W, H)) ||\
	!(load->png_ptr[3] = get_png_ptr("ARCH/LOAD/stop.png", wolf->mlx, W, H)) ||\
	!(load->png_ptr[4] = get_png_ptr("ARCH/LOAD/succ.png", wolf->mlx, W, H)) ||\
	!(load->gol_wav[0] = Mix_LoadWAV("ARCH/LOAD/stop.wav")) ||\
	!(load->gol_wav[1] = Mix_LoadWAV("ARCH/LOAD/succ.wav")) ||\
	!(load->load_mus = Mix_LoadMUS("ARCH/LOAD/load.mp3")))
		destroy_wolf_data(wolf, 1);
}

t_wolf	*loading_wolf_data(void)
{
	t_wolf *wolf;

	wolf = NULL;
	if (!(wolf = (t_wolf *)malloc(sizeof(t_wolf))))
		destroy_wolf_data(wolf, -1);
	zero_wolf_data(wolf);
	install_mlx_data(wolf, wolf->mlx);
	install_loading_data(wolf, wolf->load);
	zero_player(&wolf->player);
	zero_event(&wolf->evt);
	loading_data(wolf);
	Mix_PlayMusic(wolf->sta->sound, -1);
	return (wolf);
}
