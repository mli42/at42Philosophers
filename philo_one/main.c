/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:27:27 by mli               #+#    #+#             */
/*   Updated: 2020/09/22 11:38:58 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern t_hub		g_hub;
extern int volatile	g_stop;

static void	waitphilos(t_philo *philos)
{
	int i;

	i = -1;
	while (++i < g_hub.phinfo.nbphilo)
		pthread_join(philos[i].thread, NULL);
}

static void	ft_startphilos(t_philo *philos)
{
	int		i;

	i = -1;
	while (++i < g_hub.phinfo.nbphilo)
		pthread_create(&philos[i].thread, NULL, ft_philo, &philos[i]);
}

static void	supervisord(t_philo *philos)
{
	int						i;
	const unsigned long int	time_to_die = g_hub.phinfo.time_to[e_DIE];

	i = -1;
	while (++i < g_hub.phinfo.nbphilo)
		if (philos[i].last_meal != 0 &&
				ft_gettime() - philos[i].last_meal >= time_to_die)
		{
			ft_logs(ft_gettime() - g_hub.start_time, philos[i].index, e_DYING);
			setstop();
		}
}

int			main(int argc, char **argv)
{
	t_philo		*philos;

	philos = NULL;
	if (argc != 5 && argc != 6)
		return (ft_exit(NULL, "Takes 4 or 5 parameters"));
	if (!ft_initialization(&philos, argv))
		return (0);
	ft_startphilos(philos);
	while (!getstop())
		supervisord(philos);
	waitphilos(philos);
	ft_destructor(&philos);
	return (0);
}
