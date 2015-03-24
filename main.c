/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 21:00:59 by gjensen           #+#    #+#             */
/*   Updated: 2015/03/24 17:46:42 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	*e;
	t_map	*map;

	if (argc > 1)
	{
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			fdf_malloc_error();
		map = fd_parse(argv, 0);
		if (map->len == 0)
			fdf_map_error();
		e->map = map;
		get_center(e);
		init_window("Fdf", WINDOW_SIZE_W, WINDOW_SIZE_H, e);
		mlx_key_hook(e->win, key_hook, e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_loop(e->mlx);
	}
	return(0);
}
