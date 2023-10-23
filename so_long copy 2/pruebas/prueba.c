/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:50:51 by incalero          #+#    #+#             */
/*   Updated: 2023/10/23 15:50:32 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
        return (free_array(array), write (1, "Error opening the file\n", 23), NULL);
	i = 1;
	s = get_next_line(fd);
	array[0] = s;
	while (s != NULL)
	{
		s = get_next_line(fd);
		array[i++] = s;
    }
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
	return (free_array(array), clean);
}