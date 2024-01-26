/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:23:03 by incalero          #+#    #+#             */
/*   Updated: 2023/11/15 11:09:43 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	d;
	int		fd;

	if (ac != 2)
		return (ft_printf("Argument Error\n"), -1);
	if (ft_file_type(av[1]))
		return (ft_printf("Error, incorrect file type\n"), -1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf ("Error opening the file\n"), 0);
	d.lines = ft_lines_count(fd);
	close(fd);
	if (!ft_good_map(d, av))
		return (0);
	ft_play(d, ft_good_map(d, av));
	return (0);
}
