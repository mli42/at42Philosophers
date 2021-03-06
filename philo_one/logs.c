/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:56:04 by mli               #+#    #+#             */
/*   Updated: 2020/09/22 11:36:32 by mli              ###   ########.fr       */
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

	nbrsize = ft_nbrlen(nbr);
	tmp = nbrsize;
	while (--nbrsize >= 0)
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

	if (getstop())
		return ;
	tmp = log;
	*(tmp++) = '[';
	ft_itostr(timestamp, &tmp);
	*(tmp++) = ']';
	*(tmp++) = ' ';
	ft_itostr(philosnb, &tmp);
	*(tmp++) = ' ';
	ft_strcpystr(&tmp, strstates[state]);
	*(tmp++) = '\n';
	*(tmp++) = '\0';
	write(1, log, ft_strlen(log));
}
