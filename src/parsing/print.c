/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:08:19 by joyim             #+#    #+#             */
/*   Updated: 2025/04/04 20:48:33 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_action(t_philo *philo, t_state state);
void print_state(t_philo *philo, char *str, t_state state);

void print_action(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->data->lock_print);
	if(exit_condition(philo->data))
	{
		pthread_mutex_unlock(&philo->data->lock_print);
		return ;
	}
	if(state == GOT_FORK1 || state == GOT_FORK2)
		print_state(philo, "has taken a fork", state);
	if(state == DIED)
		print_state(philo, "Died", state);
	if(state == EATING)
		print_state(philo, "is eating", state);
	if(state == SLEEPING)
		print_state(philo, "is sleeping", state);
	if(state == THINKING)
		print_state(philo, "is thinking", state);
	pthread_mutex_unlock(&philo->data->lock_print);
}

void print_state(t_philo *philo, char *str, t_state state)
{
	const char *state_color;

	state_color = COLOR;
	if(state == DIED)
		state_color = RED;
	else if(state == GOT_FORK1 || state == GOT_FORK2)
		state_color = CYAN;
	else if(state == EATING)
		state_color = GREEN;
	else if(state == SLEEPING)
		state_color = PURPLE;
	else if(state == THINKING)
		state_color = YELLOW;
	printf(YELLOW "%ld\t" GREEN "%d\t" COLOR "%s%s\n" COLOR, \
	get_time() - philo->data->start_time, philo->id + 1, state_color, str);
	
}