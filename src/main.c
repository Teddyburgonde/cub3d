/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/08 09:35:21 by tebandam         ###   ########.fr       */
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



void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	long int	size_alloc;

	size_alloc = nmemb * size;
	if (size_alloc < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr)
		ft_memset(ptr, '\0', nmemb * size);
	return (ptr);
}


int	main(int argc, char **argv)
{
	int	fd;
	t_map *map;
	char *line;
	int	check_no;
	int check_so;
	int	check_we;
	int	check_ea;
	int	check_f;
	int	check_c;
	
	check_no = 0;
	check_so = 0;
	check_we = 0;
	check_ea = 0;
	check_f = 0;
	check_c = 0;
	
	map = NULL;
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Memory allocation error\n", 2);
		return (1);
	}
	if (argc != 2 || manage_cub_extension(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY); 
	if (fd < 0 || fd > 1023)
	{
		ft_putstr_fd("The file does not exist\n", 2);
		//? free_map(map);
		return (1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Error read\n", 2);
		return (1);
	}
	while (line)
	{
		if (ft_strncmp(line, "NO", 2) == 0)
		{
			check_no++;
		}
		else if (ft_strncmp(line, "SO", 2) == 0)
		{
			check_so++;
		}
		else if (ft_strncmp(line, "WE", 2) == 0)
		{
			check_we++;
		}
		else if (ft_strncmp(line, "EA", 2) == 0)
		{
			check_ea++;
		}
		else if (ft_strncmp(line, "F", 1) == 0)
		{
			check_f++;
		}
		else if (ft_strncmp(line, "C", 1) == 0)
		{
			check_c++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (check_no != 1 || check_so != 1 || check_we != 1 || check_ea != 1 || check_f != 1 || check_c != 1)
		ft_putstr_fd("Error parsing\n", 2);
	else
	 	ft_putstr_fd("Parsing ok all elements exist 😊\n", 1);
	//! Penser a free ma structure t_map !
	//? free_map(map);
	close(fd);
	printf("\033[32mEnd of program 😊\033[0m\n");
	return (0);
}
