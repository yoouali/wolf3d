/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:47:23 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/20 14:51:38 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

t_mmap	*install_mmap_data(t_wolf *wolf)
{
	t_mmap	*mmap;

	mmap = NULL;
	if (!(mmap = (t_mmap *)malloc(sizeof(t_mmap))))
		return (NULL);
	mmap->wolf = NULL;
	mmap->flor[0] = 0x464952;
	mmap->flor[1] = 0x5C575C;
	mmap->flor[2] = 0x324518;
	mmap->flor[3] = 0x878463;
	mmap->walc[0] = 0x605642;
	mmap->walc[1] = 0x4C5039;
	mmap->walc[2] = 0x375658;
	mmap->walc[3] = 0x476647;
	if (!(mmap->wolf = get_png_ptr("ARCH/GAME/wolf.png", wolf->mlx, 10, 10)))
	{
		free(mmap);
		return (NULL);
	}
	return (mmap);
}
