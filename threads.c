/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:29:42 by mli               #+#    #+#             */
/*   Updated: 2020/09/18 11:35:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		hey = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void	ft_heyinc(void)
{
	pthread_mutex_lock(&lock);
	hey++;
	pthread_mutex_unlock(&lock);
}

void	*second(void *tmp)
{
	sleep(10);
	write(1, "2\n", 2);
	ft_heyinc();
	return (tmp);
}

void	*first(void *tmp)
{
	pthread_t pth_nd;

	pthread_create(&pth_nd, NULL, second, NULL);
	write(1, "1\n", 2);
	ft_heyinc();
	return (tmp);
}

int		main(void)
{
	pthread_t pth_st;

	pthread_create(&pth_st, NULL, first, NULL);

	pthread_join(pth_st, NULL);
	printf("main finished\they content [%d]\n", hey);
	pthread_mutex_destroy(&lock);
	return (0);
}
