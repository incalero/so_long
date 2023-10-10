# include "so_long.h"

#define BUFFER_SIZE 32000

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
	free(s);
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
		return (NULL);
	i = 0;
	while (i < j + 1)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

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
		return (free(s), NULL);
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		result = malloc(sizeof(char) * 1);
		if (!result)
			return (NULL);
		free (s);
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
			return (free (s), s = NULL, ft_free(buff));
		buff[b_read] = '\0';
		s = ft_strjoin(s, buff);
	}
	free (buff);
	line = ft_sendline(s);
	s = ft_substr(s, ft_jumplen(s) + 1, ft_strlen(s));
	if (!b_read && *line == '\0')
		return (ft_free(line));
	return (line);
}

/* int main() 
{

	
	int fd = open("map8.ber", O_RDONLY);

	if (fd == -1) 
	{
        printf ("Error al abrir el archivo 1");
        return (1);
    }

    printf("1 - %s", get_next_line(fd));
	printf("2 - %s", get_next_line(fd));
	printf("3 - %s", get_next_line(fd));
	printf("4 - %s", get_next_line(fd));
	printf("5 - %s", get_next_line(fd));
	printf("6 - %s", get_next_line(fd));
	printf("7 - %s", get_next_line(fd));
	printf("8 - %s", get_next_line(fd));
	printf("9 - %s", get_next_line(fd));
	printf("10 - %s", get_next_line(fd));
	printf("11 - %s", get_next_line(fd));
	printf("12 - %s", get_next_line(fd));
	printf("13 - %s", get_next_line(fd));
	printf("14 - %s", get_next_line(fd));
	printf("15 - %s", get_next_line(fd));
	printf("16 - %s", get_next_line(fd));
	printf("17 - %s", get_next_line(fd));
	printf("18 - %s", get_next_line(fd));
	printf("19 - %s", get_next_line(fd));
	return(0);
} */
