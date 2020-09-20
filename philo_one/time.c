/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:58:32 by mli               #+#    #+#             */
/*   Updated: 2020/09/20 19:28:28 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** Returns time in milliseconds
*/

unsigned long int	ft_gettime(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

/*
** More precise usleep
*/

void				dosleep(const unsigned long int ms)
{
	const unsigned long int start = ft_gettime();

	while (ft_gettime() - start < ms)
		usleep(400);
}
