/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:35:54 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/15 14:52:01 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**build_array(char **arr, int i)
{
	int		j;
	char	**result;

//	result = ft_calloc(i + 2, sizeof(char *));
	result = malloc((i + 2) * sizeof(char *));
	j = 0;
	if (!result)
		return (NULL);
	while (arr && arr[j])
	{
		result[j] = ft_strdup(arr[j]);
		j++;
	}
	result[j + 1] = NULL;
	free_array(arr);
	return (result);
}
// 

char	**get_file_content(int fd)
{
	char	**file_content;
	char	*line;
	int		i;

	file_content = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Error: File is empty\n", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while(line)
	{
		file_content = build_array(file_content, i);
		file_content[i] = ft_substr(line, 0, ft_strcspn(line, "\n"));
		if (!file_content[i])
			display_allocation_failed_and_exit();
//		printf("file_content[%d] :%s\n", i, file_content[i]);
//		ft_print_value_map(file_content);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (fd > 2)
		close(fd);
	return (file_content);
}
