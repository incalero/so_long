/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:05:41 by incalero          #+#    #+#             */
/*   Updated: 2023/10/16 14:49:13 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_items_print(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (d->ar[i])
	{
		j = 0;
		while (d->ar[i][j] != '\0')
		{
			if (d->ar[i][j] == 'C')
				mlx_put_image_to_window(d->mlx, d->mlx_win, d->birra, j * 64, i * 64);
			if (d->ar[i][j] == 'E' && !d->fin)
				mlx_put_image_to_window(d->mlx, d->mlx_win, d->cobete, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_image(t_data *d)
{
	int	res;
	

	res = 64;
	
	//d->risitas = mlx_xpm_file_to_image(d->mlx, "i/risitas.xpm", &d->res, &d->res);
	d->pared = mlx_xpm_file_to_image(d->mlx, "imagenes/pared.xpm", &res, &res);
	d->suelo = mlx_xpm_file_to_image(d->mlx, "imagenes/hierba2.xpm", &res, &res);
	//d->birra = mlx_xpm_file_to_image(d->mlx, "i/birra.xpm", &res, &res);
	d->cobete = mlx_xpm_file_to_image(d->mlx, "imagenes/cobete_off.xpm", &res, &res);
	
	// Verifica si las imágenes se han cargado correctamente
    if (d->pared == NULL || d->suelo == NULL || d->birra == NULL || d->cobete == NULL)
    {
        // Maneja el error o imprime un mensaje de error
        printf("Error al cargar las imágenes\n");
        // Puedes agregar más lógica de manejo de errores aquí
    }
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
	printf("x.y = %d\n", x.y);
	d.mlx = mlx_init();
	d.mlx_win = mlx_new_window(d.mlx, x.x * 64, x.y * 64, "so_long.c");
	d.img = mlx_new_image(d.mlx, x.x * 64, x.y * 64);
	ft_image(&d);
	printf("pruba");
	mlx_put_image_to_window(d.mlx, d.mlx_win, d.img, x.x, x.y);
	//mlx_loop_hook(d.mlx, ft_items , &d);
	//mlx_key_hook(d.mlx_win, key_hook, &d);
	//mlx_hook(d.mlx_win, 17, 0, ft_free, &d);
	mlx_loop(d.mlx);
}
