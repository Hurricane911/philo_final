/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:52:31 by joyim             #+#    #+#             */
/*   Updated: 2025/04/05 17:10:59 by joyim            ###   ########.fr       */
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
# define COLOR "\033[0m" //time

typedef enum e_state
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	GOT_FORK1 = 4,
	GOT_FORK2 = 5
}t_state;

# define ARG_ERROR -1
# define FORMAT_ERROR -2
# define MUTEX_ERROR -3
# define THREAD_ERROR -4

# define ARG_MSG "Arg Error: ./philo\n\
1 - <total_philos>\n\
2 - <time_to_die>\n\
3 - <time_to_eat>\n\
4 - <time_to_sleep>\n\
5 - <meals_needed>"

# define FORMAT_MSG "FORMAT Error: \n\
1 - <Philo > 200>\n\
2 - <Has Negative Values>\n\
3 - has non-integer value"

# define MUTEX_MSG "Mutex_ERROR"
# define THREAD_MSG "THREAD_ERRO"

# define MAX 200 

typedef struct s_data t_data;

typedef struct s_philo
{
	pthread_t thread;
	time_t last_meal;
	int		id;
	int		meals_required;
	int		forks[2];
	pthread_mutex_t lock_eat_routine;
	t_data *data;
	
}t_philo;

typedef struct s_data
{
	time_t start_time;
	int nb_philos;
	int death_time;
	int eat_time;
	int sleep_time;
	int eat_loop;

	int is_exit;
	int is_dead;

	pthread_mutex_t lock_forks[MAX];
	pthread_mutex_t lock_exit;
	pthread_mutex_t lock_print;
	pthread_mutex_t lock_global;
	pthread_mutex_t	lock_dead;
	t_philo philo[MAX];
}t_data;


// main.c
void execution(t_data *data);
void monitor_death(t_data *data);
void exit_execution(t_data *data);

// error.c
void handle_error(t_data *data, int error_num);
void cleanup_mutex(t_data *data);
void destroy_mutex(t_data *data);

// parse.c
int parse_arg(char **av);
int validate_args(char *str);

// libft_utils.c
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);

// init.c
void init(t_data *data, int ac, char **av);
void assign_forks(t_data *data, t_philo *philo);
void init_philos(t_data *data);
void init_forks_locks(t_data *data);

// print.c
void print_action(t_philo *philo, t_state state);
void print_state(t_philo *philo, char *str, t_state state);

// routine.c
void *routine(void *data);
void *single_philo(t_philo *philo);
void eat_routine(t_philo *philo);
void sleep_think(t_philo *philo);

// utils_philo.c
time_t get_time(void);
void waiting(t_data *data, time_t waiting_time);
int exit_condition(t_data *data);
int dead_condition(t_philo *philo);

#endif
