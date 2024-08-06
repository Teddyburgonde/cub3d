## Plan pour cub3d :

**Petite instalation**

- Creation du Makefile.  ✅
- Installation de la MLX42. ✅

## Parsing

**Parsing arguments**

- Nombre d’arguments invalide : moins de 2 arguments ou plus de 3. ✅ 
- Le fichier .cub n'existe pas. ✅
- Le .cub est un directory




Etape 3 : Creation d'une fonction pour gerer le .cub ✅ 







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


✅ ❌




NO ?
SO ?
WE ?
EA ?


Sources : 

https://harm-smits.github.io/42docs/projects/cub3d

https://github.com/iciamyplant/Cub3d-Linux

https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf
