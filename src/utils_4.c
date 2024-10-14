/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:57:15 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/14 19:58:20 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*skip_first_whitespaces(char *str)
{
	while (str && *str && (is_whitespace(*str) == 1))
		str++;
	return (str);
}

int	line_is_full_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (0);
	}
	return (1);
}

float	clamp(float num, float min, float max)
{
	if (num < min)
		return (max + num);
	if (num > max)
		return (num - max);
	return (num);
}
