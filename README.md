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


