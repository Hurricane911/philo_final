/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:16:55 by joyim             #+#    #+#             */
/*   Updated: 2025/04/01 20:57:02 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init(t_data *data, int ac, char **av);
void init_philos(int nb_philos, int eat_loop, t_philo *philo);

void init(t_data *data, int ac, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if(ac == 6)
		data->eat_loop = ft_atoi(av[5]);
	data->is_exit = 0;
	data->is_dead = 0;

	init_philos(data->nb_philos, data->eat_loop, data->philo);

}

void init_philos(int nb_philos, int eat_loop, t_philo *philo)
{
	int i = 0;
	while(i < nb_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals_required = eat_loop;
		printf("Philosopher %d initialized with %d meals required\n", 
			philo[i].id, philo[i].meals_required);
		i++;
	}
}