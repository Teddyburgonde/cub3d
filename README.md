# README.md

## Introduction
Ce projet est une application qui charge et analyse un fichier de configuration de type `.cub` afin de rendre un environnement graphique. Il utilise des bibliothèques graphiques et met en place des fonctions de parsing avancées pour vérifier et configurer les textures, couleurs, ainsi que la carte du jeu.

## Fonctionnalités principales
- Lecture et validation d'un fichier de configuration.
- Parsing des différentes sections du fichier (`textures`, `couleurs`, `carte`).
- Allocation dynamique de mémoire pour la structure de données du jeu.
- Vérification et chargement des textures et couleurs.
- Validation de la carte avec gestion des erreurs (position du joueur, fermeture des zones).
- Rendu graphique et gestion de l'affichage.

## Prérequis
Avant de compiler et d’exécuter ce projet, vous devez avoir :
- Un compilateur compatible avec le C (ex. : `gcc` ou `clang`).
- La bibliothèque graphique `MLX` (MiniLibX).
- Une gestion de la mémoire fiable (vérification avec `valgrind` recommandée).
- Les fonctions auxiliaires suivantes :
  - `ft_strncmp`, `ft_strdup`, `ft_split`, `ft_strlen`, `ft_substr`, `ft_atoi`, `get_next_line`.

## Installation et compilation
1. Clonez le projet :
   ```bash
   git clone <url-du-repo>
   ```
2. Compilez le projet :
   ```bash
   make
   ```
3. Exécutez le programme :
   ```bash
   ./program <fichier.cub>
   ```

## Structure du projet
Voici un aperçu des fonctions et modules principaux du projet :

### 1. `main.c`
- Point d'entrée du programme.
- Initialise les structures et lance les différentes étapes du parsing et du rendu.

### 2. Parsing des arguments
**Fonction :** `parsing_arguments`
- Vérifie le nombre d'arguments.
- Valide l'extension `.cub` du fichier.

### 3. Lecture du fichier
**Fonction :** `get_file_content`
- Ouvre le fichier et le lit ligne par ligne.
- Stocke le contenu dans un tableau de chaînes de caractères.

### 4. Parsing des textures et couleurs
**Fonctions :** `parsing_file_textures`, `parsing_file_colors`
- Analyse les lignes correspondant aux chemins des textures (`NO`, `SO`, `WE`, `EA`).
- Charge les textures avec `mlx_load_png`.
- Analyse et convertit les couleurs (éléments `F` et `C`).

### 5. Validation de la carte
**Fonction :** `parsing_map`
- Vérifie la validité de la carte (éléments valides, position du joueur, fermeture des zones).
- Utilise une technique de flood-fill pour s'assurer que toutes les zones sont bien délimiteées.

### 6. Gestion des erreurs
- Erreurs gérées :
  - Nombre incorrect d'arguments.
  - Extension du fichier invalide.
  - Fichier inaccessible ou vide.
  - Manque ou redondance de textures/couleurs.
  - Erreurs de parsing du contenu du fichier.

## Utilisation
1. Préparez un fichier `.cub` contenant les informations suivantes :
   - Chemins des textures (ex. : `NO ./path/to/north_texture.png`).
   - Couleurs pour le sol et le plafond (ex. : `F 220,100,50`).
   - Carte du jeu.

2. Lancez le programme avec le fichier en argument :
   ```bash
   ./program map.cub
   ```

3. Si le fichier est valide, le rendu graphique sera affiché. Sinon, un message d'erreur apparaîtra.

## Exemple de fichier `.cub`
```text
NO ./textures/north_texture.png
SO ./textures/south_texture.png
WE ./textures/west_texture.png
EA ./textures/east_texture.png
F 220,100,50
C 255,255,255

1111111111
1000000001
1011101111
1000000001
1111111111
```
-------------------------------------------

# README.md

## Introduction

Ce projet permet de charger et analyser un fichier `.cub` pour afficher un environnement graphique. Voici les étapes à suivre pour que votre ami puisse l'utiliser correctement.

## Prérequis

Avant de commencer, assurez-vous que les points suivants sont remplis :

