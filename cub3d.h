/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:41:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/06 12:53:35 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H


/*
* Includes
*/

#include "MLX42/include/MLX42/MLX42.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <unistd.h>
#include <stdio.h>

/*
* Struct
*/

typedef struct s_map {
    char	**map;
    int		weight;
    int     height;
	int		floor_color;
	int		ceiling_color;

	mlx_texture_t *northern_texture;
	mlx_texture_t *southern_texture;
	mlx_texture_t *western_texture;
	mlx_texture_t *eastern_texture;
    
} t_map;



/*
* Utils
*/

int     ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);




#endif