/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:35:54 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/18 22:27:11 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**build_array(char **arr, int i)
{
	int		j;
	char	**result;

	result = malloc((i + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	j = 0;
	while (arr && arr[j])
	{
		result[j] = ft_strdup(arr[j]);
		if (!result[j])
		{
			free_array(arr);
			free_array(result);
			return (NULL);
		}
		j++;
	}
	result[j + 1] = NULL;
	free_array(arr);
	return (result);
}

static char	**get_lines(int fd, char *line)
{
	int		i;
	char	**file_content;

	i = 0;
	file_content = NULL;
	while (line)
	{
		file_content = build_array(file_content, i);
		if (!file_content)
		{
			free(line);
			display_allocation_failed_and_exit(fd);
		}
		file_content[i] = ft_substr(line, 0, ft_strcspn(line, "\n"));
		free(line);
		if (!file_content[i])
			display_allocation_failed_and_exit(fd);
		line = get_next_line(fd);
		i++;
	}
	return (file_content);
}

char	**get_file_content(int fd)
{
	char	**file_content;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit_when_file_is_empty(fd);
	file_content = get_lines(fd, line);
	if (fd > 2)
		close(fd);
	return (file_content);
}
