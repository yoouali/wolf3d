/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 08:00:04 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/12/18 14:51:44 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_clear_data(int **tab)
{
	int i;

	i = 0;
	while (i < w * h)
	{
		(*tab)[i] = 0;
		i++;
	}
}

int mouse_move(int x, int y, t_wolf *f)
{
	printf("(x = %d, y = %d)\n",x, y);
	return (0);
}

