/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/07 09:16:52 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	free_map(t_map *map)
// {
// 	int i;

// 	if (!map)
// 		return;
// 	if (map->map)
// 	{
// 		i = 0;
// 		while (i < map->height)
// 		{
// 			free(map->map[i]);
// 			i++;
// 		}
// 		free(map->map);
// 	}
// 	if (map->northern_texture)
// 		mlx_delete_texture(map->northern_texture);
// 	if (map->southern_texture)
// 		mlx_delete_texture(map->southern_texture);
// 	if (map->western_texture)
// 		mlx_delete_texture(map->western_texture);
// 	if (map->eastern_texture)
// 		mlx_delete_texture(map->eastern_texture);
// 	free(map);
// }

int	main(int argc, char **argv)
{

	int	fd;
	t_map *map;
	char buffer[4096];
	ssize_t bytesRead;

	map = NULL;

	if (argc != 2 || manage_cub_extension(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY); 
	if (fd < 0 || fd > 1023)
	{
		ft_putstr_fd("The file does not exist\n", 2);
		return (1);
	}
	while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) 
    	ft_putstr_fd(buffer, 1);
	if (bytesRead < 0) 
    	ft_putstr_fd("Error reading file\n", 2);
	//get_next_line(fd);
	//! Penser a free ma structure t_map !
	// free_map(map);
	close(fd);
	printf("\033[32mEnd of program 😊\033[0m\n");
	return (0);
}
