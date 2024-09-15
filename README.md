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

**Définition du Raycasting**

```c
Le raycasting est une technique de rendu permettant de créer une perspective 3D dans une carte 2D.
```

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

**ETAPE 3 : Faire bouger l'image** ❌






✅  ❌



🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧


Sources : 

https://austinhenley.com/blog/raycasting.html

https://lodev.org/cgtutor/raycasting.html


