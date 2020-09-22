/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:34:03 by mli               #+#    #+#             */
/*   Updated: 2020/09/22 15:19:07 by mli              ###   ########.fr       */
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

static int	unlockforks(t_philo *const philo)
{
	pthread_mutex_unlock(&philo->my_fork.lock);
	pthread_mutex_unlock(&philo->neighbours_fork->lock);
	return (1);
}

static void	ft_must_eat(t_philo *philo, const int must_eat)
{
	if (++philo->eaten_meals == must_eat)
		incstop();
}

void		*ft_philo(void *arg)
{
	t_philo		*philo;
	const int	must_eat = g_hub.phinfo.must_eat;

	philo = (t_philo *)arg;
	while (!getstop())
	{
		lockforks(philo);
		if (getstop() && unlockforks(philo))
			break ;
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_EATING);
		if (must_eat != 0 && philo->eaten_meals != must_eat)
			ft_must_eat(philo, must_eat);
		philo->last_meal = ft_gettime();
		dosleep(g_hub.phinfo.time_to[e_EAT]);
		unlockforks(philo);
		if (getstop())
			break ;
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_SLEEPING);
		dosleep(g_hub.phinfo.time_to[e_SLEEP]);
		if (getstop())
			break ;
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_THINKING);
		usleep(100);
	}
	return (NULL);
}
