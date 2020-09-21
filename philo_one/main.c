/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:27:27 by mli               #+#    #+#             */
/*   Updated: 2020/09/21 11:48:57 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern t_hub	g_hub;

int		ft_exit(t_philo **philos, const char *error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error, 2);
	ft_destructor(philos);
	return (0);
}

void	ft_philoinit(t_philo *philos, int const nbphilo)
{
	int i;

	i = -1;
	while (++i < nbphilo - 1)
		philos[i].neighbours_fork = &philos[i + 1].my_fork;
	philos[i].neighbours_fork = &philos[0].my_fork;
	i = -1;
	while (++i < nbphilo)
	{
		philos[i].index = i + 1;
		pthread_mutex_init(&philos[i].my_fork.lock, NULL);
	}
}

int		ft_initialization(t_philo **philos, char **argv)
{
	memset(&g_hub, 0, sizeof(g_hub));
	if (!ft_parser(&g_hub.phinfo, argv))
		return (ft_exit(NULL, "At least one parameter is not natural integer"));
	if (g_hub.phinfo.nbphilo == 1)
		return (ft_exit(NULL, "Too few amount of philosophers"));
	if (!(*philos = ft_memalloc(sizeof(t_philo) * g_hub.phinfo.nbphilo)))
		return (ft_exit(NULL, "Cannot allocate memory"));
	ft_philoinit(*philos, g_hub.phinfo.nbphilo);
	if ((g_hub.start_time = ft_gettime()) == 0)
		return (ft_exit(philos, "Cannot get time"));
	return (1);
}

int		main(int argc, char **argv)
{
	t_philo		*philos;

	philos = NULL;
	if (argc != 5 && argc != 6)
		return (ft_exit(NULL, "Takes 4 or 5 parameters"));
	if (!ft_initialization(&philos, argv))
		return (0);
	ft_putendl_fd("SUCCEED", 1);
	ft_destructor(&philos);
	return (0);
}
