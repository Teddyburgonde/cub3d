/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/06 16:05:44 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY); 
	if (fd < 0 || fd > 1023)
	{
		ft_putstr_fd("The file does not exist\n", 2);
		return (1);
	}
	if (argc != 2 || manage_cub_extension(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
