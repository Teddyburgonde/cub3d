/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:39:22 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/09 01:22:28 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*tab;

	tab = s;
	i = 0;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (s);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void		*ptr;
// 	long int	size_alloc;

// 	size_alloc = nmemb * size;
// 	if (size_alloc < 0 || ((int)nmemb < 0 && (int)size < 0))
// 		return (NULL);
// 	ptr = malloc(nmemb * size);
// 	if (ptr)
// 		ft_memset(ptr, '\0', nmemb * size);
// 	return (ptr);
// }
