/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:23:03 by incalero          #+#    #+#             */
/*   Updated: 2023/10/24 22:25:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "Argument Error\n", 15), -1); 
	if (!ft_file_type(av[1]))
		return (write(1, "incorrect file type\n", 20), -1);
	if(!ft_good_map(av))
		return (-1);
	//ft_play(ft_good_map(av));
	return (0);
	
}
