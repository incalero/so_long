/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:01:55 by incalero          #+#    #+#             */
/*   Updated: 2023/10/18 08:51:11 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_lines_count(int fd)
{
	int line_count;
	
	line_count = 0;
    while (get_next_line(fd) != NULL) 
        line_count++;
    return (line_count);
}

int	validate_char(char *s)
{
	int	i;
	
	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] != 'P' && s[i] != 'E' && s[i] != 'C' && s[i] != '1' && s[i] != '0' && s[i] != '\n')
			return(0);
		i++;
	}
	return (1);
}

char **ft_create_array(char *av, int lines)
{
	char **array;
	int i;
	char	*s; 
	
	array = (char **)malloc(sizeof(char *) * (lines + 1));
    if (!array) 
        return (NULL);
	int fd = open(av, O_RDONLY);
	if (fd == -1) 
        return (write (1, "Error opening the file\n", 23), NULL);
	i = 1;
	s = get_next_line(fd);
	array[0] = s;
	while ((s != NULL) && (i < lines))
	{
		if (!validate_char(s))
			return(free(s), free(array), NULL);
		s = get_next_line(fd);
		array[i++] = s;
    }
	array[i] = NULL;
	return (close (fd), array);
}

char **ft_remove_jump(int lines, char **array)
{
	int i = 0;
    char **clean = (char **)malloc(sizeof(char *) * (lines + 1));	
    if (clean == NULL)
        return NULL;
    while (array[i] != NULL) 
	{
        int len = strlen(array[i]);
        int j = 0;
        int k = 0;
        clean[i] = (char *)malloc(len + 1);
		if (clean[i] == NULL) 
            return NULL;
        while (j < len) 
		{
            if (array[i][j] != '\n') 
				clean[i][k++] = array[i][j];
            j++;
        }
		clean[i][k] = '\0'; 
		i++;
	}
	clean[i] = NULL;
	return (clean);
}

char	**ft_good_map(char **av)
{
	int		lines;
	char	**array;
	char	**clean;
	t_point	size;
	
	array = NULL;
	clean = NULL;
	int fd = open(av[1], O_RDONLY);
	if (fd == -1) 
        return (write (1, "Error opening the file\n", 23), NULL);
	lines = ft_lines_count(fd);
	close(fd);
	if (!ft_create_array(av[1], lines))
		return(write(1, "invalid characters\n", 19), NULL);
	array = ft_create_array(av[1], lines);
	clean = ft_remove_jump(lines, array);
	if (!ft_correct_map(lines, clean))
		return(write (1, "incorrect map\n", 14), NULL);
	if((items_count('P', clean) != 1) || (items_count('E', clean) != 1) || (items_count('C', clean) < 1))
			return (write(1, "wrong itemns\n", 13), NULL);
	size.x = ft_strlen(clean[0]);
	size.y = lines;
	char**  area = make_area(clean, size);
	t_point begin = ft_p_potition(clean);
	if (!no_way_error (flood_fill (area, size, begin), size))
		return(NULL);
	return (clean);
}
