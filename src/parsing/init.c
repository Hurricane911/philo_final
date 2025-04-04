/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:16:55 by joyim             #+#    #+#             */
/*   Updated: 2025/04/04 14:08:49 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init(t_data *data, int ac, char **av);
void init_philos(t_data *data);
void init_forks_lock(t_data *data);

void init(t_data *data, int ac, char **av)
{
	data->start_time = 0;
	data->nb_philos = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if(ac == 6)
		data->eat_loop = ft_atoi(av[5]);
	data->is_exit = 0;
	data->is_dead = 0;

	init_philos(data);
	init_forks_locks(data);
}

void init_forks_locks(t_data *data)
{
	int i;

	i = 0;
	while(i < data->nb_philos)
	{
		if(pthread_mutex_init(&data->lock_forks[i], 0) != 0)
			return (handle_error(data, MUTEX_ERROR));
		i++;
	}
	if(pthread_mutex_init(&data->lock_exit, 0) !=0\
	|| pthread_mutex_init(&data->lock_print, 0) !=0\
	|| pthread_mutex_init(&data->lock_global, 0) !=0\
	|| pthread_mutex_init(&data->lock_dead, 0) !=0)
		return (handle_error(data, MUTEX_ERROR));
	// printf("hello");
}

void assign_forks(t_data *data, t_philo *philo)
{

	philo->forks[0] = philo->id;
	philo->forks[1] = (philo->id + 1) % data->nb_philos;
	// printf("forks :%d forks: %d\n", philo->forks[0], philo->forks[1]);

}

void init_philos(t_data *data)
{
	int i = 0;
	while(i < data->nb_philos)
	{
		data->philo[i].id = i;
		data->philo[i].meals_required = data->eat_loop;
		// printf("%d: ", data->philo[i].id);
		data->philo[i].last_meal = 0;
		assign_forks(data, &data->philo[i]);
		if((pthread_mutex_init(&data->philo[i].lock_eat_routine, 0) != 0))
			return (handle_error(data, MUTEX_ERROR));
		data->philo[i].data = data;
		i++;
	}
}