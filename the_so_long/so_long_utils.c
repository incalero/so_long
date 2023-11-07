/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:10 by incalero          #+#    #+#             */
/*   Updated: 2023/11/07 13:07:58 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	ft_p_potition(char **av)
{
	t_data	p;
	int		i;
	int		j;

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
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}

void	fill(char **tab, t_data size, t_data cur, char to_fill)
{
	t_data	d;

	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || \
	(tab[cur.y][cur.x] != 'P' && tab[cur.y][cur.x] != '0' && \
	tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'E'))
		return ;
	tab[cur.y][cur.x] = 'F';
	d.x = cur.x - 1;
	d.y = cur.y;
	fill(tab, size, d, to_fill);
	d.x = cur.x + 1;
	d.y = cur.y;
	fill(tab, size, d, to_fill);
	d.x = cur.x;
	d.y = cur.y - 1;
	fill(tab, size, d, to_fill);
	d.x = cur.x;
	d.y = cur.y + 1;
	fill(tab, size, d, to_fill);
}

char	**flood_fill(char **tab, t_data size, t_data begin)
{
	fill (tab, size, begin, tab[begin.y][begin.x]);
	return (tab);
}

char	**no_way_error(char **av, t_data size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size.y)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == 'C' || av[i][j] == 'E')
			{
				write (1, "Error, unconnected items\n", 25);
				return (f_ar(av), NULL);
			}
			j++;
		}
		i++;
	}
	return (av);
}

char	**make_area(char **clean, t_data size)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	new = (char **)malloc (sizeof(char *) * (size.y + 1));
	if (!new)
		return (NULL);
	while (i < size.y)
	{
		j = 0;
		new[i] = malloc(size.x + 1);
		while (j < size.x)
		{
			new[i][j] = clean[i][j];
			j++;
		}
		new[i][size.x] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}
