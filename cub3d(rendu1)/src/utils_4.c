/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:57:15 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/18 20:21:01 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*skip_first_spaces(char *str)
{
	while (str && *str && (*str == ' '))
		str++;
	return (str);
}

float	clamp(float num, float min, float max)
{
	if (num < min)
		return (max + num);
	if (num > max)
		return (num - max);
	return (num);
}

char	**arr_copy(char **arr)
{
	int		i;
	int		nmemb;
	char	**result;

	i = 0;
	nmemb = 0;
	result = NULL;
	while (arr && arr[nmemb])
		nmemb++;
	result = ft_calloc(nmemb + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (arr && arr[i])
	{
		result[i] = ft_strdup(arr[i]);
		if (!result[i])
		{
			free_array(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
