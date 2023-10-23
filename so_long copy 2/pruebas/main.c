/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:23:03 by incalero          #+#    #+#             */
/*   Updated: 2023/10/23 15:57:07 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_array(char **array)
{
	int	i;
	
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);	
		i++;
	}
	free(array);
	return (NULL);
}

int	ft_file_type(char *s)
{
	int		j;
	int		k;
	char	p[4];
	char	*f;

	j = 0;
	f = ".ber";
	if (!s)
		return (-1);
	k = ft_strlen(s) - 4;
	while(s[k] != '\0')
		p[j++] = s[k++];
	j = 0;
	if (p[j] == f[j])
		return (1);
	return (0);
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

int	main(int ac, char **av)
{
	int lines;
	char	**array;
	char	**s;
	
	int fd = open(av[1], O_RDONLY);
	if (fd == -1) 
        return (write (1, "Error opening the file\n", 23), 0);
	lines = ft_lines_count(fd);
	if (ac != 2)
		return (write(1, "Argument Error\n", 15), -1); 
	if (!ft_file_type(av[1]))
		return (write(1, "incorrect file type\n", 20), -1);
	array = ft_create_array(av[1], lines);
	s = ft_remove_jump(lines, array);
	
	return(free_array(s), 0);
	
}
