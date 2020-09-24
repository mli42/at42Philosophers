/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:05:48 by mli               #+#    #+#             */
/*   Updated: 2020/09/24 16:27:03 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <pthread.h>
# include <sys/time.h>

# include <semaphore.h>
# include <sys/sem.h>

# include <signal.h>

# define FORK_SEM "philo_forks"
# define PH_STOP_SEM "philo_stop"
# define PH_SEMSTOP "philo_semstop"

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

typedef struct	s_philo
{
	pid_t				pid;
	int					index;
	unsigned short int	eaten_meals;
	unsigned long int	last_meal;
}				t_philo;

typedef struct	s_hub
{
	t_phinfo			phinfo;
	unsigned long int	start_time;
	sem_t				*stoplock;
	sem_t				*forks;
	sem_t				*someone_died;
}				t_hub;

/*
** Global variables:
*/

int	volatile	g_stop;
t_hub			g_hub;
sem_t			*g_semstop;

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
