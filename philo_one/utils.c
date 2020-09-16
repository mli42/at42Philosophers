/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:58:32 by mli               #+#    #+#             */
/*   Updated: 2020/09/16 16:49:37 by mli              ###   ########.fr       */
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

int		ft_strlen(const char * const str)
{
	const char *tmp = str;

	while (*tmp)
		tmp++;
	return (tmp - str);
}

void	ft_putstr_fd(const char * const str, const int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putendl_fd(const char * const str, const int fd)
{
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}
