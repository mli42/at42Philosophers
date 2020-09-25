/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:16:50 by mli               #+#    #+#             */
/*   Updated: 2020/09/25 11:26:43 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

extern t_hub		g_hub;
extern int volatile	g_stop;
extern sem_t		*g_semstop;

short int	getstop(void)
{
	short int dostop;

	dostop = (g_stop >= g_hub.phinfo.nbphilo ? 1 : 0);
	if (dostop)
		setstop();
	return (dostop);
}

void		incstop(void)
{
	sem_post(g_hub.mealstop);
}

void		setstop(void)
{
	int i;

	i = -1;
	sem_post(g_semstop);
	while (++i < g_hub.phinfo.nbphilo)
		sem_post(g_hub.mealstop);
}
