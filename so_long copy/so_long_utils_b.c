/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:10 by incalero          #+#    #+#             */
/*   Updated: 2023/10/16 13:19:31 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	ft_p_potition(char **av)
{
	t_point position;
	int 	i;
	
	position.x = -1; // Valor predeterminado si no se encuentra 'P'
    position.y = -1;
	i = 0;
    while (av[i] != NULL)
    {
        int j = 0;
        while (av[i][j] != '\0')
        {
            if (av[i][j] == 'P')
            {
                position.x = j;
                position.y = i;
                return position;
            }
            j++;
        }
        i++;
    }
    return position; // Devuelve (-1, -1) si no se encontró 'P'
}


void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != 'P' && tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'E'))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}


char	**flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
    return(tab);
}

char **no_way_error(char **av, t_point size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < size.y)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if(av[i][j] == 'C' || av[i][j] == 'E')
            {
                write(1, "error, unconnected items\n", 25);
                return(NULL);
            }
            j++;
        }
        i++;
	}
    return(av);
}

char** make_area(char** zone, t_point size)
{
    char** new;
    int i = 0;
    
    new = malloc(sizeof(char*) * size.y);
    
    while (i < size.y)
    {
        int j = 0;
        new[i] = malloc(size.x + 1);
        
        while (j < size.x)
        {
            new[i][j] = zone[i][j];
            j++;
        }
        
        new[i][size.x] = '\0';
        i++;
    }
    return (new);
}