/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyson <joyson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:04:41 by joyim             #+#    #+#             */
/*   Updated: 2025/04/04 18:29:43 by joyson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void handle_error(t_data *data, int error_num);
void cleanup_mutex(t_data *data);
void destroy_mutex(t_data *data);

void handle_error(t_data *data, int error_num)
{
	if(error_num == ARG_ERROR)
		ft_putendl_fd(ARG_MSG, STDERR_FILENO);
	if(error_num == FORMAT_ERROR)
		ft_putendl_fd(FORMAT_MSG, STDERR_FILENO);
	if(error_num == MUTEX_ERROR)
		ft_putendl_fd(MUTEX_MSG, STDERR_FILENO);
	if(error_num == THREAD_ERROR)
		ft_putendl_fd(THREAD_MSG, STDERR_FILENO);
	if(data)
		cleanup_mutex(data);
}

void cleanup_mutex(t_data *data)
{
	if(data->nb_philos)
		destroy_mutex(data);
}

void destroy_mutex(t_data *data)
{
	int i;

	i = 0;
	while(i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->philo[i].lock_eat_routine);
		pthread_mutex_destroy(&data->lock_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->lock_exit);
	pthread_mutex_destroy(&data->lock_print);
	pthread_mutex_destroy(&data->lock_dead);
	
}