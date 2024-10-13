/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:50:29 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/13 09:55:45 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_first_and_last_line(char *line, t_game *game)
{
	int	j;

	j = 0;
	while(line && line[j])
	{
		if(line[j] != 1 && line [j] != 32)
		{
			ft_putstr_fd("Error: Invalid map\n", 2);
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
		if((j = 0 || j = len - 1) && line[j] != 1 && line [j] != 32) //une ligne peut-elle commencer par un espace ?
		{
			ft_putstr_fd("Error: Invalid map\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}	

void	check_if_map_closed(t_game *game);
{
	int		i;
	char	**map;

	i = 0;
	map = game->data->map;
	check_first_and_last_line(map[i], game);
	i++;
	while(map[i] && i != game->data->nb_lines - 1)
	{
		check_curent_line(map[i], game);
		i++;
	}
	check_first_and_last_line(map[i], game);
}

int	check_char_validity(char *line, int len, t_game *game)
{
	int		j;
	char	*valid_chars;

	j = 0;
	valid_chars = "10 NSEW";
	while (line && line[j])
	{
		if (ft_strchr(valid_chars, str[j]) < len)
		{
			ft_putstr_fd("Error: Invalid map\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	if(game->data->nb_columns <= j)
		game->data->nb_columns = j;
}











int	is_line_valid(char *line)
{
	char	*valid_chars;
	int		i;

	valid_chars = "10 NSEW";
	i = 0;
	while (line && line[i])
	{
		if (ft_strchr(valid_chars, str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_direction_valid(char *str, t_map_data *map_data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (map_data->direction && (str[i] == 'N' || str[i] == 'S'
				|| str[i] == 'E' || str[i] == 'W'))
			return (0);
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			map_data->direction = str[i];
		i++;
	}
	return (1);
}

void	check_top_and_bottom_wall_closed(char *str, t_game *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
		{
			ft_putstr_fd("Error: Invalid map\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}








void	check_around_0(char	**line, t_game *game)
{
	int	i;
	int	j;

	j = 1;
	while (line[j + 1])
	{
		i = 1;
		while (line[j][i + 1])
		{
			if (line[j][i] == '0')
			{
				if (line[j - 1][i] == ' ' || line[j + 1][i] == ' ' ||
					line[j][i - 1] == ' ' || line[j][i + 1] == ' ')
				{
					ft_putstr_fd("Error: Invalid map\n", 2);
					free_structs(game);
					exit(EXIT_FAILURE);			
				}
			}
			i++;
		}
		j++;
	}
}

void	check_if_validate_map_line(char *line, t_map_data *map_data)
{
	int	j;

//check current line
	if (line[0] != '1' && line[0] != ' ')
		return (message_error_return_1("Error: Invalid map\n"));
	j = ft_strlen(line) - 1;
	if (line[j] != '1')
		return (message_error_return_1("Error: Invalid map\n"));


//check char validity
	if (is_line_valid(line) == 0 || is_full_whitespaces(line) == 1)
		return (message_error_return_1("Error: Invalid map\n"));



//check if only one direction/character
	if (is_direction_valid(line, map_data) == 0)
		return (message_error_return_1("Error: Invalid map\n"));
	return (0);
}