/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/09 01:33:16 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_map	map;

	if (parsing_arguments(argc, argv) == 1)
		return (1);
	map.fd = open(argv[1], O_DIRECTORY);
	if (map.fd > 0)
		return (message_error_for_parsing_args("Is a directory\n", 1));
	map.fd = open(argv[1], O_RDONLY);
	if (map.fd < 0 || map.fd > 1023)
		return (message_error_for_parsing_args("The file does not exist\n", 1));

	// char *line;
	// int	check_no;
	// int check_so;
	// int	check_we;
	// int	check_ea;
	// int	check_f;
	// int	check_c;
	
	// check_no = 0;
	// check_so = 0;
	// check_we = 0;
	// check_ea = 0;
	// check_f = 0;
	// check_c = 0;
	// line = get_next_line(fd);
	// if (!line)
	// {
	// 	ft_putstr_fd("Error read\n", 2);
	// 	return (1);
	// }
	// while (line)
	// {
	// 	if (ft_strncmp(line, "NO", 2) == 0)
	// 		check_no++;
	// 	else if (ft_strncmp(line, "SO", 2) == 0)
	// 		check_so++;
	// 	else if (ft_strncmp(line, "WE", 2) == 0)
	// 		check_we++;
	// 	else if (ft_strncmp(line, "EA", 2) == 0)
	// 		check_ea++;
	// 	else if (ft_strncmp(line, "F", 1) == 0)
	// 		check_f++;
	// 	else if (ft_strncmp(line, "C", 1) == 0)
	// 		check_c++;
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	// if (check_no != 1 || check_so != 1 || check_we != 1 || check_ea != 1 || check_f != 1 || check_c != 1)
	// 	ft_putstr_fd("Error parsing\n", 2);
	// else
	//  	ft_putstr_fd("Parsing ok all elements exist 😊\n", 1);
	// //! Penser a free ma structure t_map !
	// //? free_map(map);
	// close(fd);
	printf("\033[32mEnd of program 😊\033[0m\n");
	return (0);
}
