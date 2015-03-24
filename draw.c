/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 11:09:45 by gjensen           #+#    #+#             */
/*   Updated: 2015/03/24 17:16:51 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


//void	apply_z(t_point *p)
//{

void	draw_lines(t_env *e, t_point p1, t_point p2)
{
	double dx;
	double dy;
	double sx;
	double sy;
	double tab[2];
	double pointxy[2];

	p1.x -= p1.z;
	p1.y -= p1.z;
	p2.y -= p2.z;
	p2.x -= p2.z;
	dx = fabs(p2.x - p1.x);
	dy = fabs(p2.y - p1.y);
	sx = p1.x < p2.x ? 1 : -1;
	sy = p1.y < p2.y ? 1 : -1;
	tab[0] = (dx > dy ? dx : -dy) * 0.5;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		pointxy[0] = p1.x + ((WINDOW_SIZE_W - (e->center.x * 2)) / 2);
		pointxy[1] = p1.y + ((WINDOW_SIZE_H - (e->center.y * 2)) / 2);
		mlx_pixel_put(e->mlx, e->win, pointxy[0], pointxy[1], get_color(&p1, &p2));
		tab[1] = tab[0];
		if (tab[1] >- dx)
		{
			tab[0] -= dy;
			p1.x += sx;
		}
		if (tab[1] < dy)
		{
			tab[0] += dx;
			p1.y += sy;
		}
	}
}
