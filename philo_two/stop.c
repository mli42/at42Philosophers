/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:16:50 by mli               #+#    #+#             */
/*   Updated: 2020/09/23 15:27:30 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

extern t_hub		g_hub;
extern int volatile	g_stop;

short int	getstop(void)
{
	short int dostop;

	sem_wait(g_hub.stoplock);
	dostop = g_stop >= g_hub.phinfo.nbphilo;
	sem_post(g_hub.stoplock);
	return (dostop ? 1 : 0);
}

void		incstop(void)
{
	sem_wait(g_hub.stoplock);
	g_stop++;
	sem_post(g_hub.stoplock);
}

void		setstop(void)
{
	sem_wait(g_hub.stoplock);
	g_stop = g_hub.phinfo.nbphilo;
	sem_post(g_hub.stoplock);
}
