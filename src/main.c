/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/05 15:55:40 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int manage_cub_extension(char **argv)
{
    int i;

    i = 0;
    while (argv[1][i])
        i++;
    i--;
    if (i >= 4 && ft_strncmp(&argv[1][i - 3], ".cub", 4) != 0)
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    int i;

    i = 0;
    if (manage_cub_extension(argv) == 1)
    {
        printf("Error\n");
        return (1);
    }
    return (0);
}