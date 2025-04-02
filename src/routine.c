/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:49:13 by joyim             #+#    #+#             */
/*   Updated: 2025/04/03 01:19:51 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *routine(void *data);
void single_philo(t_philo *philo);

void *routine(void *data)
{
	t_philo *philo;
	philo = (t_philo *)data;

	if (philo->data->nb_philos == 1)
		return (single_philo(philo));
}

void single_philo(t_philo *philo)
{
	
	pthread_mutex_lock(&philo->data->lock_forks[philo->forks[0]]);
	print_action(philo, GOT_FORK1);
	print_action(philo, DIED);
	pthread_mutex_unlock(&philo->data->lock_forks[philo->forks[0]]);
	return (NULL);
}