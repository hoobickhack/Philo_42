/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:41 by isouaidi          #+#    #+#             */
/*   Updated: 2024/02/28 17:10:58 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	allpars(char **av, int i, t_data *data)
{
	while (av[++i])
	{
		if (parsing(av[i], data) == 1)
			return (1);
	}
	if (takearg(av, data) == 1)
		return (1);
	return (0);
}

void	allphilo(t_data *data, t_philo *philo)
{
	data->philo = philo;
	philo->data = data;
	data->dead = 0;
	func_philo(data);
}

long long	gct(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = gct();
	while ((gct() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	ft_1(t_data *data)
{
	printf("0 1 has taken a fork\n");
	printf("%ld 1 dead\n", data->time_to_die);
}
