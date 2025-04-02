/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:01:58 by joyim             #+#    #+#             */
/*   Updated: 2025/04/02 20:08:15 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data data;
	if(ac != 5 && ac != 6)
		handle_error(&data, ARG_ERROR);

	if(parse_arg(av) == 0)
		handle_error(&data, FORMAT_ERROR);
	
	init(&data, ac, av);
}