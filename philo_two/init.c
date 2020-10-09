/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:11:33 by mli               #+#    #+#             */
/*   Updated: 2020/10/09 14:10:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

extern t_hub	g_hub;

/*
** Fills the t_phinfo structure
** Since its full of integers, one can cast this struct into int *
*/

int			ft_parser(t_phinfo *phinfo, char **argv)
{
	int		i;
	int		*iphinfo;

	i = (argv[5] == NULL ? 4 : 5);
	iphinfo = (int *)phinfo;
	while (--i >= 0)
		if (ft_atoi_isdigit(argv[i + 1], &iphinfo[i]) == 0 || iphinfo[i] < 1)
			return (0);
	return (1);
}

static void	ft_philoinit(t_philo *philos, int const nbphilo)
{
	int i;

	i = -1;
	while (++i < nbphilo)
		philos[i].index = i + 1;
}

static int	init_one_sem(sem_t **sem, const char *const name, const int init)
{
	sem_unlink(name);
	if ((*sem = sem_open(name, O_CREAT, 644, init)) == SEM_FAILED)
		return (0);
	return (1);
}

int			ft_initialization(t_philo **philos, char **argv)
{
	memset(&g_hub, 0, sizeof(g_hub));
	if (!ft_parser(&g_hub.phinfo, argv))
		return (ft_exit(NULL, "At least one parameter is not natural integer"));
	if (g_hub.phinfo.nbphilo == 1)
		return (ft_exit(NULL, "Too few amount of philosophers"));
	if (!(*philos = ft_memalloc(sizeof(t_philo) * g_hub.phinfo.nbphilo)))
		return (ft_exit(NULL, "Cannot allocate memory"));
	ft_philoinit(*philos, g_hub.phinfo.nbphilo);
	if (!init_one_sem(&g_hub.forks, FORK_SEM, g_hub.phinfo.nbphilo))
		return (ft_exit(philos, "Cannot create semaphore (forks)"));
	if (!init_one_sem(&g_hub.stoplock, PH_STOP_SEM, 1))
		return (ft_exit(philos, "Cannot create semaphore (stoplock)"));
	if ((g_hub.start_time = ft_gettime()) == 0)
		return (ft_exit(philos, "Cannot get time"));
	return (1);
}
