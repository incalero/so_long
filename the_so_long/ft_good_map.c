/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:54:42 by incalero          #+#    #+#             */
/*   Updated: 2023/11/07 11:54:48 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lines_count(int fd)
{
	int		line_count;
	char	*s;

	line_count = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (s)
		{
			line_count++;
			free(s);
		}
		else
			break ;
	}
	return (line_count);
}

int	validate_char(int lines, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] != 'P' && s[i][j] != 'E' && s[i][j] != 'C' && \
			s[i][j] != '1' && s[i][j] != '0' && s[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_create_array(char *av, int lines)
{
	char	**array;
	int		i;
	char	*s;
	int		fd;

	array = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!array)
		return (NULL);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (f_ar(array), write (1, "Error, wrong file\n", 18), NULL);
	i = 0;
	while (i <= lines)
	{
		s = get_next_line(fd);
		array[i++] = s;
	}
	close (fd);
	return (array);
}

char	**ft_remove_jump(int lines, char **array)
{
	int		i;
	char	**clean;
	int		len;
	int		j;
	int		k;

	i = 0;
	clean = (char **)malloc(sizeof(char *) * (lines + 1));
	if (clean == NULL)
		return (NULL);
	while (array[i] != NULL)
	{
		len = strlen(array[i]);
		j = 0;
		k = 0;
		clean[i] = (char *)malloc(len + 1);
		if (clean[i] == NULL)
			return (NULL);
		while (array[i][j] && array[i][j] != '\n')
			clean[i][k++] = array[i][j++];
		clean[i][k] = '\0';
		i++;
	}
	return (clean[i] = NULL, clean);
}

char	**ft_good_map(t_data d, char **av)
{
	char	**array;
	char	**clean;
	char	**area;

	array = NULL;
	clean = NULL;
	array = ft_create_array(av[1], d.lines);
	if (validate_char(d.lines, array))
		return (f_ar(array), write(1, "Error, wrong character\n", 23), NULL);
	d.ar = ft_remove_jump(d.lines, array);
	f_ar(array);
	if (!ft_correct_map(d.lines, d.ar))
		return (f_ar(d.ar), write (1, "Error, incorrect map\n", 21), NULL);
	if ((items_count('P', d.ar) != 1) || (items_count('E', d.ar) != 1) || \
	(items_count('C', d.ar) < 1))
		return (f_ar(d.ar), write(1, "Error, wrong itemns\n", 20), NULL);
	d.x = ft_strlen(d.ar[0]);
	d.y = d.lines;
	area = make_area(d.ar, d);
	if (!no_way_error (flood_fill (area, d, ft_p_potition(d.ar)), d))
		return (f_ar(d.ar), (write(1, "Error, wrong map\n", 10)), NULL);
	f_ar(area);
	return (d.ar);
}
