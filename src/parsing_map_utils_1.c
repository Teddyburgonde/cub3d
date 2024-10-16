/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:50:29 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/16 08:42:53 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_if_empty_line(char *line, t_game *game)
{
	if(line && line_is_full_whitespaces(line) == 1)
	{
		ft_putstr_fd("Error: Invalid map1\n", 2);
		free_structs(game);
		exit(EXIT_FAILURE);
	}
}

void	check_char_validity(char *line, t_game *game)
{
	int		j;
	char	*valid_chars;

	j = 0;
	valid_chars = "10 NSEW";
	while (line && line[j])
	{
		if (ft_strchr(valid_chars, line[j]) == 0)
		{
			ft_putstr_fd("Error: Invalid map2\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

static void	check_first_and_last_line(char *line, t_game *game)
{
	int	j;

	j = 0;
	while(line && line[j])
	{
//		if(line[j] != '1' && line [j] != 32)
		if(line[j] != '1')
		{
			ft_putstr_fd("Error: Invalid map3\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

static void	check_current_line(char *line, t_game *game)
{
	int	j;
	int	len;

	len = ft_strlen(line);
	j = 0;
	while (line && line[j])
	{
//		if((j == 0 || j == len - 1) && line[j] != '1' && line [j] != 32)//une ligne peut-elle commencer par un espace ?
		if((j == 0 || j == len - 1) && line[j] != '1')
		{
			ft_putstr_fd("Error: Invalid map4\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}	

static int	*get_lines_lenght(t_game *game)
{
	int	*lines_len;
	int	i;
	
	lines_len = malloc((game->data->nb_lines + 1) * sizeof(int));
	if (!lines_len)
	{
		free_structs(game);
		display_allocation_failed_and_exit();
	}
	i = 0;
	while (game->data->map[i])
	{
		lines_len[i] = ft_strlen(game->data->map[i]);
		i++;
	}
	lines_len[i] = -1;
	return(lines_len);
}

static void	check_1_on_current_line(char **map, int i, \
t_game *game, int *lines_len, int index)
{
	int	j;

	j = lines_len[index];
	while (j != -1 && map[i][j] && map[i][j] == '1')
		j++;
	if (j != -1 && map[i][j] && map[i][j] != '1')
	{
		ft_putstr_fd("Error: Invalid map5\n", 2);
		free(lines_len);
		free_structs(game);
		exit(EXIT_FAILURE);
	}
}

static void	compare_lines_one_each_other(char **map, int i, \
t_game *game, int *lines_len)
{
	int	lower_delta_len;
	int	upper_delta_len;

	lower_delta_len = lines_len[i] - lines_len[i - 1];
	upper_delta_len = lines_len[i] - lines_len[i + 1];
	if (lower_delta_len > 0)
		check_1_on_current_line(map, i, game, lines_len, i - 1);
	if (lower_delta_len < 0)
		check_1_on_current_line(map, i, game, lines_len, i + 1);
}

void	check_if_map_closed(t_game *game)
{
	int		i;
	char	**map;
	int *lines_len;

	i = 0;
	map = game->data->map;
	check_first_and_last_line(map[i], game);
	i++;
	lines_len = get_lines_lenght(game);
	while(map[i] && i != game->data->nb_lines - 1)
	{
		compare_lines_one_each_other(map, i, game, lines_len);
		free(lines_len);
		check_current_line(map[i], game);
		i++;
	}
	check_first_and_last_line(map[i], game);
}
