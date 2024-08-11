/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:52:41 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/11 11:48:30 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	manage_cub_extension(char **argv)
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

int	parsing_arguments(int argc, char **argv)
{
	if (argc != 2)
		return (message_error_for_parsing_args("Wrong argument number.\n", 1));
	if (manage_cub_extension(argv) == 1)
		return (message_error_for_parsing_args("Wrong extension map.\n", 1));
	return (0);
}
