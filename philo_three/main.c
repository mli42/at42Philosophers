/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:27:27 by mli               #+#    #+#             */
/*   Updated: 2020/09/24 16:49:23 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

extern t_hub		g_hub;
extern int volatile	g_stop;
extern sem_t		*g_semstop;

static void	waitphilos(t_philo *philos)
{
	int i;

	i = -1;
	while (++i < g_hub.phinfo.nbphilo)
		kill(philos[i].pid, SIGQUIT);
}

static void	ft_startphilos(t_philo *philos)
{
	int		i;

	i = 0;
	while (i < g_hub.phinfo.nbphilo)
	{
		if ((philos[i].pid = fork()) == 0)
			ft_philo(&philos[i]);
		else if (philos[i].pid == -1)
			ft_exit(&philos, "Couldn't fork");
		i += 2;
	}
	usleep(500);
	i = 1;
	while (i < g_hub.phinfo.nbphilo)
	{
		if ((philos[i].pid = fork()) == 0)
			ft_philo(&philos[i]);
		else if (philos[i].pid == -1)
			ft_exit(&philos, "Couldn't fork");
		i += 2;
	}
}

int			main(int argc, char **argv)
{
	t_philo		*philos;

	philos = NULL;
	g_semstop = NULL;
	memset(&g_hub, 0, sizeof(g_hub));
	if (argc != 5 && argc != 6)
		return (ft_exit(NULL, "Takes 4 or 5 parameters"));
	if (!ft_initialization(&philos, argv))
		return (0);
	ft_startphilos(philos);
	sem_wait(g_semstop);
	waitphilos(philos);
	ft_destructor(&philos);
	return (0);
}
