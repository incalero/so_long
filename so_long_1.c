/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:57:39 by incalero          #+#    #+#             */
/*   Updated: 2023/10/06 13:35:39 by incalero         ###   ########.fr       */
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
			return(free(s), free(array), printf("error de caracteres"), NULL);
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

int items_count(char p, char **array)
{
	int	i;
	int	j;
	int count;
	char *s;

	s = "PEC";
	i = 0;
	j = 0;
	count = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == p)
				count++;
			j++;
		}
		i++;
	}
	return(count);
}

int ft_correct_map(int lines, char **array)
{
	int	i;
	int j;
	int	k;
	
	k = 0;
	i = 0;
	j = i + 1;
	while (array[i] != NULL)
	{
		if (lines < 4)
			return (0);
		if ((i < lines) && (ft_strlen(array[i]) != ft_strlen(array[j])))
			return (0); 
		while (array[0][k] != '\0' || array[lines - 1][k] != '\0')
		{
			if (array[0][k] != '1' || array[lines - 1][k] != '1')
				return (0);
			k++;			
		}
		if (array[i][0] != '1' || array[i][ft_strlen(array[i]) - 1] != '1')
			return(0);
		i++;
	}
	return(1);
}

int	all_conected(int lines, int	len, char **array)
{
	
}

int	main(int ac, char **av)
{
	//int 	i;
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
	clean = ft_remove_jump(lines, array);
	if (!ft_correct_map(lines, clean))
		return(write (1, "incorrect map\n", 14), -1);
	if((items_count('P', clean) != 1) || (items_count('E', clean) != 1) || (items_count('C', clean) < 1))
			return (write(1, "wrong itemns\n", 13), 0);
	if (!all_conected(lines, ft_strlen(clean[0]), clean))
	
	/* i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);  */
	
	
	/* printf("el clean 1 es = %s\n", clean[0]);
	printf("el clean 2 es = %s\n", clean[1]);
	printf("el clean 3 es = %s\n", clean[2]);
	printf("el clean 4 es = %s\n", clean[3]);
	printf("el clean 5 es = %s\n", clean[4]);
	printf("el clean 6 es = %s\n", clean[5]);
	printf("el clean 7 es = %s\n", clean[6]);
	printf("el clean 8 es = %s\n", clean[7]);
	printf("el clean 9 es = %s\n", clean[8]);
	printf("el clean 10 es = %s\n", clean[9]);
	printf("el clean 11 es = %s\n", clean[10]);
	printf("el clean 12 es = %s\n", clean[11]);
	printf("el clean 13 es = %s\n", clean[12]);
	printf("el clean 14 es = %s\n", clean[13]); */
	


	return (0);
}