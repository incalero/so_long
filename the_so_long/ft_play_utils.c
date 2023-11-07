/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:26 by incalero          #+#    #+#             */
/*   Updated: 2023/11/07 14:40:25 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_map(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (d->ar[i])
	{
		j = 0;
		while (d->ar[i][j] != '\0')
		{
			if (d->ar[i][j] != '1')
				mlx_put_image_to_window(d->mlx, d->mlx_win,
					d->ground, j * 64, i * 64);
			else
				mlx_put_image_to_window(d->mlx, d->mlx_win,
					d->wall, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print_items(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (d->ar[i])
	{
		j = 0;
		while (d->ar[i][j] != '\0')
		{
			if (d->ar[i][j] == 'E')
				mlx_put_image_to_window(d->mlx, d->mlx_win,
					d->exit, j * 64, i * 64);
			else if (d->ar[i][j] == 'C')
				mlx_put_image_to_window(d->mlx, d->mlx_win,
					d->item, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int	ft_items(t_data *d)
{
	ft_print_map(d);
	ft_print_items(d);
	ft_print_player(d);
	return (0);
}

void	ft_declare_image(t_data *d)
{
	int	res;

	res = 64;
	d->player = mlx_xpm_file_to_image(d->mlx, "imagenes/player6.xpm", \
	&d->res, &d->res);
	d->wall = mlx_xpm_file_to_image(d->mlx, "imagenes/wall5.xpm", \
	&res, &res);
	d->ground = mlx_xpm_file_to_image(d->mlx, "imagenes/ground4.xpm", \
	&res, &res);
	d->item = mlx_xpm_file_to_image(d->mlx, "imagenes/Chicken8.xpm", \
	&res, &res);
	d->exit = mlx_xpm_file_to_image(d->mlx, "imagenes/exit1.xpm", \
	&res, &res);
	if (d->wall == NULL || d->ground == NULL || d->item == NULL || \
	d->exit == NULL)
		write (1, "Error loading the images\n", 25);
}

int	key_hook(int keycode, t_data *d)
{
	int	y;
	int	x;

	y = d->pos_y;
	x = d->pos_x;
	if (keycode == 53 || keycode == 12)
		mlx_f_ar(d);
	if (keycode == 0 || keycode == 123)
	{
		d->player = mlx_xpm_file_to_image(d->mlx, "imagenes/p_left.xpm", \
		&d->res, &d->res);
		ft_move(d, x - 1, y);
	}
	else if (keycode == 2 || keycode == 124)
	{
		d->player = mlx_xpm_file_to_image(d->mlx, "imagenes/player6.xpm", \
		&d->res, &d->res);
		ft_move(d, x + 1, y);
	}	
	else if (keycode == 13 || keycode == 126)
		ft_move(d, x, y - 1);
	else if (keycode == 1 || keycode == 125)
		ft_move(d, x, y + 1);
	return (0);
}
