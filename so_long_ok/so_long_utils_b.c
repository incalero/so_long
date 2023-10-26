/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:10 by incalero          #+#    #+#             */
/*   Updated: 2023/10/26 11:40:50 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	ft_p_potition(char **av)
{
	t_point p;
    int i;
    int j;

	p.x = -1;
    p.y = -1;
    i = 0;
    while (av[i] != NULL)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if (av[i][j] == 'P')
            {
                p.x = j;
                p.y = i;
                return(p);
            }
            j++;
        }
        i++;
    }
    return (p);
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
    return(free_array(av), av);
}

char** make_area(char** clean, t_point size)
{
    char** new;
    int i = 0;
    
    new = malloc(sizeof(char*) * size.y);
    if(!new)
        return (free_array(clean), NULL);
    while (i < size.y)
    {
        int j = 0;
        new[i] = malloc(size.x + 1);
        
        while (j < size.x)
        {
            new[i][j] = clean[i][j];
            j++;
        }
        
        new[i][size.x] = '\0';
        i++;
    }
    return (new);
}