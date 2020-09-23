/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:58:32 by mli               #+#    #+#             */
/*   Updated: 2020/09/23 10:31:36 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		ft_nbrlen_base(long unsigned int nb, unsigned long int const base_len)
{
	int size;

	size = 0;
	if (nb <= 0)
		size++;
	while (nb != 0)
	{
		nb /= base_len;
		size++;
	}
	return (size);
}

int		ft_nbrlen(long unsigned int nb)
{
	return (ft_nbrlen_base(nb, 10));
}

/*
** Basic atoi function, but checks if the string passed as parameters
** contains only digits:
** On success, fills the pointer on int passed and returns 1
** Otherwise does not modify any pointer and returns 0
*/

int		ft_atoi_isdigit(const char *str, int *nbr)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = (10 * result) + str[i++] - '0';
	if (str[i] != '\0')
		return (0);
	*nbr = (result * sign);
	return (1);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
