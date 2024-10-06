/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_open_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:49:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/06 19:22:06 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_and_open_file(int *fd, char **argv)
{
	*fd = open(argv[1], O_DIRECTORY);
	if (*fd > 0)
	{
		close(*fd);
		ft_putstr_fd("Error: Is a directory.\n", 2);
		exit(EXIT_FAILURE);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0 || *fd > 1023)
	{
		ft_putstr_fd("Error: The file does not exist.\n", 2);
		exit(EXIT_FAILURE);
	}
}
