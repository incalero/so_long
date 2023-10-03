/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:57:39 by incalero          #+#    #+#             */
/*   Updated: 2023/10/03 15:51:13 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long_1.h"

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

int ft_lines_count(fd)
{
	int line_count;
	
	line_count = 0;
    while (get_next_line(fd) != NULL) 
        line_count++;
    return (line_count);
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
		s = get_next_line(fd);
		array[i] = s;
		i++;
    }
	free(s);
	array[i] = NULL;
	close (fd);
	return (array);
}
char **ft_remove_jump(char **array)
{
	int i;
	int j;
	int	k;
	char	**clean;

	i = 0;
	j = 0;
	k = ft_strlen(array[0]);
	clean = NULL;
	while (array[i] != NULL && j < k)
	{
		clean[i][j] = array[i][j];
		j++;
		i++;
	}
	printf("el array 1 es = %s\n", array[0]);
	printf("el array 2 es = %s\n", array[1]);
	printf("el array 3 es = %s\n", array[2]);
	printf("el array 4 es = %s\n", array[3]);
	printf("el array 5 es = %s\n", array[4]);
	printf("el array 6 es = %s\n", array[5]);
	printf("el array 7 es = %s\n", array[6]);
	printf("el array 8 es = %s\n", array[7]);
	printf("el array 9 es = %s\n", array[8]);
	printf("el array 10 es = %s\n", array[9]);
	printf("el array 11 es = %s\n", array[10]);
	printf("el array 12 es = %s\n", array[11]);
	printf("el array 13 es = %s\n", array[12]);
	printf("el array 14 es = %s\n", array[13]);
		
	printf("k = %d\n", k);
	return (clean);
}
int ft_correct_map(int lines, char **array)
{
	int	i;
	int j;
	
	i = 0;
	j = 1;
	while (array[i] != NULL)
	{
		if (lines > 4)
			return (0);
		while (ft_strlen(array[i++]) != ft_strlen(array[j++]))
			return (0);
	}
	return(0);
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
	array = ft_create_array(av[1], lines);
	if (array == NULL) 
		return (write (1, "Error creating the array\n", 25), -1);
	clean = ft_remove_jump(array);
	
	printf("el len del array 1 es %d\n", ft_strlen(array[0]));
	printf("el len del array 14 es %d\n", ft_strlen(array[13]));
	
	/* printf("el array 1 es = %s\n", array[0]);
	printf("el array 2 es = %s\n", array[1]);
	printf("el array 3 es = %s\n", array[2]);
	printf("el array 4 es = %s\n", array[3]);
	printf("el array 5 es = %s\n", array[4]);
	printf("el array 6 es = %s\n", array[5]);
	printf("el array 7 es = %s\n", array[6]);
	printf("el array 8 es = %s\n", array[7]);
	printf("el array 9 es = %s\n", array[8]);
	printf("el array 10 es = %s\n", array[9]);
	printf("el array 11 es = %s\n", array[10]);
	printf("el array 12 es = %s\n", array[11]);
	printf("el array 13 es = %s\n", array[12]);
	printf("el array 14 es = %s\n", array[13]); */
	return (0);
}