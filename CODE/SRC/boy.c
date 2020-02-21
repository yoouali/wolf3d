/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boy.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 03:04:36 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/21 01:18:27 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void		zero_boy_data(t_boy *boy)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		boy->wals[i].n.img_ptr = NULL;
		boy->wals[i].e.img_ptr = NULL;
		boy->wals[i].s.img_ptr = NULL;
		boy->wals[i].w.img_ptr = NULL;
		boy->wals[i].c.img_ptr = NULL;
		boy->wals[i].f.img_ptr = NULL;
	}
	i = -1;
	while (++i < 7)
		boy->wop.wop[0][i] = NULL;
	i = -1;
	while (++i < 7)
		boy->wop.wop[1][i] = NULL;
	boy->box.day = NULL;
	boy->box.night = NULL;
	boy->box.x = 0;
	boy->box.y = 0;
	boy->wop.frm = 0;
}

t_boy		*destroy_boy(t_boy *boy, t_wolf *wolf)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		free_png_ptr(boy->wals[i].n.img_ptr, wolf->mlx);
		free_png_ptr(boy->wals[i].e.img_ptr, wolf->mlx);
		free_png_ptr(boy->wals[i].s.img_ptr, wolf->mlx);
		free_png_ptr(boy->wals[i].w.img_ptr, wolf->mlx);
		free_png_ptr(boy->wals[i].c.img_ptr, wolf->mlx);
		free_png_ptr(boy->wals[i].f.img_ptr, wolf->mlx);
	}
	i = -1;
	while (++i < 7)
		free_png_ptr(boy->wop.wop[0][i], wolf->mlx);
	i = -1;
	while (++i < 7)
		free_png_ptr(boy->wop.wop[1][i], wolf->mlx);
	free_png_ptr(boy->box.day, wolf->mlx);
	free_png_ptr(boy->box.night, wolf->mlx);
	return (NULL);
}

t_boy		*install_boy_data(t_wolf *wolf)
{
	t_boy	*boy;

	boy = NULL;
	if (!(boy = (t_boy *)malloc(sizeof(t_boy))))
		return (NULL);
	zero_boy_data(boy);
	loading_bar(wolf->mlx, wolf->load, 580);
	if (!(install_walls_data(boy, wolf->mlx)))
		return (destroy_boy(boy, wolf));
	loading_bar(wolf->mlx, wolf->load, 570);
	if (!(install_wop_data(boy, wolf->mlx)) ||\
		!(boy->box.day = get_png_ptr("ARCH/BOX/day.png", wolf->mlx, BW, BH)) ||\
	!(boy->box.night = get_png_ptr("ARCH/BOX/night.png", wolf->mlx, BW, BH)))
		return (destroy_boy(boy, wolf));
	loading_bar(wolf->mlx, wolf->load, 550);
	return (boy);
}
