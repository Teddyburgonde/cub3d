/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:35:54 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/10 10:40:48 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**get_map(int fd)
{
	char	**map;
	char	*line;
	char	*tmp;

	map = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Error: Map is empty.\n", 2);
		exit(EXIT_FAILURE);
	}
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		if (!line)
			display_allocation_failed_and_exit();
//		tmp = NULL;
		tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
//	free(tmp);
	free(line);
	if (fd > 2)
		close(fd);
	if(!map)
		display_allocation_failed_and_exit();
	return (map);
}
