/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:53 by incalero          #+#    #+#             */
/*   Updated: 2023/10/23 14:13:07 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_jumplen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s, char *buff)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	if (!s)
	{
		s = malloc(1);
		*s = '\0';
	}
	len = ft_strlen(s) + ft_strlen(buff);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
		result[i++] = buff[j++];
	ft_free(s);
	return (result[i] = '\0', result);
}

char	*ft_sendline(char *s)
{
	int		i;
	int		j;
	char	*result;

	j = ft_jumplen(s);
	if (!s)
		return (NULL);
	result = (char *)malloc(j + 2);
	if (!result)
		return(NULL);
	i = 0;
	while (i < j + 1)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}