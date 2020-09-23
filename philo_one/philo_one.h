/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:38:41 by mli               #+#    #+#             */
/*   Updated: 2020/09/23 10:53:14 by mli              ###   ########.fr       */
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
	pthread_mutex_t	lock;
	int				taken : 8;
}				t_fork;

typedef struct	s_philo
{
	pthread_t			thread;
	t_fork				my_fork;
	t_fork				*neighbours_fork;
	int					index;
	unsigned short int	eaten_meals;
	unsigned long int	last_meal;
}				t_philo;

typedef struct	s_hub
{
	t_phinfo			phinfo;
	unsigned long int	start_time;
	pthread_mutex_t		stoplock;
}				t_hub;

/*
** Global variables:
*/

int	volatile	g_stop;
t_hub			g_hub;

int				ft_initialization(t_philo **philos, char **argv);
int				ft_exit(t_philo **philos, const char *error);
int				ft_parser(t_phinfo *phinfo, char **argv);

void			ft_destructor(t_philo **philos);

void			ft_logs(unsigned const long int timestamp,
		unsigned short int philosnb, unsigned short int const state);

unsigned long	ft_gettime(void);
void			dosleep(unsigned long int ms);

void			*ft_philo(void *arg);

short int		getstop(void);
void			incstop(void);
void			setstop(void);

/*
** Utils functions:
*/

void			*ft_memalloc(size_t size);
size_t			ft_strlen(const char *const str);

int				ft_isdigit(int c);

void			ft_putstr_fd(const char *const str, const int fd);
void			ft_putendl_fd(const char *const str, const int fd);

void			ft_free(void **ptr);
int				ft_nbrlen_base(long unsigned int nb,
		unsigned long int const base_len);
int				ft_nbrlen(long unsigned int nb);

int				ft_atoi_isdigit(const char *str, int *nbr);

#endif
