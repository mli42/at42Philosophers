/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:56:04 by mli               #+#    #+#             */
/*   Updated: 2020/09/20 23:25:00 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static char	*ft_strcpystr(char **dest, const char *src)
{
	while (*src)
		*(*dest)++ = *(src++);
	return (*dest);
}

static void	ft_itostr(unsigned long int nbr, char **str)
{
	int			tmp;
	int			nbrsize;
	const int	begin = ((int)nbr >= 0 ? 0 : 1);

	nbrsize = ft_nbrlen(nbr);
	tmp = nbrsize;
	if ((int)nbr < 0)
	{
		nbr *= -1;
		*(*str) = '-';
	}
	while (--nbrsize >= begin)
	{
		(*str)[nbrsize] = (nbr % 10) + '0';
		nbr /= 10;
	}
	*str += tmp;
}

void		ft_logs(unsigned const long int timestamp,
		unsigned short int philosnb, unsigned short int const state)
{
	char		log[128];
	char		*tmp;
	const char	*strstates[] = {"has taken a fork", "is eating", "is sleeping",
		"is thinking", "died"};

	tmp = log;
	ft_itostr(timestamp, &tmp);
	*(tmp++) = ' ';
	ft_itostr(philosnb, &tmp);
	*(tmp++) = ' ';
	ft_strcpystr(&tmp, strstates[state]);
	*(tmp++) = '\n';
	*(tmp++) = '\0';
	write(1, log, ft_strlen(log));
}
