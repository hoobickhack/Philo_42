/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:09:48 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/01 11:27:10 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	eat(t_philo *philo)
{
	if (er_break(philo, 2) == 1)
		return ;
	pthread_mutex_lock(philo->fork_r);
	if (er_break(philo, 2) == 1)
		return ;
	message(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->fork_l);
	if (er_break(philo, 1) == 1)
		return ;
	message(philo, "has taken a fork\n");
	if (er_break(philo, 3) == 1)
		return ;
	message(philo, "is eating\n");
	if (er_break(philo, 3) == 1)
		return ;
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->m_eat);
	philo->eat++;
	pthread_mutex_unlock(&philo->data->m_eat);
	pthread_mutex_lock(&philo->data->m_meal);
	philo->last_meal = gct();
	pthread_mutex_unlock(&philo->data->m_meal);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	message(t_philo	*philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s", gct()
		- philo->data->start, philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	think_and_sleep(t_philo *philo)
{
	if (er_break(philo, 3) == 1)
		return ;
	message(philo, "is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
	if (er_break(philo, 3) == 1)
		return ;
	message(philo, "is thinking\n");
}

void	dead(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->m_meal);
	pthread_mutex_lock(&philo->data->m_dead);
	philo->data->dead = 1;
	pthread_mutex_unlock(&philo->data->m_dead);
	message(philo, "dead\n");
}

int	philo_eat(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != philo->data->nbr_philo)
	{
		pthread_mutex_lock(&philo->data->m_eat);
		if (philo[i].eat == philo->data->nbr_repas)
			j++;
		pthread_mutex_unlock(&philo->data->m_eat);
		if (j == philo->data->nbr_philo)
			return (1);
		i++;
	}
	return (0);
}
