/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyson <joyson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:49:13 by joyim             #+#    #+#             */
/*   Updated: 2025/04/04 13:04:17 by joyson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *routine(void *data);
void *single_philo(t_philo *philo);
void eat_routine(t_philo *philo);
void sleep_think(t_philo *philo);

void *routine(void *data)
{
	t_philo *philo;
	philo = (t_philo *)data;

	if (philo->data->nb_philos == 1)
		return (single_philo(philo));
	if (philo->id % 2 == 1)
		waiting(philo->data, philo->data->sleep_time);
	while(!exit_condition(philo->data))
	{
		eat_routine(philo);
		if(philo->meals_required == 0 || exit_condition(philo->data))
			break ;
		sleep_think(philo);
	}
	return (NULL);
}

void *single_philo(t_philo *philo)
{
	
	pthread_mutex_lock(&philo->data->lock_forks[philo->forks[0]]);
	print_action(philo, GOT_FORK1);
	waiting(philo->data, philo->data->death_time);
	print_action(philo, DIED);
	pthread_mutex_unlock(&philo->data->lock_forks[philo->forks[0]]);
	return (NULL);
}

void eat_routine(t_philo *philo)
{
	if(philo->forks[0] < philo->forks[1])
	{
		pthread_mutex_lock(&philo->data->lock_forks[philo->forks[0]]);
		pthread_mutex_lock(&philo->data->lock_forks[philo->forks[1]]);
	}
	else
	{
		pthread_mutex_lock(&philo->data->lock_forks[philo->forks[1]]);
		pthread_mutex_lock(&philo->data->lock_forks[philo->forks[0]]);
	}
	print_action(philo, GOT_FORK1);
	print_action(philo, GOT_FORK2);
	print_action(philo, EATING);

	pthread_mutex_lock(&philo->lock_eat_routine);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->lock_eat_routine);

	waiting(philo->data, philo->data->eat_time);
	pthread_mutex_lock(&philo->data->lock_global);
	philo->meals_required -= 1;
	pthread_mutex_unlock(&philo->data->lock_global);
	
	if(philo->forks[0] < philo->forks[1])
	{
		pthread_mutex_unlock(&philo->data->lock_forks[philo->forks[0]]);
		pthread_mutex_unlock(&philo->data->lock_forks[philo->forks[1]]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->lock_forks[philo->forks[1]]);
		pthread_mutex_unlock(&philo->data->lock_forks[philo->forks[0]]);
	}
}

void sleep_think(t_philo *philo)
{
	print_action(philo, SLEEPING);
	waiting(philo->data, philo->data->sleep_time);
	print_action(philo, THINKING);
}