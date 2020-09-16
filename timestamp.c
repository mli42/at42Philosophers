/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:25:10 by mli               #+#    #+#             */
/*   Updated: 2020/09/16 13:28:59 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

double	get_time(void)
{
	struct timeval	tp;
	double			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += (double)tp.tv_usec / 1000;
	return (milliseconds);
}

void	dosleep(int const microseconds)
{
	static const int	divide = 0;
	const int			cut = microseconds >> divide;
	usleep(cut);
//	usleep(cut);
}

int		main(void)
{
	double	start_time;
	double	curr_time;
	double	prev_time;

	prev_time = 0;
	start_time = get_time();
	while (1)
	{
	//	static int i = 0;
		curr_time = get_time() - start_time;
		// Print time from start, in ms
		printf("%ld\t\t[%lf]\n", (long int)curr_time, curr_time - prev_time - 200);
		prev_time = curr_time;
		// Sleep 200 times 1000 microseconds (1 millisecond)
		dosleep(200 * 1000);
	}
}
