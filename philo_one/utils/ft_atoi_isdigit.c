/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:14:46 by mli               #+#    #+#             */
/*   Updated: 2020/09/18 14:29:27 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
