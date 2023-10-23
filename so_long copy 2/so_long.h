/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:18:21 by incalero          #+#    #+#             */
/*   Updated: 2023/10/23 15:16:49 by incalero         ###   ########.fr       */
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
	int		x;
	int		y;
}				t_point;

typedef struct s_data
{
	char	**ar;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*ground;
	void	*player;
	void	*item;
	void	*exit;
	void	*img;
	int		res;
	int		movement;
	int		count;
	int		fin;
	int		pos_x;
	int		pos_y;
	
}				t_data;

/*MAIN*/
int		main(int ac, char **av);

/*FT_GOOD_MAP*/
char	**ft_good_map(char **av);
char	**ft_remove_jump(int lines, char **array);
char	**ft_create_array(char *av, int lines);
int		validate_char(char *s);
int		ft_lines_count(int fd);

/*SO_LONG_UTILS*/
int		ft_correct_map(int lines, char **array);
int		items_count(char p, char **array);
int		ft_file_type(char *s);
void	*ft_del(char **array, int j);
void	free_array(char **array);

/*SO_LONG_UTILS_B*/
char**	make_area(char** zone, t_point size);
char	**no_way_error(char **av, t_point size);
char	**flood_fill(char **tab, t_point size, t_point begin);
void	fill(char **tab, t_point size, t_point cur, char to_fill);
t_point	ft_p_potition(char **av);

/*GET_NEXT_LINE*/
char	*get_next_line(int fd);
char	*ft_free(char *str);
char	*ft_jump(char *s);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_substr(char *s, int start, int len);

/*GET_NEXT_LINE_UTILS*/
char	*ft_strjoin(char *s, char *buff);
int		ft_strlen(char *s);
int		ft_jumplen(char *s);
char	*ft_sendline(char *s);

/*FT_PLAY*/
//void	ft_play(char **av);
//int 	line_count(char **av);
//int 	ft_move(t_data *d, int x, int y);
//int		ft_free_ar(t_data *d);

#endif