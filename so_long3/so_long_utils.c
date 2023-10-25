/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:09:52 by incalero          #+#    #+#             */
/*   Updated: 2023/10/25 18:54:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	free_array(char **array)
{
	int	i;
	
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);	
		i++;
	}
	free(array);
}


int	ft_file_type(char *s)
{
	int		k;

	if (!s)
		return (-1);
	k = ft_strlen(s) - 4;
	if(s[k] != '.' && s[k + 1] != 'b' && s[k + 2] != 'e' &&s[k + 3] != 'r')
		return (1);
	return (0);
}

int items_count(char p, char **array)
{
	int	i;
	int	j;
	int count;
	//char *s = "PEC";

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

	while (i <= lines)
	{
		j = i + 1;
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