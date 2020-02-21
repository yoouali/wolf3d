/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:36:31 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/20 14:47:13 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void		zero_gen_data(t_gen *gen)
{
	gen->frm0 = NULL;
	gen->frm1 = NULL;
	gen->wal[0] = NULL;
	gen->wal[1] = NULL;
	gen->wal[2] = NULL;
	gen->wal[3] = NULL;
	gen->wal[4] = NULL;
	gen->waln = 0;
}

t_gen		*destroy_gen_data(t_gen *gen, t_mlx *mlx)
{
	free_png_ptr(gen->frm0, mlx);
	free_png_ptr(gen->frm1, mlx);
	free_png_ptr(gen->wal[0], mlx);
	free_png_ptr(gen->wal[1], mlx);
	free_png_ptr(gen->wal[2], mlx);
	free_png_ptr(gen->wal[3], mlx);
	free_png_ptr(gen->wal[4], mlx);
	free(gen);
	return (NULL);
}

t_gen		*install_gen_data(t_wolf *wolf)
{
	t_gen	*gen;

	gen = NULL;
	if (!(gen = (t_gen *)malloc(sizeof(t_gen))))
		return (NULL);
	zero_gen_data(gen);
	if (!(gen->frm0 = get_png_ptr("ARCH/GEN/frm0.png", wolf->mlx, SW, SH)) ||\
		!(gen->frm1 = get_png_ptr("ARCH/GEN/frm1.png", wolf->mlx, 144, 140)) ||\
		!(gen->wal[0] = get_png_ptr("ARCH/GEN/wal0.png", wolf->mlx, 30, 30)) ||\
		!(gen->wal[1] = get_png_ptr("ARCH/GEN/wal1.png", wolf->mlx, 30, 30)) ||\
		!(gen->wal[2] = get_png_ptr("ARCH/GEN/wal2.png", wolf->mlx, 30, 30)) ||\
		!(gen->wal[3] = get_png_ptr("ARCH/GEN/wal3.png", wolf->mlx, 30, 30)) ||\
		!(gen->wal[4] = get_png_ptr("ARCH/GEN/wal4.png", wolf->mlx, 30, 30)))
		return (destroy_gen_data(gen, wolf->mlx));
	return (gen);
}
