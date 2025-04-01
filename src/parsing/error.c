/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:04:41 by joyim             #+#    #+#             */
/*   Updated: 2025/04/01 19:08:51 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void handle_error(int error_num)
{
	if(error_num == ARG_ERROR)
		ft_putendl_fd(ARG_MSG, STDERR_FILENO);
	if(error_num == FORMAT_ERROR)
		ft_putendl_fd(FORMAT_MSG, STDERR_FILENO);

}