/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:11:33 by mli               #+#    #+#             */
/*   Updated: 2020/09/18 14:59:43 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** Fills the t_phinfo structure
** Since its full of integers, one can cast this struct into int *
*/

int		ft_parser(t_phinfo *phinfo, char **argv)
{
	int		i;
	int		*iphinfo;

	i = (argv[5] == NULL ? 4 : 5);
	iphinfo = (int *)phinfo;
	while (--i >= 0)
		if (ft_atoi_isdigit(argv[i + 1], &iphinfo[i]) == 0 || iphinfo[i] < 1)
			return (0);
	return (1);
}
