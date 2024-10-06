/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:47:39 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/06 15:35:04 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_ceiling(mlx_image_t *image, int x, int up_wall)
{
	int	y;

	y = 0;
	while (y < up_wall && y < WINDOWS_HEIGHT)
	{	
		mlx_put_pixel(image, x, y, 0x00007FFF);
		y++;
	}
}


/*static uint32_t	get_pixel_color_from_image(mlx_image_t *player_image, uint32_t x_image, uint32_t y_image)
{
	uint32_t	color;
	int		pixel_index;
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;

//	printf ("x_image : %d\n", x_image);
//	printf ("y_image : %d\n", y_image);

	color = 0;
	if (x_image >=0 && x_image < player_image->width && y_image >=0 && y_image < player_image->height)
	{
		pixel_index = (y_image * player_image->width + x_image) * 4;
		red = player_image->pixels[pixel_index]; // 8 bits pour le rouge
		green = player_image->pixels[pixel_index + 1]; // 8 bits pour le vert
		blue = player_image->pixels[pixel_index + 2]; // 8 bits pour le bleu
		alpha = player_image->pixels[pixel_index + 3]; // 8 bits pour l'opacite

		color = (red << 24) | (green << 16) | (blue << 8) | alpha;
//		printf("Couleur RGBA combinée en hex: %#010x\n\n", color);
//		printf("Couleur RGBA combinée en hex: %x\n", color);

	}
	return (color);

}

static void	draw_wall_section(t_game *game, mlx_image_t *image, int x,
		int up_wall, int down_wall)
{
//	float x;
	float y;
	mlx_image_t	*wall_image;
	uint32_t	color;

	(void)image;

//	float	x_ratio;
	float	y_ratio;
	uint32_t x_image;
	uint32_t y_image;

//	x_ratio = 1;
	y_ratio = 1;

	x_image = x;
//	if ()
	{
		wall_image = mlx_texture_to_image(game->mlx, game->texture->north_texture);
		if (!wall_image)
			exit(EXIT_FAILURE);
	}
	if ()
	{
		wall_image = mlx_texture_to_image(game->mlx, game->texture->east_texture);
		if (!wall_image)
			exit(EXIT_FAILURE);
	}
	if ()
	{
		wall_image = mlx_texture_to_image(game->mlx, game->texture->south_texture);
		if (!wall_image)
			exit(EXIT_FAILURE);
	}
	if ()
	{
		wall_image = mlx_texture_to_image(game->mlx, game->texture->west_texture);
		if (!wall_image)
			exit(EXIT_FAILURE);
	}

	int square_height = up_wall - down_wall;

//	x_ratio = wall_image->width / square_width;
	y_ratio = wall_image->height / square_height;


//	x = game->player->player_pos_x * square_width;
//	while (x < square_width * (game->player->player_pos_x + 1))
//	{
		y_image = down_wall;
		y = game->player->player_pos_y * square_height;
		while (y < square_height * (up_wall + 1))
		{
			color = get_pixel_color_from_image(wall_image, x_image, y_image);
			mlx_put_pixel(game->texture->image, x, y, color);
			y++;
			y_image += y_ratio;
		}
//		x++;
//		x_image += x_ratio;
//	}
}*/





static void	draw_wall_section(mlx_image_t *image, int x,
		int up_wall, int down_wall, int color)
{
	int	y;

	y = up_wall;
	while (y < down_wall)
	{
		mlx_put_pixel(image, x, y, color); // couleur du mur
		y++;
	}
}

static void	draw_floor(mlx_image_t *image, int x, int down_wall)
{
	int	y;

	if (down_wall < 0) 
		down_wall = 0;
    if (down_wall >= (int)image->height)
		return;
	y = down_wall;
	while (y < (int)image->height && y < WINDOWS_HEIGHT)
	{
		mlx_put_pixel(image, x, y, 0xAFAFAFFF); // couleur du sol
		y++;
	}
}

void	draw_elements(mlx_image_t *image,
	int x, float wall_height, t_game *game)
{
	int		color;
	int		up_wall;
	int		down_wall;

	up_wall = ((int)image->height / 2.0) - wall_height / 2
		+ (float)(image->height / 2.0) * game->player->pitch;
	down_wall = ((int)image->height / 2.0) + wall_height / 2
		+ (float)(image->height / 2.0) * game->player->pitch;
	if (up_wall < 0)
		up_wall = 0;
	if (down_wall >= (int)image->height)
		down_wall = image->height - 1;
	color = 0xFFB400B4;
	draw_ceiling(image, x, up_wall);
	draw_wall_section(image, x, up_wall, down_wall, color);
//	draw_wall_section(game, image, x, up_wall, down_wall);//envoyer orientation du mur en paramètre
	draw_floor(image, x, down_wall);
}
