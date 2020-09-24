/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:34:03 by mli               #+#    #+#             */
/*   Updated: 2020/09/25 00:30:20 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

extern int volatile	g_stop;
extern t_hub		g_hub;

static void	lockforks(t_philo *const philo)
{
	sem_wait(g_hub.forks);
	ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_TAKING_FORK);
	sem_wait(g_hub.forks);
	ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_TAKING_FORK);
}

static void	unlockforks(void)
{
	sem_post(g_hub.forks);
	sem_post(g_hub.forks);
}

static void	*supervisord(void *arg)
{
	const t_philo			*philo = (t_philo *)arg;
	const unsigned long int	time_to_die = g_hub.phinfo.time_to[e_DIE];

	while (1)
	{
		if (philo->last_meal != 0 &&
				ft_gettime() - philo->last_meal > time_to_die)
		{
			ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_DYING);
			setstop();
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

void		*ft_philo(void *arg)
{
	t_philo		*philo;
	pthread_t	thread;
	const int	must_eat = g_hub.phinfo.must_eat;

	philo = (t_philo *)arg;
	pthread_create(&thread, NULL, supervisord, philo);
	while (!getstop())
	{
		lockforks(philo);
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_EATING);
		if (must_eat != 0 && philo->eaten_meals != must_eat)
			if (++philo->eaten_meals == must_eat)
				incstop();
		philo->last_meal = ft_gettime();
		dosleep(g_hub.phinfo.time_to[e_EAT]);
		unlockforks();
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_SLEEPING);
		dosleep(g_hub.phinfo.time_to[e_SLEEP]);
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_THINKING);
	}
	return (NULL);
}
