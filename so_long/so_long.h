/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:18:21 by incalero          #+#    #+#             */
/*   Updated: 2023/10/10 13:44:56 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include "mlx.h"

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

int		ft_strlen(char *s);
int		ft_jumplen(char *s);
char	*ft_strjoin(char *s, char *buff);
char	*ft_sendline(char *s);
char	*ft_jump(char *s);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_substr(char *s, int start, int len);
char	*ft_free(char *str);
char	*get_next_line(int fd);
int		ft_lines_count(int fd);
int		validate_char(char *s);
char	**ft_create_array(char *av, int lines);
char	**ft_remove_jump(int lines, char **array);
int		ft_file_type(char *s);
int		items_count(char p, char **array);
int		ft_correct_map(int lines, char **array);
int		ft_strlen(char *s);
t_point	ft_p_potition(char **av);
void	fill(char **tab, t_point size, t_point cur, char to_fill);
char	**flood_fill(char **tab, t_point size, t_point begin);
char	**no_way_error(char **av, t_point size);
char**	make_area(char** zone, t_point size);


#endif