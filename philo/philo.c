/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:00:42 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/01 11:28:21 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*check_life(void *ptr)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *) ptr;
	i = 0;
	while (1)
	{
		if (!(philo->data-> ac5 == 1 && (philo_eat(philo) == 1)))
		{
			if (i == philo->data->nbr_philo - 1)
				i = 0;
			pthread_mutex_lock(&philo->data->m_meal);
			if (((gct() - philo[i].last_meal) >= philo->data->time_to_die))
			{
				dead(philo);
				break ;
			}
			pthread_mutex_unlock(&philo->data->m_meal);
			i++;
		}
		if ((philo->data-> ac5 == 1 && (philo_eat(philo) == 1)))
			break ;
	}
	return (0);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *) ptr;
	if (philo->id % 2 != 0)
		usleep(5000);
	while (1)
	{
		if (er_break(philo, 3) == 1)
			break ;
		eat(philo);
		if (er_break(philo, 3) == 1)
			break ;
		think_and_sleep(philo);
	}
	return (0);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->m_dead, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	pthread_mutex_init(&data->m_meal, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->m_nbr_repas, NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	while (i < data->nbr_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philo[i].eat = 0;
		i++;
	}
	i = 0;
	data->philo[0].fork_r = &data->forks[0];
	data->philo[0].fork_l = &data->forks[data->nbr_philo - 1];
	i = 1;
	while (i < data->nbr_philo)
	{
		data->philo[i].fork_r = &data->forks[i];
		data->philo[i].fork_l = &data->forks[i - 1];
		i++;
	}
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].id = i;
		data->philo[i].last_meal = gct();
		data->philo[i].data = data;
		i++;
	}
}

void	func_philo(t_data *data)
{
	int	i;

	i = 0;
	data->start = gct();
	init_philo(data);
	init_mutex(data);
	pthread_create(&data->death, NULL, check_life, &data->philo[i]);
	while (i < data->nbr_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_join(data->death, NULL);
}
