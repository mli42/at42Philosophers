/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:27:27 by mli               #+#    #+#             */
/*   Updated: 2020/09/18 16:42:09 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_exit(t_hub *hub, const char *error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error, 2);
	ft_destroy_hub(hub);
	return (0);
}

void	ft_linkforks(t_philo *philos, int const nbphilo)
{
	int i;

	i = -1;
	while (++i < nbphilo - 1)
		philos[i].neighbours_fork = &philos[i + 1].my_fork;
	philos[i].neighbours_fork = &philos[0].my_fork;
}

int		ft_hubinit(t_hub *hub, int argc, char **argv)
{
	memset(hub, 0, sizeof(*hub));
	if (argc != 5 && argc != 6)
		return (ft_exit(hub, "Takes 4 or 5 parameters"));
	if (!ft_parser(&hub->phinfo, argv))
		return (ft_exit(hub, "At least one parameter is not natural integer"));
	if (hub->phinfo.nbphilo == 1)
		return (ft_exit(hub, "Too few amount of philosophers"));
	if ((hub->start_time = ft_gettime()) == -1)
		return (ft_exit(hub, "Cannot get time"));
	if (!(hub->philos = ft_memalloc(sizeof(t_philo) * hub->phinfo.nbphilo)))
		return (ft_exit(hub, "Cannot allocate memory"));
	ft_linkforks(hub->philos, hub->phinfo.nbphilo);
	return (1);
}

int		main(int argc, char **argv)
{
	t_hub	hub;

	if (!ft_hubinit(&hub, argc, argv))
		return (0);
	ft_putendl_fd("SUCCEED", 1);
	ft_destroy_hub(&hub);
	return (0);
}
