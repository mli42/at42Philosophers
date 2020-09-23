/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:35:32 by mli               #+#    #+#             */
/*   Updated: 2020/09/23 14:45:41 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

extern t_hub	g_hub;

void			ft_destructor(t_philo **philos)
{
	if (!philos || !*philos)
		return ;
	if (g_hub.forks && g_hub.forks != SEM_FAILED)
		sem_close(g_hub.forks);
	if (g_hub.stoplock && g_hub.stoplock != SEM_FAILED)
		sem_close(g_hub.stoplock);
	ft_free((void **)philos);
}

int				ft_exit(t_philo **philos, const char *error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error, 2);
	ft_destructor(philos);
	return (0);
}
