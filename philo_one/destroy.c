/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:35:32 by mli               #+#    #+#             */
/*   Updated: 2020/09/22 11:20:14 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern t_hub	g_hub;

void			ft_destructor(t_philo **philos)
{
	int i;

	if (!philos || !*philos)
		return ;
	i = -1;
	while (++i < g_hub.phinfo.nbphilo)
		pthread_mutex_destroy(&(*philos)[i].my_fork.lock);
	pthread_mutex_destroy(&g_hub.stoplock);
	ft_free((void **)philos);
}

int				ft_exit(t_philo **philos, const char *error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error, 2);
	ft_destructor(philos);
	return (0);
}
