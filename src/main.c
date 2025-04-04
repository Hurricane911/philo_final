/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyson <joyson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:01:58 by joyim             #+#    #+#             */
/*   Updated: 2025/04/04 10:56:30 by joyson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void execution(t_data *data);

int main(int ac, char **av)
{
	t_data data;
	if(ac != 5 && ac != 6)
		handle_error(&data, ARG_ERROR);

	if(parse_arg(av) == 0)
		handle_error(&data, FORMAT_ERROR);
	
	init(&data, ac, av);
	execution(&data);
	exit_execution(&data);

}

void execution(t_data *data)
{
	int i;

	i = 0;
	data->start_time = get_time();
	while(i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philo[i].lock_eat_routine);
		data->philo[i].last_meal = get_time();
		pthread_mutex_unlock(&data->philo[i].lock_eat_routine);
		
		if(pthread_create(&data->philo[i].thread, NULL, routine, \
		(void *)&data->philo[i]) != 0)
			return(handle_error(data, THREAD_ERROR));
		i++;
	}

}

void exit_execution(t_data *data)
{
	int i;

	i = 0;
	while(i < data->nb_philos)
	{
		pthread_join(data->philo[i++].thread, NULL);
		i++;
	}
	cleanup_mutex(data);
}