## Plan pour cub3d :

**Petite instalation**

```c
- Creation du Makefile.  ✅
- Installation de la MLX42. ✅
- Création du .h ✅
- Initialiser les variables des structures ✅
- Importer get_next_line ✅
```

## Parsing

```c
Je vous conseil de commencer par ouvrir mon fichier sur excalidraw :
parsing_explain_code.excalidraw
```

**Parsing arguments**

```c
- Nombre d’arguments invalide : moins de 2 arguments ou plus de 3. ✅ 
- Le fichier .cub n'existe pas. ✅
- L'extention du fichier .cub est t'il valide ? ✅ 
```
**Parsing map**

```c
- Lire la map ✅
- trouver comment on peut regarder la map en bas sans les elements den haut ✅
- N S E W doit etre dedans  ✅
- regarder si la map est bien fermer par des 1 ✅
- trouver le F ✅
- split et stock dans tab ✅
- if (tab[1] != NULL) ✅
- parcourir le tableau de tableau  ✅
- si les 3 premiers element sont un chiffre et element 4 et une virgule et si les 3 elements
sont des chiffres puis virgule et apres un chifre ( tout est entre 0 a 255) ✅
- chercher la fonction MLX42 qui permet de transformer le RGB ✅
- Appliquer la fonction qui permet de transformer le RGB ✅
```

## Raycasting

Je vous conseil de commencer par ouvrir mon fichier sur excalidraw :

```c
raycasting_explain_code.excalidraw
```

**Liste des fonctions importants**

```c
bool mlx_is_key_down(mlx_t* mlx, keys_t key);
```
- Description : Vérifie si une touche du clavier est enfoncée ou non.
- Paramètres : mlx Le pointeur vers l'instance MLX.
               key Le code de la touche à vérifier (utilisez MLX_KEY_...).
- return : true si la touche est enfoncée, sinon false.



**Définition du Raycasting**

```c
Le raycasting est une technique de rendu permettant de créer une perspective 3D dans une carte 2D.
```
**Entrainement sur des mini bases**

**ETAPE 1 : Afficher une fenêtre** ✅

```c
mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize); // mlx_init permet de cree la fenêtre.
void mlx_loop(mlx_t* mlx); // mlx_loop permet d'afficher la fenêtre.
void mlx_close_window(mlx_t* mlx); // mlx_close_window permet de fermer la fenêtre.
void mlx_terminate(mlx_t* mlx); // mlx_terminate permet de fermer proprement la fenêtre
```

**ETAPE 2 : Afficher une image** ✅

Vous devez d'abord transformer la texture en image et la stoker dans une variable image.
```c
mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture);
```

Puis pour afficher l'image :

```c
int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x,int32_t y);
```

**Entrainement sur l'agorithme du raycasting** 

https://austinhenley.com/blog/raycasting.html

Sur ce site vous trouverez un algorithme qui vous permettra d'afficher les murs.
Il est ecris en javascript donc je l'ai traduis en C. 
Ici on vas faire seulement le step 1.
ps : vous aurez des murs moches mais c'est un bon entrainement pour
apres bien comprendre le "vrai" algorithme.

```c

/*
La fonction cast_ray calcule la distance et la hauteur d'un mur 
en projetant un rayon à partir de la position du joueur
dans une direction spécifiée.
Des que le rayon touche un mur , 
la fonction ajuste la hauteur du mur en fonction de 
la distance détectée.
*/

t_ray_result cast_ray(float rayAngle, t_game *game)
{
	t_ray_result	ray_result;

	// initialisation des variables
	float x;
	float y;
	float dx;
	float dy;
	int	i;
	int map_x;
	int	map_y;
	
	x = game->player->player_pos_x;
	y = game->player->player_pos_y;
	dx = cos(rayAngle);
    dy = sin(rayAngle);
	i = 0;
	while (i < 400) // la boucle continue tant qu'il ne trouve pas de mur
	{
		map_x = (int)floor(x);
		map_y = (int)floor(y);
		if (map_x >= 0 && map_y >= 0  && game->data->map[map_y][map_x] == '1')
    		break; // il a trouver un mur
		// x += dx * 0.1f;
        // y += dy * 0.1f;
		x += dx * 0.05f;
		y += dy * 0.05f;
		i++;
	}
	
	// Calcul de la distance et de la hauteur du mur
	ray_result.distance = sqrtf((x - game->player->player_pos_x) * (x - game->player->player_pos_x) + 
		(y - game->player->player_pos_y) * (y - game->player->player_pos_y));
	ray_result.wall_height = (300.0f / ray_result.distance);
	return (ray_result);
}

```

