/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:27:27 by mli               #+#    #+#             */
/*   Updated: 2020/09/18 15:06:50 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_exit(t_hub *hub, const char *error)
{
	(void)hub;
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error, 2);
	return (0);
}

int		ft_hubinit(t_hub *hub, int argc, char **argv)
{
	memset(hub, 0, sizeof(*hub));
	if (argc != 5 && argc != 6)
		return (ft_exit(hub, "Takes 4 or 5 parameters"));
	if (!ft_parser(&hub->phinfo, argv))
		return (ft_exit(hub, "At least one parameter is not a natural integer"));
	if ((hub->start_time = ft_gettime()) == -1)
		return (ft_exit(hub, "Cannot get time"));
	return (1);
}

int		main(int argc, char **argv)
{
	t_hub	hub;

	if (ft_hubinit(&hub, argc, argv))
		ft_putendl_fd("SUCCEED", 1);
	return (0);
}
