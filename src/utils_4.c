/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:57:15 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/16 12:09:10 by ppuivif          ###   ########.fr       */
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
