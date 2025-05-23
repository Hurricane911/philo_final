/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:59:43 by joyim             #+#    #+#             */
/*   Updated: 2025/04/05 17:36:13 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parse_arg(char **av);
int validate_args(char *str);

int parse_arg(char **av)
{
	int i;
	int num_philos;
	int temp;

	temp = 0;
	i = 1;
	num_philos = ft_atoi(av[1]);
	if(num_philos > 200 || num_philos <= 0)
		return (0);
	while(av[i])
	{
		temp = validate_args(av[i]);
		if(temp < 0)
			return (0);
		i++;
	}
	

	return (1);
}

int validate_args(char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	if(str[i] == '-')
		return(-1);
	if(str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (-1);
	while(str[i])
	{
		if(str[i] < '0' || str[i] > '9')
			return (-1);
		if(str[i] >= '0' && str[i] <= '9')
			num = (str[i] - '0') + (num * 10);
		i++;
	}
	// printf("%d", num);
	return (num);
}