/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:35:54 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/11 11:11:48 by tebandam         ###   ########.fr       */
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
		return (NULL);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	free(line);
	free(tmp);
	return (map);
}
