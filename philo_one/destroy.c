/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:35:32 by mli               #+#    #+#             */
/*   Updated: 2020/09/20 16:46:11 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_destroy_hub(t_hub *hub)
{
	if (!hub)
		return ;
	if (hub->philos)
		ft_destroy_philo(&hub->philos);
}

void	ft_destroy_philo(t_philo **philos)
{
	ft_free((void **)philos);
}
