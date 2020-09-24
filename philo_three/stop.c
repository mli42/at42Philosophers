/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:16:50 by mli               #+#    #+#             */
/*   Updated: 2020/09/25 00:36:40 by mli              ###   ########.fr       */
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
	sem_post(g_semstop);
}
