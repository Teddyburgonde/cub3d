/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:52:41 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/17 14:43:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	manage_cub_extension(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	i--;
	if (i >= 4 && ft_strncmp(&argv[1][i - 3], ".cub", 4) != 0)
		return (1);
	return (0);
}

void	parsing_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong argument number\n", 2);
		exit(EXIT_FAILURE);
	}
	if (manage_cub_extension(argv) == 1)
	{
		ft_putstr_fd("Error: Wrong extension map\n", 2);
		exit(EXIT_FAILURE);
	}
}
