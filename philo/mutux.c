/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:04:07 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/01 11:24:05 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	er_break(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->data->m_dead);
	if ((philo->data->dead == 1) || (philo->data-> ac5 == 1
			&& (philo->eat == philo->data->nbr_repas)))
	{
		pthread_mutex_unlock(&philo->data->m_dead);
		if (i == 1)
			pthread_mutex_unlock(philo->fork_l);
		if (i == 2)
			pthread_mutex_unlock(philo->fork_r);
		if (i == 3)
		{
			pthread_mutex_unlock(philo->fork_r);
			pthread_mutex_unlock(philo->fork_l);
		}
		return (1);
	}
	pthread_mutex_unlock(&philo->data->m_dead);
	return (0);
}
