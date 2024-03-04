/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:12:51 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/01 11:27:52 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	int				eat;
	pthread_t		thread;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long long			start;
	int					nbr_reel;
	long				nbr_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_repas;
	int					ac5;
	int					a;
	int					dead;
	pthread_mutex_t		m_eat;
	pthread_mutex_t		m_dead;
	pthread_mutex_t		m_time;
	pthread_mutex_t		m_meal;
	pthread_mutex_t		m_nbr_repas;
	pthread_mutex_t		print;
	pthread_t			death;
	pthread_mutex_t		*forks;
	t_philo				*philo;
}	t_data;

//Pars
void		allphilo(t_data *data, t_philo *philo);
int			allpars(char **av, int i, t_data *data);
int			write_er(t_data *data);
int			parsing(char *str, t_data *data);
int			takearg(char **av, t_data *data);
void		prendre(char **av, t_data *data);
int			ft_atoi(const char *str, t_data *s_data);

//Philo
void		*routine(void *ptr);
int			main(int ac, char **av);
void		func_philo(t_data *data);
void		init_mutex(t_data *data);
void		eat(t_philo *philo);
void		init_philo(t_data *data);
void		free_philo(t_data *data);
void		think_and_sleep(t_philo *philo);
void		dead(t_philo *philo);

//utils
long long	gct(void);
int			ft_usleep(size_t milliseconds);
void		ft_1(t_data *data);
void		message(t_philo	*philo, char *str);
int			er_break(t_philo *philo, int i);
int			philo_eat(t_philo *philo);

#endif
