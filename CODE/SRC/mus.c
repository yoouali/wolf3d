/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mus.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:53:32 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 06:57:49 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

t_mus	*destroy_mus_data(t_mus *mus)
{
	if (mus->cave)
		Mix_FreeMusic(mus->cave);
	if (mus->factor)
		Mix_FreeMusic(mus->factor);
	if (mus->day)
		Mix_FreeMusic(mus->day);
	if (mus->night)
		Mix_FreeMusic(mus->night);
	if (mus->move)
		Mix_FreeChunk(mus->move);
	if (mus->gun)
		Mix_FreeChunk(mus->gun);
	if (mus->spear)
		Mix_FreeChunk(mus->spear);
	free(mus);
	return (NULL);
}

t_mus	*install_mus_data(void)
{
	t_mus	*mus;

	mus = NULL;
	if (!(mus = (t_mus *)malloc(sizeof(t_mus))))
		return (NULL);
	mus->cave = NULL;
	mus->factor = NULL;
	mus->day = NULL;
	mus->night = NULL;
	mus->move = NULL;
	mus->gun = NULL;
	mus->spear = NULL;
	if (!(mus->cave = Mix_LoadMUS("ARCH/MUS/cave.mp3")) ||\
			!(mus->factor = Mix_LoadMUS("ARCH/MUS/factor.mp3")) ||\
			!(mus->day = Mix_LoadMUS("ARCH/MUS/day.mp3")) ||\
			!(mus->night = Mix_LoadMUS("ARCH/MUS/night.mp3")) ||\
			!(mus->move = Mix_LoadWAV("ARCH/MUS/move.wav")) ||\
			!(mus->gun = Mix_LoadWAV("ARCH/MUS/gun.wav")) ||\
			!(mus->spear = Mix_LoadWAV("ARCH/MUS/spear.wav")))
		return (destroy_mus_data(mus));
	return (mus);
}

void	detect_music(t_wolf *wolf)
{
	if (wolf->evt.music == 1)
	{
		Mix_PauseMusic();
		if (wolf->map->boyn[wolf->map->mapn] == 0)
			Mix_PlayMusic(wolf->mus->cave, -1);
		if (wolf->map->boyn[wolf->map->mapn] == 1)
			Mix_PlayMusic(wolf->mus->factor, -1);
		if (wolf->map->boyn[wolf->map->mapn] == 2)
			Mix_PlayMusic(wolf->mus->day, -1);
		if (wolf->map->boyn[wolf->map->mapn] == 3)
			Mix_PlayMusic(wolf->mus->night, -1);
	}
}
