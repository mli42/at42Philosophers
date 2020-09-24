/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:35:32 by mli               #+#    #+#             */
/*   Updated: 2020/09/24 16:28:30 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

extern t_hub	g_hub;
extern sem_t	*g_semstop;

static void		destroy_sem(sem_t *sem)
{
	if (sem && sem != SEM_FAILED)
		sem_close(sem);
}

void			ft_destructor(t_philo **philos)
{
	destroy_sem(g_hub.forks);
	destroy_sem(g_hub.mealstop);
	destroy_sem(g_semstop);
	destroy_sem(g_hub.someone_died);
	if (philos && *philos)
		ft_free((void **)philos);
}

int				ft_exit(t_philo **philos, const char *error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error, 2);
	ft_destructor(philos);
	exit(0);
	return (0);
}
