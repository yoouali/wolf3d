/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 05:36:27 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/12/24 03:02:03 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point		ft_new_point(double x, double y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point		ft_intersection(t_point pos, t_point dir, t_point p1, t_point p2)
{
	t_point res;
	double	t;
	double	u;
	double	m;

	res = ft_new_point(-1, -1);
	m = (p1.x - p2.x) * (pos.y - dir.y) - (p1.y - p2.y) * (pos.x - dir.x);
	if (!m)
		return (res);
	t = ((p1.x - pos.x) * (pos.y - dir.y) - (p1.y - pos.y) * (pos.x - dir.x)) / m;
	u = -1 * ((p1.x - p2.x) * (p1.y - pos.y) - (p1.y - p2.y) * (p1.x - pos.x)) / m;
	if (t >= 0.0 && t <= 1.0 && u > 0)
	{
		res.x = p1.x + t * (p2.x - p1.x);
		res.y = p1.y + t * (p2.y - p1.y);
		return (res);
	}
	return (res);
}
