/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:38:41 by mli               #+#    #+#             */
/*   Updated: 2020/09/16 16:59:05 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <pthread.h>
# include <sys/time.h>

enum			ph_activity
{
	e_DIE,
	e_EAT,
	e_SLEEP,
	e_ACTIVITY_END
};

typedef struct	s_phinfo
{
	int		nbphilo;
	int		activity[e_ACTIVITY_END];
	int		must_eat;
}				t_phinfo;

typedef struct	s_fork
{
	bool	taken;
}				t_fork;

typedef struct	s_philo
{
	t_fork		my_fork;
	t_fork		*neighbours_fork;
}				t_philo;

typedef struct	s_hub
{
	t_phinfo	phinfo;
	double		start_time;
	t_philo		*philos;
}				t_hub;

int				ft_hubinit(t_hub *hub, int argc, char **argv);
int				ft_exit(t_hub *hub, const char *error);
double			ft_gettime(void);
int				ft_strlen(const char * const str);
void			ft_putstr_fd(const char * const str, const int fd);
void			ft_putendl_fd(const char * const str, const int fd);

#endif