1. Avoir un compilateur C installé (`gcc` ou `clang`).
2. Disposer de la bibliothèque graphique `MLX`.
3. Les fonctions auxiliaires suivantes doivent être disponibles :
   - `ft_strncmp`, `ft_strdup`, `ft_split`, `ft_strlen`, `ft_substr`, `ft_atoi`, `get_next_line`.

---

## Étapes à suivre pour utiliser le projet

### 1. Cloner le projet

```bash
git clone <url-du-repo>
```

### 2. Compiler le projet

```bash
make
```

### 3. Préparer un fichier `.cub`

Le fichier `.cub` doit contenir les éléments suivants :

- Les chemins vers les textures.
- Les couleurs pour le sol (`F`) et le plafond (`C`).
- Une carte correctement fermée.

Exemple de fichier `.cub` :

```text
NO ./textures/north_texture.png
SO ./textures/south_texture.png
WE ./textures/west_texture.png
EA ./textures/east_texture.png
F 220,100,50
C 255,255,255

1111111111
1000000001
1011101111
1000000001
1111111111
```

### 4. Lancer le programme avec le fichier `.cub`

```bash
./program map.cub
```

Si le fichier est valide, le programme affichera le rendu graphique. En cas d'erreur, un message d’erreur apparaîtra.

---

## Étapes techniques dans le code

Voici les principales étapes effectuées par le programme lors de son exécution :

### 1. Parsing des arguments

**Fonction :** `parsing_arguments`

- Vérifie que le fichier est bien passé en argument.
- Valide l’extension `.cub`.

Code correspondant :

```c
void parsing_arguments(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putstr_fd("Error: Wrong argument number\n", 2);
        exit(EXIT_FAILURE);
    }
    if (manage_cub_extension(argv) == 1)
    {
        ft_putstr_fd("Error: Wrong extension map\n", 2);
        exit(EXIT_FAILURE);
    }
}
```

### 2. Ouverture et lecture du fichier

**Fonction :** `get_file_content`

- Ouvre le fichier et le lit ligne par ligne.
- Stocke le contenu dans un tableau de chaînes de caractères.

Code correspondant :

```c
char **get_file_content(int fd)
{
    char **file_content;
    char *line;

    line = get_next_line(fd);
    if (!line)
        exit_when_file_is_empty(fd);

    file_content = get_lines(fd, line);
    if (fd > 2)
        close(fd);
    return (file_content);
}
```

### 3. Parsing des textures

**Fonction :** `parsing_file_textures`

- Analyse les lignes du fichier contenant les chemins des textures.
- Met à jour l’index de début de la carte.

Code correspondant :

```c
void parsing_file_textures(t_game *game)
{
    int i;
    char *tmp;
    t_counter_parameter counter_parameter;

    i = 0;
    ft_memset(&counter_parameter, 0, sizeof(t_counter_parameter));
    while (game->data->file_content[i])
    {
        tmp = skip_first_spaces(game->data->file_content[i]);
        if (count_parameters(tmp, &counter_parameter) == 0)
            break;
        i++;
    }
    game->data->begin_map_index = i;
    check_if_missing_element(counter_parameter, game);
}
```

### 4. Validation de la carte

**Fonction :** `parsing_map`

- Vérifie la validité de la carte.
- Utilise une technique de flood-fill pour s'assurer que toutes les zones sont correctement fermées.

Code correspondant :

```c
void parsing_map(t_game *game)
{
    skip_first_empty_lines(&game->data->map);
    check_map_validity(game);
}
```

### 5. Rendu graphique

**Fonction :** `render_graphics`

- Initialise l'affichage et affiche la carte avec les textures chargées.

### 6. Libération de la mémoire

**Fonction :** `free_structs`

- Libère toutes les structures de données allouées dynamiquement.

---

## Gestion des erreurs

Le programme gère différentes erreurs, telles que :

- Nombre incorrect d'arguments.
- Extension de fichier invalide.
- Fichier inaccessible ou vide.
- Erreurs dans les chemins de textures ou les couleurs.
- Carte non valide (ex. : zones non fermées).

Exemple de message d’erreur :

```text
Error: Wrong argument number
```

---


