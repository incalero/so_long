/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:05:41 by incalero          #+#    #+#             */
/*   Updated: 2023/10/23 19:21:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_ar(t_data *d)
{
	mlx_destroy_window(d->mlx, d->mlx_win);
	ft_del(d->ar, ft_strlen(d->ar[0]));
	exit(0);
	return (0);
}

void	ft_new_potition(t_data	*d)
{
	int i;
    int j;
	
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

int ft_item_count(t_data *d)
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
	printf("count = %d\n", d->count);
	return(d->count);
}

void ft_print_player(t_data *d)
{
    int i;
    int j;
	int player_x;
	int	player_y;

    if (d->pos_x != -1 && d->pos_y != -1)
    {
        i = d->pos_y; 
        j = d->pos_x; 
        player_x = j * 64;
        player_y = i * 64;
        mlx_put_image_to_window(d->mlx, d->mlx_win, d->player, player_x, player_y);
    }
}

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
	d->player = mlx_xpm_file_to_image(d->mlx, "imagenes/player6.xpm", &d->res, &d->res);
	d->wall = mlx_xpm_file_to_image(d->mlx, "imagenes/wall5.xpm", &res, &res);
	d->ground = mlx_xpm_file_to_image(d->mlx, "imagenes/ground4.xpm", &res, &res);
	d->item = mlx_xpm_file_to_image(d->mlx, "imagenes/item1.xpm", &res, &res);
	d->exit = mlx_xpm_file_to_image(d->mlx, "imagenes/exit1.xpm", &res, &res);
    if (d->wall == NULL || d->ground == NULL || d->item == NULL || d->exit == NULL)
    	write (1, "Error loading the images\n", 25);
}

int line_count(char **av)
{
	int	count;
	
	count = 0;
	while(av[count] != NULL)
		count++;
	return(count);
}

int ft_move(t_data *d, int x, int y)
{
    if (d->ar[y][x] != '1') 
	{
		if (d->ar[y][x] == 'C')
		{
			d->ar[y][x] = '0';
			d->count -= 1;
			printf("count = %d\n", d->count);	
		}
		else if (d->ar[y][x] == 'E' && d->count == 0)
			ft_free_ar(d);
		d->movement = d->movement + 1;
		printf("Number of movements = %i\n", d->movement);
		d->pos_x = x;
		d->pos_y = y;
	}    
	return (0);
}
int	key_hook(int keycode, t_data *d)
{
    int y;
    int x;

	y = d->pos_y; 
    x = d->pos_x;
	if (keycode == 53 || keycode == 12)
		ft_free_ar(d);
	if (keycode == 0 || keycode == 123)
	{
		d->player = mlx_xpm_file_to_image(d->mlx, "imagenes/p_left.xpm", &d->res, &d->res);
		ft_move(d, x - 1, y);
	}
	else if (keycode == 2 || keycode == 124)
	{
		d->player = mlx_xpm_file_to_image(d->mlx, "imagenes/player6.xpm", &d->res, &d->res);
		ft_move(d, x + 1, y);
	}	
	else if (keycode == 13 || keycode == 126)
		ft_move(d, x, y - 1);
	else if (keycode == 1 || keycode == 125)
		ft_move(d, x, y + 1);
	return (0);
}  

void	ft_play(char **av)
{
	
	t_data	d;
	t_point x;

	d.fin = 0;
	d.res = 64;
	d.count = 0;
	d.movement = 0;
	d.ar = av;
	ft_new_potition(&d);
	ft_item_count(&d);
	x.x = ft_strlen(av[0]);
	x.y = line_count(av);
	d.mlx = mlx_init();
	d.mlx_win = mlx_new_window(d.mlx, x.x * 64, x.y * 64, "so_long.c");
	d.img = mlx_new_image(d.mlx, x.x * 64, x.y * 64);
	ft_declare_image(&d);
	mlx_loop_hook(d.mlx, ft_items, &d);
	mlx_key_hook(d.mlx_win, key_hook, &d);
	mlx_hook(d.mlx_win, 17, 0, ft_free_ar, &d);
	mlx_loop(d.mlx);

}
