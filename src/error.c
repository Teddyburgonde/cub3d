/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:31:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/06 19:06:18 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	message_error_for_missing_elements(t_counter_parameter counter_parameter)
{
	if (counter_parameter.counter_no != 1 || counter_parameter.counter_so != 1
		|| counter_parameter.counter_we != 1
		|| counter_parameter.counter_ea != 1
		|| counter_parameter.counter_f != 1 || counter_parameter.counter_c != 1)
	{
		ft_putstr_fd("Error: One or more elements is missing \n", 2); // is missing
		exit (1);
	}
	return (0);
}

int	message_error_return_1(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	return (1);
}

int	free_tab_return_1(char **arr)
{
	free_array(arr);
	return (1);
}
