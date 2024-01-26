/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:05:41 by incalero          #+#    #+#             */
/*   Updated: 2023/11/15 11:11:06 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_potition(t_data	*d)
{
	int	i;
	int	j;

	i = 0;
	while (d->ar[i] != NULL)
	{
		j = 0;
		while (d->ar[i][j] != '\0')
		{
			if (d->ar[i][j] == 'P')
			{
				d->pos_x = j;
				d->pos_y = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_item_count(t_data *d)
{
	int	i;
	int	j;

	d->count = 0;
	i = 0;
	while (d->ar[i])
	{
		j = 0;
		while (d->ar[i][j] != '\0')
		{
			if (d->ar[i][j] == 'C')
				d->count++;
			j++;
		}
		i++;
	}
	return (d->count);
}

void	ft_print_player(t_data *d)
{
	int	i;
	int	j;
	int	player_x;
	int	player_y;

	if (d->pos_x != -1 && d->pos_y != -1)
	{
		i = d->pos_y;
		j = d->pos_x;
		player_x = j * 64;
		player_y = i * 64;
		mlx_put_image_to_window(d->mlx, d->mlx_win, d->player, \
		player_x, player_y);
	}
}

int	ft_move(t_data *d, int x, int y)
{
	if (d->ar[y][x] != '1')
	{
		if (d->ar[y][x] == 'C')
		{
			d->ar[y][x] = '0';
			d->count -= 1;
		}
		else if (d->ar[y][x] == 'E' && d->count == 0)
			mlx_f_ar(d);
		d->movement = d->movement + 1;
		ft_printf("Number of movements = %i\n", d->movement);
		d->pos_x = x;
		d->pos_y = y;
	}
	return (0);
}

void	ft_play(t_data d, char **av)
{
	d.fin = 0;
	d.res = 64;
	d.count = 0;
	d.movement = 0;
	d.ar = av;
	ft_new_potition(&d);
	ft_item_count(&d);
	d.x = ft_strlen(av[0]);
	d.y = line_count(av);
	d.mlx = mlx_init();
	d.mlx_win = mlx_new_window(d.mlx, d.x * 64, d.y * 64, "so_long.c");
	d.img = mlx_new_image(d.mlx, d.x * 64, d.y * 64);
	ft_declare_image(&d);
	mlx_loop_hook(d.mlx, ft_items, &d);
	mlx_key_hook(d.mlx_win, key_hook, &d);
	mlx_hook(d.mlx_win, 17, 0, mlx_f_ar, &d);
	mlx_loop(d.mlx);
}
