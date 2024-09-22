/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:06:44 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/22 17:55:49 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_separator(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static int	wd_count_words(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_separator(str[i], charset))
		{
			count++;
			while (str[i] && !ft_separator(str[i], charset))
				i++;
			if (!str[i])
				i--;
		}
		i++;
	}
	return (count);
}

static char	*ft_strdup_edit(const char *str, char charset)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !ft_separator(str[i], charset))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_separator(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (wd_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && ft_separator(s[i], c))
			i++;
		if (s[i] && !ft_separator(s[i], c))
		{
			tab[j] = ft_strdup_edit(&s[i], c);
			j++;
			while (s[i] && !ft_separator(s[i], c))
				i++;
		}
	}
	tab[j] = 0;
	return (tab);
}