```c

// Function pour dessiner les murs en fonction de la distance parcourue par les rayons
void	 draw_wall(mlx_image_t* image, int j, float wall_height, float slice_width)
{
	int	y_position;
	int		color;
	
	color = 0xFFB400B4;

	for (int i = 0; i < (int)wall_height; i++)
	{
		// Calcul de la position en Y
		y_position = (int)floor(300 - wall_height / 2 + i);
		if (y_position >= 0 && y_position < (int)image->height) // Vérification que y_position est dans les limites de l'écran
        {
			// Dessine le slice verticale(petite bande) avec la larguer donnée
			for(int k = 0; k < (int)slice_width; k++)
			{
				if (j * slice_width + k < image->width)  // Vérification des limites X
                {
					mlx_put_pixel(image, j * slice_width + k, y_position, color);
				}
			}
		}	
	}
}
```

```C

void	raycast(void *param)
{
	int	rays;
	int	screen_width;
	int	slice_width;
	float	angle_step;
	float ray_angle;
	t_ray_result	ray_result;
	t_game *game;


	game = (t_game*)param;
	rays = 200;
	screen_width = 800;
	slice_width = screen_width / rays;
	angle_step = game->player->fov / rays;

	// murs 
	for (int i = 0; i < rays; i++)
	{
		ray_angle = game->player->angle - (game->player->fov / 2.0f) + i * angle_step;
		ray_result = cast_ray(ray_angle, game);
		draw_wall(game->texture->image, i, ray_result.wall_height, slice_width);
	}
}
```

le main 

```c

game->mlx = mlx_init(1040, 720, "cub3d", false); // mlx_init permet de cree la fenêtre.
	if (!game->mlx)
		return (EXIT_FAILURE);
	//game->texture->image = mlx_texture_to_image(game->mlx, game->texture->north_texture); // transformer un texture en image
	game->texture->image = mlx_new_image(game->mlx, 1040, 720);
	if (mlx_image_to_window(game->mlx, game->texture->image, 0, 0) < 0) // affiche l'image 
		return (EXIT_FAILURE);
	mlx_loop_hook(game->mlx, raycast, (void*)game);
	mlx_loop(game->mlx); // mlx_loop permet d'afficher la fenêtre.
```

**S'entrainer a bouger la vue du player**


```c

void key_press(mlx_key_data_t keydata, void* param)
{
    t_game *game = (t_game*)param;

    // On détecte les flèches directionnelles
    if (keydata.key == MLX_KEY_LEFT)
        game->x -= 10;  // Déplacer vers la gauche
    else if (keydata.key == MLX_KEY_RIGHT)
        game->x += 10;  // Déplacer vers la droite
    else if (keydata.key == MLX_KEY_UP)
        game->y -= 10;  // Déplacer vers le haut
    else if (keydata.key == MLX_KEY_DOWN)
        game->y += 10;  // Déplacer vers le bas
}
```

```c
int main(void)
{
    mlx_t* mlx = mlx_init();
    mlx_window_t* window = mlx_new_window(mlx, 800, 600, "Move Character");

    t_game game = {400, 300};  // Position initiale du personnage

    mlx_key_hook(mlx, key_press, &game);

    mlx_loop(mlx);
    return 0;
}
```

**Implementation du bon algorithme de cub3D** ⚠️


✅  ❌

🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧



Sources : 

https://austinhenley.com/blog/raycasting.html

https://lodev.org/cgtutor/raycasting.html



/**
 * Détruit l'objet curseur donné.
 * 
 * @param[in] cursor L'objet curseur à détruire.
 */
void mlx_destroy_cursor(mlx_win_cursor_t* cursor);


Pour la fermeture de la fenêtre.
typedef void (*mlx_closefunc)(void* param);




void mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param);


mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture);


Définit/met un pixel sur une image.
void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color);


Crée et alloue un nouveau buffer d'image.
mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height);

int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y);


Fonction de callback utilisée pour gérer les pressions de touches.
