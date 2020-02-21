/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:08:36 by yoouali           #+#    #+#             */
/*   Updated: 2020/02/20 14:59:09 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf.h"

void	*get_png_ptr(char *path, t_mlx *mlx, int w, int h)
{
	int		a;
	int		b;
	void	*png;

	if (!(png = mlx_png_file_to_image(mlx->mlx_ptr, path, &a, &b)))
		return (NULL);
	if (a != w || b != h)
	{
		mlx_destroy_image(mlx->mlx_ptr, png);
		return (NULL);
	}
	return (png);
}

void	free_png_ptr(void *png_ptr, t_mlx *mlx)
{
	if (png_ptr)
		mlx_destroy_image(mlx->mlx_ptr, png_ptr);
}

void	put_png_ptr(void *png_ptr, int x, int y, t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, png_ptr, x, y);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
