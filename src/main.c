/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:01:58 by joyim             #+#    #+#             */
/*   Updated: 2025/04/04 19:59:54 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void execution(t_data *data);
void monitor_death(t_data *data);
void exit_execution(t_data *data);

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
	return (EXIT_SUCCESS);
}

void monitor_death(t_data *data)
{
	int infinite;
	int i;

	infinite = 1;
	i = 0;

	while(infinite)
	{
		i = 0;
		while(infinite && i < data->nb_philos)
		{
			usleep(100);
			pthread_mutex_lock(&data->lock_global);
			if(data->philo[i].meals_required == 0 \
				|| exit_condition(data) \
				|| dead_condition(&data->philo[i]))
			{
				infinite = 0;
				pthread_mutex_unlock(&data->lock_global);
				break ;
			}
			i++;
			pthread_mutex_unlock(&data->lock_global);
		}
	}
	
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
	if(data->nb_philos > 1)
		monitor_death(data);
}

void exit_execution(t_data *data)
{
	int i;

	i = 0;
	while(i < data->nb_philos)
		pthread_join(data->philo[i++].thread, NULL);
	cleanup_mutex(data);
}