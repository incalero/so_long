/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_camino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:10:19 by incalero          #+#    #+#             */
/*   Updated: 2023/10/06 15:35:23 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

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

void fill(char **tab, t_point size, t_point cur, char to_fill, char replacement)
{
    if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
        || tab[cur.y][cur.x] != to_fill)
        return ;

    char replace_chars[] = {'0', 'E', 'C', 'P'};
    int i = 0;

    while (i < sizeof(replace_chars) / sizeof(replace_chars[0])) {
        if (to_fill == replace_chars[i]) {
            tab[cur.y][cur.x] = replacement;
            break;
        }
        i++;
    }

    fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill, replacement);
    fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill, replacement);
    fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill, replacement);
    fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill, replacement);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x], tab[begin.y][begin.x]);
}


char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}
int main(void)
{
	int	lines = 14;
	char *zone[] = {
		"11111111111111111",
		"1P000000000000001",
		"11110111111111111",
		"100000C0000000101",
		"10111111111111101",
		"10000000000000001",
		"11111111111111101",
		"10000000000000001",
		"11111111111111101",
		"10000000000000001",
		"11111111111111101",
		"1000C000000000001",
		"100000000000000E1",
		"11111111111111111",
	};

	t_point size = {ft_strlen(zone[0]), lines};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = ft_p_potition(zone);
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}