/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:56:56 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/19 06:43:50 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	draw_box(t_wolf *wolf, t_box *box, t_evt *evt)
{
	void	*img_ptr;

	if (wolf->map->boyn[wolf->map->mapn] == 2)
		img_ptr = box->day;
	else
		img_ptr = box->night;
	mlx_put_image_to_window(wolf->mlx->mlx_ptr,\
			wolf->mlx->win_ptr, img_ptr, evt->x, 0);
}

int		close_wolf(t_wolf *wolf)
{
	destroy_wolf_data(wolf, 0);
	return (0);
}
