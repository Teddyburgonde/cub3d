/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:57:15 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/13 17:59:28 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	a;
	int	sign;

	i = 0;
	a = 0;
	sign = 1;
	while (is_whitespace(nptr[i]))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i + 1] == '+')
			return (0);
		if (nptr[i] == '-')
			sign *= -1;
		if (nptr[i + 1] == '-')
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		a = a * 10 + (nptr[i] - '0');
		i++;
	}
	return (a * sign);
}