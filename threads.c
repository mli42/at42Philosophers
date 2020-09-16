/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:29:42 by mli               #+#    #+#             */
/*   Updated: 2020/09/16 14:16:03 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		hey = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void	*first(void *tmp)
{
	write(1, "1\n", 2);
		pthread_mutex_lock(&lock);
		hey++;
		pthread_mutex_unlock(&lock);
	return (tmp);
}

void	*ft_nd(void *tmp)
{
	write(1, "2\n", 2);
		pthread_mutex_lock(&lock);
		hey++;
		pthread_mutex_unlock(&lock);
	return (tmp);
}

int		main(void)
{
	pthread_t pth_st;
	pthread_t pth_nd;

	pthread_create(&pth_st, NULL, first, NULL);
	pthread_create(&pth_nd, NULL, ft_nd, NULL);

	pthread_join(pth_st, NULL);
	pthread_join(pth_nd, NULL);
	printf("main finished\t%d\n", hey);
	pthread_mutex_destroy(&lock);
	return (0);
}
