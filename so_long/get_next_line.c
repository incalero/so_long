/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:39 by incalero          #+#    #+#             */
/*   Updated: 2023/10/26 11:41:08 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BUFFER_SIZE 32000

char	*ft_jump(char *s)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst [i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, int start, int len)
{
	char	*result;

	if (!ft_jump(s))
		return (ft_free(s), NULL);
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		result = malloc(sizeof(char) * 1);
		if (!result)
			return (NULL);
		ft_free (s);
		result[0] = '\0';
		return (result);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	result = malloc(sizeof(char) * (len +1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len +1);
	free (s);
	return (result);
}

char	*ft_free(char *str)
{
	free (str);
	return (NULL);
}

char	*get_next_line(int fd)

{
	int			b_read;
	char		*buff;
	static char	*s = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	b_read = 1;
	while (!ft_jump(s) && b_read > 0)
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read < 0)
			return (ft_free (s), s = NULL, ft_free(buff));
		buff[b_read] = '\0';
		s = ft_strjoin(s, buff);
	}
	ft_free (buff);
	line = ft_sendline(s);
	s = ft_substr(s, ft_jumplen(s) + 1, ft_strlen(s));
	if (!b_read && *line == '\0')
		return (ft_free(line));
	return (line);
}
