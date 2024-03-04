/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:15:09 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/01 13:55:25 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	data = malloc(sizeof(t_data));
	i = 0;
	if ((ac == 5 || ac == 6))
	{
		if (allpars(av, i, data) == 1)
			return (0);
		philo = malloc(data->nbr_philo * sizeof(t_philo));
		if (data->nbr_philo == 1)
			ft_1(data);
		else
			allphilo(data, philo);
	}
	else
	{
		data->a = 2;
		write_er(data);
	}
	if (data->nbr_philo > 1)
		free(data->forks);
	free(data);
	free(philo);
}
