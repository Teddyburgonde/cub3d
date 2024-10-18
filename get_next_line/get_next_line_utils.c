/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:53:47 by ppuivif           #+#    #+#             */
/*   Updated: 2024/10/18 18:43:20 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../cub3d.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof (char));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

char	*begin_new_line(char *s1, int fd)
{
	char	*s2;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) - find_line_return(s1);
	if (len == 0)
	{
		free(s1);
		return (NULL);
	}
	s2 = ft_calloc(len + 1, sizeof(char));
	if (!s2)
		display_allocation_failed_and_exit(fd);
	i = 0;
	j = find_line_return(s1);
	while (s1 && s1[j])
	{
		s2[i] = s1[j];
		i++;
		j++;
	}
	if (s1)
		free(s1);
	return (s2);
}

char	*close_current_line(char *s1, int fd)
{
	char	*s2;
	int		len;
	int		i;

	len = find_line_return(s1);
	s2 = ft_calloc((len + 1), sizeof(char));
	if (!s2)
		display_allocation_failed_and_exit(fd);
	i = 0;
	while (s1 && s1[i] && i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
