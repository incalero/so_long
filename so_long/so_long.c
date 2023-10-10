/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:01:55 by incalero          #+#    #+#             */
/*   Updated: 2023/10/10 14:28:48 by incalero         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	
	int		lines;
	char	**array;
	char	**clean;
	
	array = NULL;
	clean = NULL;
	if (ac != 2)
		return (write(1, "Argument Error\n", 15), -1); 
	if (!ft_file_type(av[1]))
		return (write(1, "incorrect map\n", 14), -1);
	int fd = open(av[1], O_RDONLY);
	if (fd == -1) 
        return (write (1, "Error opening the file\n", 23), -1);
	lines = ft_lines_count(fd);
	close(fd);
	if (!ft_create_array(av[1], lines))
		return(write(1, "invalid characters\n", 19), -1);
	array = ft_create_array(av[1], lines);
	clean = ft_remove_jump(lines, array);
	if (!ft_correct_map(lines, clean))
		return(write (1, "incorrect map\n", 14), -1);
	if((items_count('P', clean) != 1) || (items_count('E', clean) != 1) || (items_count('C', clean) < 1))
			return (write(1, "wrong itemns\n", 13), -1);
	t_point size = {ft_strlen(clean[0]), lines};
	char**  area = make_area(clean, size);
	t_point begin = ft_p_potition(clean);
	//flood_fill(area, size, begin);
	if (!no_way_error (flood_fill (area, size, begin), size))
		return(-1);
	return (0);
}