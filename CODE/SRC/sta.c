/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sta.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:46:34 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/21 00:34:20 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	zero_sta_data(t_sta *sta)
{
	sta->frm0 = NULL;
	sta->frm1 = NULL;
	sta->frm2 = NULL;
	sta->frm3 = NULL;
	sta->frm4 = NULL;
	sta->mous = NULL;
	sta->man = NULL;
	sta->click = NULL;
	sta->sound = NULL;
}

t_sta	*destroy_sta_data(t_sta *sta, t_mlx *mlx)
{
	free_png_ptr(sta->frm0, mlx);
	free_png_ptr(sta->frm1, mlx);
	free_png_ptr(sta->frm2, mlx);
	free_png_ptr(sta->frm3, mlx);
	free_png_ptr(sta->frm4, mlx);
	free_png_ptr(sta->mous, mlx);
	free_png_ptr(sta->man, mlx);
	Mix_FreeChunk(sta->click);
	Mix_FreeMusic(sta->sound);
	free(sta);
	return (NULL);
}

t_sta	*install_sta_data(t_wolf *wolf)
{
	t_sta	*sta;

	if (!(sta = (t_sta *)malloc(sizeof(t_sta))))
		return (NULL);
	zero_sta_data(sta);
	if (!(sta->frm0 = get_png_ptr("ARCH/STA/frm0.png", wolf->mlx, SW, SH)) ||\
		!(sta->frm1 = get_png_ptr("ARCH/STA/frm1.png", wolf->mlx, 210, 228)) ||\
		!(sta->frm2 = get_png_ptr("ARCH/STA/frm2.png", wolf->mlx, 210, 228)) ||\
		!(sta->frm3 = get_png_ptr("ARCH/STA/frm3.png", wolf->mlx, 500, 80)) ||\
		!(sta->frm4 = get_png_ptr("ARCH/STA/frm4.png", wolf->mlx, 500, 80)) ||\
		!(sta->mous = get_png_ptr("ARCH/STA/mous.png", wolf->mlx, 50, 50)) ||\
		!(sta->man = get_png_ptr("ARCH/STA/man.png", wolf->mlx, 360, 448)) ||\
		!(sta->click = Mix_LoadWAV("ARCH/STA/click.wav")) ||\
		!(sta->sound = Mix_LoadMUS("ARCH/STA/sound.mp3")))
		return (destroy_sta_data(sta, wolf->mlx));
	return (sta);
}
