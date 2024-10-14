/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:31:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/14 19:55:18 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_allocation_failed_and_exit()
{
	ft_putstr_fd("Error: A memory allocation failed\n", 2);
	exit(EXIT_FAILURE);
}

