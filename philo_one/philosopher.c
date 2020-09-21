/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:34:03 by mli               #+#    #+#             */
/*   Updated: 2020/09/21 16:03:31 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern int volatile	g_stop;
extern t_hub		g_hub;

static int	can_eat(t_philo const *const philo)
{
	if (philo->my_fork.taken || philo->neighbours_fork->taken)
		return (0);
	return (1);
}

static void	lockforks(t_philo *const philo)
{
	pthread_mutex_lock(&philo->my_fork.lock);
	ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_TAKING_FORK);
	pthread_mutex_lock(&philo->neighbours_fork->lock);
	ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_TAKING_FORK);
}

static void	unlockforks(t_philo *const philo)
{
	pthread_mutex_unlock(&philo->my_fork.lock);
	pthread_mutex_unlock(&philo->neighbours_fork->lock);
}

void		*ft_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (g_stop != g_hub.phinfo.nbphilo)
	{
		while (!can_eat(philo))
			;
		lockforks(philo);
		ft_logs(ft_gettime() - g_hub.start_time, philo->index, e_EATING);
		philo->eaten_meals++;
		if (philo->eaten_meals == g_hub.phinfo.must_eat)
			g_stop++;
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
