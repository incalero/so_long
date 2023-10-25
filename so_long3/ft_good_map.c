/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:01:55 by incalero          #+#    #+#             */
/*   Updated: 2023/10/25 18:47:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lines_count(int fd)
{
	int	line_count;
	char	*s;

	line_count = 0;
	while (1)
	{
		s = get_next_line(fd);
		if(s)
		{
			line_count++;
			free(s);
		}
		else
			break;
	}
	return (line_count);
}

int	validate_char(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != 'P' && s[i] != 'E' && s[i] != 'C' && s[i] \
		!= '1' && s[i] != '0' && s[i] != '\n')
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
	{
        return (NULL);
	}
	int fd = open(av, O_RDONLY);
	if (fd == -1) 
        return (free_array(array), write (1, "Error opening the file\n", 23), NULL);
	i = 0;
	while (i < lines)
	{
		s = get_next_line(fd);
		array[i++] = s;
    }
	array[i] = NULL;
	close (fd);
	return (array);
}
char **ft_remove_jump(int lines, char **array)
{
	int	i;
	int	len;
	
	i = 0;
	if(!array)
		return (NULL);
	while (i < lines && array != NULL)
	{
		len = ft_strlen(array[i]);
		if(len > 0)
			array[i][len -1] = '\0';
		i++;
	}
	return (array);
}



/*char **ft_remove_jump(int lines, char **array)
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
	printf("%s" ,clean[0]);
	printf("%s" ,clean[1]);
	printf("%s" ,clean[2]);
	printf("%s" ,clean[3]);
	printf("%s" ,clean[4]);
	return (free_array(array), clean);
}*/

char	**ft_good_map(char **av)
{
	int		lines;
	char	**array;
	char	**clean;
	t_point	size;
	char**  area;
	
	//array = NULL;
	//clean = NULL;
	int fd = open(av[1], O_RDONLY);
	if (fd == -1) 
        return (write (1, "Error opening the file\n", 23), NULL);
	lines = ft_lines_count(fd);
	close(fd);
	array = ft_create_array(av[1], lines);
	clean = ft_remove_jump(lines, array );
	ft_correct_map(lines, clean);
	if((items_count('P', clean) != 1) || (items_count('E', clean) != 1) || (items_count('C', clean) < 1))
			return (free_array(clean), write(1, "wrong itemns\n", 13), NULL);
	size.x = ft_strlen(clean[0]);
	size.y = lines;
	area = make_area(clean, size);
	if (!no_way_error (flood_fill (area, size, ft_p_potition(clean)), size))
		return(free_array(clean), NULL);
	//free_array(area);
	free_array(array);
	return (NULL);
}
