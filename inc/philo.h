/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:52:31 by joyim             #+#    #+#             */
/*   Updated: 2025/03/31 23:40:27 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>


# define RED "\033[0;31m" //ded
# define GREEN "\033[0;32m" //eat
# define YELLOW "\033[0;33m" //thinking
# define PURPLE "\033[0;35m" // sleep
# define CYAN "\033[0;36m"
# define RESET "\033[0m" //time

# define ARG_ERROR -1;

# define ARG_MSG "Arg Error: ./philo\n\
1 - <total_philos>\n\
2 - <time_to_die>\n\
3 - <time_to_eat>\n\
4 - <time_to_sleep>\n\
5 - <meals_needed>"

typedef struct s_philo
{
	pthread_t thread;

	
}t_philo;

typedef struct s_data;
{
	// pthread_mutex_t 

}t_data;

#endif