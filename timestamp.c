/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:25:10 by mli               #+#    #+#             */
/*   Updated: 2020/09/20 16:29:24 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long int	get_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

void				dosleep(const unsigned int microseconds)
{
	const unsigned long int	milliseconds = microseconds / 1000;
	const unsigned long int start = get_time();

	while (get_time() - start < milliseconds)
		usleep(400);
}

int					main(void)
{
	unsigned int	start_time;
	unsigned int	curr_time;
	unsigned int	prev_time;

	prev_time = 0;
	start_time = get_time();
	while (1)
	{
		curr_time = get_time() - start_time;
		// Print time from start, in ms
		printf("%ld\t\t[%d]\n", (long int)curr_time, curr_time - prev_time);
		prev_time = curr_time;
		// Sleep 200 times 1000 microseconds (1 millisecond)
		dosleep(200 * 1000);
	}
}
