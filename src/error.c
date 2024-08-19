/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:31:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/19 15:01:11 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	message_error_for_parsing_args(char *message, int ret_value)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	return (ret_value);
}

int	message_error_for_missing_elements(t_counter_parameter counter_parameter)
{
	if (counter_parameter.counter_no != 1 || counter_parameter.counter_so != 1
		|| counter_parameter.counter_we != 1
		|| counter_parameter.counter_ea != 1
		|| counter_parameter.counter_f != 1 || counter_parameter.counter_c != 1)
	{
		ft_putstr_fd("Error: One or more elements are missing \n", 2);
		return (1);
	}
	return (0);
}

int	message_error_r1(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	return (1);
}

