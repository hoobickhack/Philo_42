/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:37:23 by isouaidi          #+#    #+#             */
/*   Updated: 2024/02/29 10:11:45 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	write_er(t_data *data)
{
	if (data->a < 9)
	{
		if (data->a == 1)
			printf("error\n Philosophers only takes numbers\n");
		if (data->a == 2)
			printf("error\n Philosophers takes 4 or 5 args\n");
		if (data->a == 3)
			printf("Error\n check INT_MAX\n");
		if (data->a == 4)
			printf("Error\n check your philos\n");
		return (1);
	}
	else
		return (0);
}

int	parsing(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			data->a = 1;
			write_er (data);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str, t_data *data)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
	{
		data->a = 3;
		write_er(data);
		return (-1);
	}
	return (result * sign);
}

int	takearg(char **av, t_data *data)
{
	if (ft_atoi(av[1], data) < 1)
	{
		data->a = 4;
		write_er(data);
		return (1);
	}
	else
	{
		if ((ft_atoi(av[1], data) == -1 || ft_atoi(av[2], data) == -1
				|| ft_atoi(av[3], data) == -1 || ft_atoi(av[4], data) == -1))
			return (1);
		else
		{
			prendre(av, data);
			if (av[5])
			{
				if (ft_atoi(av[5], data) == -1)
					return (1);
				data->nbr_repas = ft_atoi(av[5], data);
				data->ac5 = 1;
			}
		}
	}
	return (0);
}

void	prendre(char **av, t_data *data)
{
	data->nbr_philo = ft_atoi(av[1], data);
	data->time_to_die = ft_atoi(av[2], data);
	data->time_to_eat = ft_atoi(av[3], data);
	data->time_to_sleep = ft_atoi(av[4], data);
	data->nbr_repas = -1;
}
