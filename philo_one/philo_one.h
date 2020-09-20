/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:38:41 by mli               #+#    #+#             */
/*   Updated: 2020/09/20 18:11:19 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <pthread.h>
# include <sys/time.h>

# include "./utils/libft.h"

int				g_stop;

enum			e_ph_activity
{
	e_DIE,
	e_EAT,
	e_SLEEP,
	e_ACTIVITY_END
};

enum			e_ph_state
{
	e_TAKING_FORK,
	e_EATING,
	e_SLEEPING,
	e_THINKING,
	e_DYING,
	e_STATE_END
};

typedef struct	s_phinfo
{
	int		nbphilo;
	int		time_to[e_ACTIVITY_END];
	int		must_eat;
}				t_phinfo;

typedef struct	s_fork
{
	int		taken : 8;
}				t_fork;

typedef struct	s_philo
{
	t_fork			my_fork;
	t_fork			*neighbours_fork;
	int				index;
	unsigned int	eaten_meals;
}				t_philo;

typedef struct	s_hub
{
	t_phinfo	phinfo;
	double		start_time;
	t_philo		*philos;
}				t_hub;

int				ft_hubinit(t_hub *hub, char **argv);
int				ft_exit(t_hub *hub, const char *error);
double			ft_gettime(void);
int				ft_parser(t_phinfo *phinfo, char **argv);

void			ft_destroy_hub(t_hub *hub);
void			ft_destroy_philo(t_philo **philos);

void			ft_philoinit(t_philo *philos, int nbphilo);

void			ft_logs(unsigned const long int timestamp,
		unsigned short int philosnb, unsigned short int const state);

#endif
