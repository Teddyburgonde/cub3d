
#include "../cub3d.h"

void	fill_grid_square(t_game *game, int i, int j, int square_width, int color)
{
	int x;
	int y;

	x = j * square_width;
	while (x < square_width * (j + 1))
	{
		y = i * square_width;
		while (y < square_width * (i + 1))
		{
			mlx_put_pixel(game->texture->image, x, y, color);
			y++;
		}
		x++;
	}
}


uint32_t	get_pixel_color_from_image(mlx_image_t *player_image, uint32_t x_image, uint32_t y_image)
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



void	put_player_on_map(t_game *game, int square_width, int square_height)
{
	float x;
	float y;
	mlx_image_t	*player_orientation_image;
//	mlx_image_t	*player_position_image;
	uint32_t	color;


	float	x_ratio;
	float	y_ratio;
	uint32_t x_image;
	uint32_t y_image;

	x_ratio = 1;
	y_ratio = 1;

	x_image = 0;
//	printf("game->player->angle : %f\n", game->player->angle);
	if ((game->player->angle > 7 * M_PI / 4 && \
	game->player->angle < 2 * M_PI) || \
	(game->player->angle >= 0 && \
	game->player->angle <= M_PI / 4 ))
	{
//		printf("orientation Nord\n");
		player_orientation_image = mlx_texture_to_image(game->mlx, game->texture->player_image_E);
		if (!player_orientation_image)
			exit(EXIT_FAILURE);
	}
	if (game->player->angle > M_PI / 4 && \
	game->player->angle <= 3 * M_PI / 4 )
	{
//		printf("orientation Est\n");
		player_orientation_image = mlx_texture_to_image(game->mlx, game->texture->player_image_S);
		if (!player_orientation_image)
			exit(EXIT_FAILURE);
	}
	if (game->player->angle > 3 * M_PI / 4 && \
	game->player->angle <= 5 * M_PI / 4 )
	{
//		printf("orientation Sud\n");
		player_orientation_image = mlx_texture_to_image(game->mlx, game->texture->player_image_W);
		if (!player_orientation_image)
			exit(EXIT_FAILURE);
	}
	if (game->player->angle > 5 * M_PI / 4 && \
	game->player->angle <= 7 * M_PI / 4 )
	{
//		printf("orientation Ouest\n");
		player_orientation_image = mlx_texture_to_image(game->mlx, game->texture->player_image_N);
		if (!player_orientation_image)
			exit(EXIT_FAILURE);
	}

//	if (mlx_image_to_window(game->mlx, game->texture->player_position_image, game->player->player_pos_x, game->player->player_pos_y) < 0) // affiche la position du player
//		exit(1);

	x_ratio = player_orientation_image->width / square_width;
	y_ratio = player_orientation_image->height / square_height;


//	x = game->player->player_pos_x * square_width;
	x = 0;
//	while (x < square_width * (game->player->player_pos_x + 1))
	while (x < square_width)
	{
		y_image = 0;
//		y = game->player->player_pos_y * square_height;
		y = 0;
//		while (y < square_height * (game->player->player_pos_y + 1))
		while (y < square_height)
		{
			color = get_pixel_color_from_image(player_orientation_image, x_image, y_image);
//			color = get_pixel_color_from_image(player_image, x, y, 1 / 2, 1 / 2);
//			printf("Couleur RGBA combinée en hex: %x\n", color);
			mlx_put_pixel(game->texture->image, x, y, color);
			y++;
			y_image += y_ratio;
		}
		x++;
		x_image += x_ratio;
	}
}


void    display_minimap(t_game *game)
{
	int	i;
	int	j;
	int			minimap_width;
	int			minimap_height;
	int			square_width;
	int			square_height;

	i = 0;
	minimap_width = WINDOWS_WIDTH / 5;
//	printf("minimap_width %d\n", minimap_width);
	minimap_height = WINDOWS_HEIGHT / 5;
//	printf("minimap_height %d\n", minimap_height);
	square_width = minimap_width / game->data->nb_columns;
//	printf("square_width %d\n", square_width);
	square_height = minimap_height / game->data->nb_lines;
//	printf("square_height %d\n", square_height);

	while (game->data->map[i])
	{
		j = 0;
		while (game->data->map[i][j])
		{
//			if (game->data->map[i][j] == '0')
			fill_grid_square(game, i, j, square_width, 0xAFAFAFFF);
			if (game->data->map[i][j] == '1')
				fill_grid_square(game, i, j, square_width, 0xFFB400B4);
			j++;
		}
		i++;
	}
	put_player_on_map(game, square_width, square_height);
}