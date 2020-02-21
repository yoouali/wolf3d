/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 03:21:35 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/21 01:17:50 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

int		install_tex_data(char *path, t_tex *tex, t_mlx *mlx)
{
	int		a;
	int		b;
	int		c;

	tex->data_img = NULL;
	if (!(tex->img_ptr = mlx_png_file_to_image(mlx->mlx_ptr, path, &tex->w,\
		&tex->h)) || !(tex->data_img = (int *)mlx_get_data_addr(tex->img_ptr,\
			&a, &b, &c)))
		return (0);
	if (tex->w != 1000 || tex->h != 1000)
		return (0);
	return (1);
}

int		install_walls_data(t_boy *boy, t_mlx *mlx)
{
	if (!install_tex_data("ARCH/TEX/cavn.png", &boy->wals[0].n, mlx) ||\
		!install_tex_data("ARCH/TEX/cave.png", &boy->wals[0].e, mlx) ||\
		!install_tex_data("ARCH/TEX/cavs.png", &boy->wals[0].s, mlx) ||\
		!install_tex_data("ARCH/TEX/cavw.png", &boy->wals[0].w, mlx) ||\
		!install_tex_data("ARCH/TEX/cavc.png", &boy->wals[0].c, mlx) ||\
		!install_tex_data("ARCH/TEX/cavf.png", &boy->wals[0].f, mlx) ||\
		!install_tex_data("ARCH/TEX/facn.png", &boy->wals[1].n, mlx) ||\
		!install_tex_data("ARCH/TEX/face.png", &boy->wals[1].e, mlx) ||\
		!install_tex_data("ARCH/TEX/facs.png", &boy->wals[1].s, mlx) ||\
		!install_tex_data("ARCH/TEX/facw.png", &boy->wals[1].w, mlx) ||\
		!install_tex_data("ARCH/TEX/facc.png", &boy->wals[1].c, mlx) ||\
		!install_tex_data("ARCH/TEX/facf.png", &boy->wals[1].f, mlx) ||\
		!install_tex_data("ARCH/TEX/dayn.png", &boy->wals[2].n, mlx) ||\
		!install_tex_data("ARCH/TEX/daye.png", &boy->wals[2].e, mlx) ||\
		!install_tex_data("ARCH/TEX/days.png", &boy->wals[2].s, mlx) ||\
		!install_tex_data("ARCH/TEX/dayw.png", &boy->wals[2].w, mlx) ||\
		!install_tex_data("ARCH/TEX/dayf.png", &boy->wals[2].f, mlx) ||\
		!install_tex_data("ARCH/TEX/nign.png", &boy->wals[3].n, mlx) ||\
		!install_tex_data("ARCH/TEX/nige.png", &boy->wals[3].e, mlx) ||\
		!install_tex_data("ARCH/TEX/nigs.png", &boy->wals[3].s, mlx) ||\
		!install_tex_data("ARCH/TEX/nigw.png", &boy->wals[3].w, mlx) ||\
		!install_tex_data("ARCH/TEX/nigf.png", &boy->wals[3].f, mlx))
		return (0);
	return (1);
}

int		install_wop_data(t_boy *boy, t_mlx *mlx)
{
	if (!(boy->wop.wop[0][0] = get_png_ptr("ARCH/WOP/gun0.png",\
	mlx, WW, WH)) ||\
	!(boy->wop.wop[0][1] = get_png_ptr("ARCH/WOP/gun1.png", mlx, WW, WH)) ||\
	!(boy->wop.wop[0][2] = get_png_ptr("ARCH/WOP/gun2.png", mlx, WW, WH)) ||\
	!(boy->wop.wop[0][3] = get_png_ptr("ARCH/WOP/gun3.png", mlx, WW, WH)) ||\
	!(boy->wop.wop[0][4] = get_png_ptr("ARCH/WOP/gun4.png", mlx, WW, WH)) ||\
	!(boy->wop.wop[0][5] = get_png_ptr("ARCH/WOP/gun5.png", mlx, WW, WH)) ||\
	!(boy->wop.wop[0][6] = get_png_ptr("ARCH/WOP/gun6.png", mlx, WW, WH)) ||\
	!(boy->wop.wop[1][0] = get_png_ptr("ARCH/WOP/spr0.png", mlx, SW, SH)) ||\
	!(boy->wop.wop[1][1] = get_png_ptr("ARCH/WOP/spr1.png", mlx, SW, SH)) ||\
	!(boy->wop.wop[1][2] = get_png_ptr("ARCH/WOP/spr2.png", mlx, SW, SH)) ||\
	!(boy->wop.wop[1][3] = get_png_ptr("ARCH/WOP/spr3.png", mlx, SW, SH)) ||\
	!(boy->wop.wop[1][4] = get_png_ptr("ARCH/WOP/spr4.png", mlx, SW, SH)) ||\
	!(boy->wop.wop[1][5] = get_png_ptr("ARCH/WOP/spr5.png", mlx, SW, SH)) ||\
	!(boy->wop.wop[1][6] = get_png_ptr("ARCH/WOP/spr6.png", mlx, SW, SH)))
		return (0);
	return (1);
}
