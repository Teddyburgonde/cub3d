## Plan pour cub3d :

**Petite instalation**

- Creation du Makefile.  ✅
- Installation de la MLX42. ✅
- Création du .h ✅
- Initialiser les variables des structures ✅
- Importer get_next_line ✅



## Parsing

**Parsing arguments**

- Nombre d’arguments invalide : moins de 2 arguments ou plus de 3. ✅ 
- Le fichier .cub n'existe pas. ✅
- L'extention du fichier .cub est t'il valide ? ✅

**Parsing map**

- Lire la map ❌



**Problems**

- Je ne free pas ma structure t_map. ❌
- Je n'arrive pas a include MLX42_Int_h pour mlx_delete_texture. ❌


✅  ❌


🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧

Tous les trucs tricky auxquels il faut penser pour le parsing de tout sauf la map :

    : Il manque qqe chose (R, NO, SO, S…)
    : Deux fois la même chose (deux R, deux NO..)
    : Résolution avec des int plus grands que int max
    : Résolution avec une virgule ou un autre caractère dedans
    : Résolution avec 3 chiffres, ou un seul, ou un 0
    : F ou C avec un chiffre qui manque, ou un chiffre en trop
    : F ou C avec une virgule en moins ou une virgule en trop
    : F ou C avec un int supérieur à int max : doit renvoyer une erreur
    : F ou C avec un chiffre supérieur à 255
    : Un identifiant mauvais genre (X au lieu de R, ou E au lieu de EA)

Tous les trucs tricky auxquels il faut penser pour le parsing de la map :

    : Une ligne vide dans la map : “Sauf pour la map elle-même, les informations de chaque élément peuvent être séparées par un ou plusieurs espace(s)"
    : Un caractère incorrect dans la map, genre un 4
    : Une map ouverte
    : “Les espaces sont une partie valable de la carte, c’est à vous de les gérer correctement” : pour moi les espaces vides sont des murs
    : La map est avant un autre élément
    : Il n’y a pas de map
    : Pas de joueur ou plusieurs joueurs




**Free structure**
```c

void	unleak(t_cub *cb)
{
	if (!cb)
		return ;
	if (cb->map.file)
		ft_free_map(cb->map.file, ft_maplen(cb->map.file));
	if (cb->map.map)
		ft_free_map(cb->map.map, ft_maplen(cb->map.map));
	if (cb->map.param)
		ft_free_map(cb->map.param, 7);
	if (cb->map.par)
		free(cb->map.par);
	if (cb->map.north_texture)
		mlx_delete_texture(cb->map.north_texture);
	if (cb->map.west_texture)
		mlx_delete_texture(cb->map.west_texture);
	if (cb->map.south_texture)
		mlx_delete_texture(cb->map.south_texture);
	if (cb->map.east_texture)
		mlx_delete_texture(cb->map.east_texture);
	if (cb->map.bozo_texture)
		mlx_delete_texture(cb->map.bozo_texture);
}
```


```c
void	error(int type, char *arg)
{
	ft_putstr_fd("Error\n", 2);
	if (type == MLX)
		ft_putstr_fd("cub3d: Impossible to load mlx.", 2);
	if (type == ARGS)
	{
		ft_putstr_fd("cub3d: Invalid number of arguments -> ", 2);
		ft_putstr_fd("usage : ./cub3d [map.cub]\n", 2);
	}
	else if (type == EXTENSION)
	{
		ft_putstr_fd("cub3d: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": Invalid map format, need [map.cub]\n", 2);
	}
	else if (type == DIRECTORY)
	{
		ft_putstr_fd("cub3d: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": is a directory\n", 2);
	}
	else
		error_bis(type, arg);
}
```

```c
void	set_param(t_cub *cb)
{
	cb->map.param = ft_calloc(sizeof(char *), 7);
	cb->map.param[0] = ft_strdup("NO");
	cb->map.param[1] = ft_strdup("SO");
	cb->map.param[2] = ft_strdup("EA");
	cb->map.param[3] = ft_strdup("WE");
	cb->map.param[4] = ft_strdup("F");
	cb->map.param[5] = ft_strdup("C");
	if (!cb->map.param[0] || !cb->map.param[1] || !cb->map.param[2]
		|| !cb->map.param[3] || !cb->map.param[4] || !cb->map.param[5])
		error(cb, MALLOC_ERROR);
	cb->map.par = ft_calloc(sizeof(int), 7);
	if (!cb->map.par)
		error(cb, MALLOC_ERROR);
}
```
✅ ❌




NO ?
SO ?
WE ?
EA ?

- trouver le F ✅
- split et stock dans tab ✅
- if (tab[1] != NULL) ✅
- parcourir le tableau de tableau  ✅
- si les 3 premiers element sont un chiffre et element 4 et une virgule et si les 3 elements
sont des chiffres puis virgule et apres un chifre ( tout est entre 0 a 255) ✅
- chercher la fonction MLX42 qui permet de transformer le RGB ✅
- Appliquer la fonction qui permet de transformer le RGB ✅



- trouver comment on peut regarder la map en bas sans les elements den haut ✅
- regarder si la map est bien fermer par des 1
- N S E W doit etre dedans 


- regarder si la map est bien fermer par des 1
- N S E W doit etre dedans 

Sources : 

https://harm-smits.github.io/42docs/projects/cub3d

https://github.com/iciamyplant/Cub3d-Linux

https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf
