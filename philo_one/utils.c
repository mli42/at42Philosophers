/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:58:32 by mli               #+#    #+#             */
/*   Updated: 2020/09/18 12:31:29 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** Returns time in milliseconds
*/

double		ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)(tv.tv_sec * 1000) + ((double)tv.tv_usec / 1000));
}
