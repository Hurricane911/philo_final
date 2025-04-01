/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:52:31 by joyim             #+#    #+#             */
/*   Updated: 2025/04/01 20:48:55 by joyim            ###   ########.fr       */
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

# define ARG_ERROR -1
# define FORMAT_ERROR -2

# define ARG_MSG "Arg Error: ./philo\n\
1 - <total_philos>\n\
2 - <time_to_die>\n\
3 - <time_to_eat>\n\
4 - <time_to_sleep>\n\
5 - <meals_needed>"

# define FORMAT_MSG "FORMAT Error: \n\
1 - <Philo > 200>\n\
2 - <Has Negative Values>\n\
3 - "

# define MAX 200 

typedef struct s_data t_data;

typedef struct s_philo
{
	pthread_t thread;
	int		id;
	int		meals_required;
	int		forks[2];
	
	
}t_philo;

typedef struct s_data
{
	int nb_philos;
	int death_time;
	int eat_time;
	int sleep_time;
	int eat_loop;

	int is_exit;
	int is_dead;
	// pthread_mutex_t 
	t_philo philo[MAX];
}t_data;

#endif

// error.c
void handle_error(int error_num);

// parse.c
int parse_arg(char **av);
int validate_args(char *str);

// libft_utils.c
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);

// init.c
void init(t_data *data, int ac, char **av);
void init_philos(int nb_philos, int eat_loop, t_philo *philo);