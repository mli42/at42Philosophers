/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:34:03 by mli               #+#    #+#             */
/*   Updated: 2020/09/22 12:14:00 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern int volatile	g_stop;
extern t_hub		g_hub;

static void	lockforks(t_philo *const philo)
{
	const short int odd = (philo->index % 2);

	if (odd)
	{
		pthread_mutex_lock(&philo->my_fork.lock);
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_TAKING_FORK);
	}
	pthread_mutex_lock(&philo->neighbours_fork->lock);
	ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_TAKING_FORK);
	if (!odd)
	{
		pthread_mutex_lock(&philo->my_fork.lock);
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_TAKING_FORK);
	}
}

static void	unlockforks(t_philo *const philo)
{
	pthread_mutex_unlock(&philo->my_fork.lock);
	pthread_mutex_unlock(&philo->neighbours_fork->lock);
}

void		*ft_philo(void *arg)
{
	t_philo		*philo;
	const int	must_eat = g_hub.phinfo.must_eat;

	philo = (t_philo *)arg;
	while (!getstop())
	{
		lockforks(philo);
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_EATING);
		if (!must_eat && philo->eaten_meals != must_eat)
			philo->eaten_meals++;
		if (must_eat != 0 && philo->eaten_meals == must_eat)
			incstop();
		philo->last_meal = ft_gettime();
		dosleep(g_hub.phinfo.time_to[e_EAT]);
		unlockforks(philo);
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_SLEEPING);
		dosleep(g_hub.phinfo.time_to[e_SLEEP]);
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_THINKING);
		usleep(100);
	}
	return (NULL);
}
