/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:27:17 by ppuivif           #+#    #+#             */
/*   Updated: 2024/10/14 18:57:16 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char	const *s, unsigned int start, int len)
{
	int		i;
	int		j;
	char	*str;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(&s[start])))
		len = ft_strlen(&s[start]);
	str = (char *)malloc((len + 1) * sizeof (char));
	if (str)
	{
		while (j < len && s[i] != '\0')
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int		count;
	size_t	i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	start_str(char const *s, char c, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (count == 1)
		return (0);
	if (!s)
		return (0);
	while (j < count - 1)
	{
		if (s[i] == '\0')
			break ;
		if (s[i + 1] != '\0' && s[i] == c && s[i + 1] != c)
		{
			j++;
			i++;
		}
		i++;
	}
	return (i - 1);
}

static int	len_str(char const *s, char c, int start)
{
	int	i;

	i = start;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i - start);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	int		len;
	int		i;
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count_words(s, c) && *s)
	{
		while (*s == c && *s)
			s++;
		start = start_str(s, c, i + 1);
		len = len_str(s, c, start);
		tab[i] = ft_substr(s, start, len);
		if (!tab[i])
			return (free_array(tab));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
