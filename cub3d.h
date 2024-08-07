/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:41:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/09 02:49:46 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
* Includes
*/

# include "MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <fcntl.h> 
# include "get_next_line/get_next_line.h" 

/*
* Struct
*/

typedef struct s_texture
{
	mlx_texture_t	*northern_texture;
	mlx_texture_t	*southern_texture;
	mlx_texture_t	*western_texture;
	mlx_texture_t	*eastern_texture;
}	t_texture;


typedef struct s_map
{
	int				fd;
	char			**map;
	int				weight;
	int				height;
	int				floor_color;
	int				ceiling_color;
	t_texture		textures;
}	t_map;

/*
* Parsing arguments
*/

int		manage_cub_extension(char **argv);
int		parsing_arguments(int argc, char **argv);


/*
* Check and open file
*/

int check_and_open_file(t_map *map, char **argv);


/*
* Read map 
*/

int	read_map(t_map *map, char **line);

/*
* Utils
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr_fd(char *s, int fd);

/*
* Initialization
*/

void	initialization_all_struct(t_map *map);


/*
* Error
*/

int	message_error_for_parsing_args(char *message, int ret_value);

/*
* Allocation 
*/
// void	*ft_calloc(size_t nmemb, size_t size);

#endif