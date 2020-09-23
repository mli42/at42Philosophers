/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:16:50 by mli               #+#    #+#             */
/*   Updated: 2020/09/22 15:21:26 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

extern t_hub		g_hub;
extern int volatile	g_stop;

short int	getstop(void)
{
	short int dostop;

	pthread_mutex_lock(&g_hub.stoplock);
	dostop = g_stop >= g_hub.phinfo.nbphilo;
	pthread_mutex_unlock(&g_hub.stoplock);
	return (dostop ? 1 : 0);
}

void		incstop(void)
{
	pthread_mutex_lock(&g_hub.stoplock);
	g_stop++;
	pthread_mutex_unlock(&g_hub.stoplock);
}

void		setstop(void)
{
	pthread_mutex_lock(&g_hub.stoplock);
	g_stop = g_hub.phinfo.nbphilo;
	pthread_mutex_unlock(&g_hub.stoplock);
}
