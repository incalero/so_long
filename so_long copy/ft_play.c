/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:05:41 by incalero          #+#    #+#             */
/*   Updated: 2023/10/17 15:24:09 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_player_potition(t_data *d)
{
    t_point p;
    int i;
    int j;
	int player_x;
	int	player_y;

    
    p = ft_p_potition(d->ar);
    if (p.x != -1 && p.y != -1)
    {
        i = p.y; 
        j = p.x; 
        player_x = j * 64;
        player_y = i * 64;
        mlx_put_image_to_window(d->mlx, d->mlx_win, d->player, player_x, player_y);
    }
    else
		write(1, "player no found\n", 16);
}

int16_t	ft_print_map(t_data *d)
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
{/* 
	int		i;
	int		j;

	i = ft_st_temp('x', 0);
	j = ft_st_temp('y', 0);
	if (!ft_st_temp('k', 0) && d->ar[i][j] == 'E')
		ft_free(d);
	else  */
	ft_print_map(d);
	ft_print_items(d);
	ft_player_potition(d);
	return (0);
}

void	ft_declare_image(t_data *d)
{
	int	res;
	
	res = 64;
	d->player = mlx_xpm_file_to_image(d->mlx, "imagenes/player.xpm", &d->res, &d->res);
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
	printf("count = %d\n", count);
	return(count);
}

void	ft_play(char **av)
{
	t_data	d;
	t_point x;

	d.fin = 0;
	d.res = 64;
	d.count = 0;
	d.ar = av;
	x.x = ft_strlen(av[0]);
	x.y = line_count(av);
	d.mlx = mlx_init();
	d.mlx_win = mlx_new_window(d.mlx, x.x * 64, x.y * 64, "so_long.c");
	d.img = mlx_new_image(d.mlx, x.x * 64, x.y * 64);
	ft_declare_image(&d);
	printf("pruba");
	mlx_loop_hook(d.mlx, ft_items, &d);
	//mlx_key_hook(d.mlx_win, key_hook, &d);
	//mlx_hook(d.mlx_win, 17, 0, ft_free, &d);
	mlx_loop(d.mlx);
}
