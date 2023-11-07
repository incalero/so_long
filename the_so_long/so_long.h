/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:18:21 by incalero          #+#    #+#             */
/*   Updated: 2023/11/07 13:20:09 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "mlx.h"

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
	int		x;
	int		y;
	int		lines;
}				t_data;

/*MAIN*/
int		main(int ac, char **av);

/*FT_GOOD_MAP*/
char	**ft_good_map(t_data d, char **av);
char	**ft_remove_jump(int lines, char **array);
char	**ft_create_array(char *av, int lines);
int		validate_char(int lines, char **s);
int		ft_lines_count(int fd);

/*SO_LONG_UTILS*/
int		ft_correct_map(int lines, char **array);
int		items_count(char p, char **array);
int		ft_file_type(char *s);
void	f_ar(char **array);
int		mlx_f_ar(t_data *d);

/*SO_LONG_UTILS_B*/
char	**make_area(char **zone, t_data size);
char	**no_way_error(char **av, t_data size);
char	**flood_fill(char **tab, t_data size, t_data begin);
void	fill(char **tab, t_data size, t_data cur, char to_fill);
t_data	ft_p_potition(char **av);

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
int		line_count(char **av);

/*FT_PLAY_UTILS*/
int		ft_print_map(t_data *d);
void	ft_print_items(t_data *d);
int		ft_items(t_data *d);
void	ft_declare_image(t_data *d);
int		key_hook(int keycode, t_data *d);

/*FT_PLAY*/
void	ft_play(t_data d, char **av);
int		ft_move(t_data *d, int x, int y);
void	ft_new_potition(t_data	*d);
int		ft_item_count(t_data *d);
void	ft_print_player(t_data *d);

#endif
