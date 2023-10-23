/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:23:03 by incalero          #+#    #+#             */
/*   Updated: 2023/10/23 12:48:21 by incalero         ###   ########.fr       */
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
		return (write(1, "imposible to play\n", 18), -1);
	//ft_play(ft_good_map(av));
	return (0);
	
}
