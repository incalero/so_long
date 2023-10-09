/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_1.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:03:30 by incalero          #+#    #+#             */
/*   Updated: 2023/10/06 12:21:38 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_1_H
# define SO_LONG_1_H

# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<string.h>


int		ft_strlen(char *s);
int		ft_jumplen(char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_sendline(char *s);
char	*ft_jump(char *s);
char	*ft_strjoin(char *s, char *buff);
char	*ft_free(char *str);
char	*get_next_line(int fd);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_file_type(char *s);
int		validate_char(char *s);
char 	**ft_create_array(char *av, int lines);
char 	**ft_remove_jump(int lines, char **array);
int		items_count(char p, char **array);
int		ft_correct_map(int lines, char **array);


#endif