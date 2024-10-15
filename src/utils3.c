/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:57:15 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/14 17:07:56 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

/*int	ft_strcspn(char *line, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (str[j])
		{
			if (line[i] == str[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}*/

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
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		a = a * 10 + (nptr[i] - '0');
		i++;
	}
	while (nptr[i] && nptr[i] == ' ')
		i++;
	if (nptr[i])
		return (-1);
	return (a * sign);
}
