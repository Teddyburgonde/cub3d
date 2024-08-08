/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:31:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/09 01:31:23 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	message_error_for_parsing_args(char *message, int ret_value)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(message, 2);
	return (ret_value);
}
