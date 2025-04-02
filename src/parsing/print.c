/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:08:19 by joyim             #+#    #+#             */
/*   Updated: 2025/04/03 01:14:00 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_action(t_philo *philo, t_state state);
void print_state(t_philo *philo, char *str, t_state state);

void print_action(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->data->lock_print);
	if(state == GOT_FORK1 || GOT_FORK2)
		print_state(philo, "GOT_FORK", state);
	else if(state == DIED)
		print_state(philo, "Died", state);
	else if(state == EATING)
		print_state(philo, "Eating", state);
	pthread_mutex_unlock(&philo->data->lock_print);
}

void print_state(t_philo *philo, char *str, t_state state)
{
	const char *state_color;

	state_color = COLOR;
	if(state == DIED)
		state_color == RED;
	if(state == GOT_FORK1 || GOT_FORK2)
		state_color == CYAN;
	if(state_color == EATING)
		state_color == GREEN;
	if(state_color == SLEEPING)
		state_color == PURPLE;
	if(state_color == THINKING)
		state_color == YELLOW;
	
}