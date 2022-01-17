/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:07:13 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/09 16:26:40 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h> // write
# include <pthread.h> // pthread_t
# include <fcntl.h> // O_CREAT
# include <semaphore.h> // sem_t
# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <sys/time.h> // struct timeval, gettimeofday
# include <signal.h> // kill

typedef struct s_philo
{
	int				pid;
	int				count_eat;
	long long		last_eat;
	struct s_data	*d;
	pid_t			id;
	pthread_t		wait;
	sem_t			*stop_eat;
}	t_philo;

typedef struct s_data
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_times_each_philo_must_eat;
	long long	time_start;
	t_philo		*philo;
	sem_t		*fork;
	sem_t		*print;
	sem_t		*mutex;
	sem_t		*somebody_dead;
}	t_data;

int			ft_parsing(int argc, char **argv, t_data *d);
int			ft_atoi(const char *str);
int			ft_init(t_data *d);
long long	ft_current_time(void);
char		*ft_sem_name(char const *base, char *name, int pos);
int			ft_strcpy(char *dst, const char *src);
int			ft_routine(void *philo_v);
void		ft_print_message(t_data *d, int pid, char *msg);
void		ft_usleep(int time);
int			ft_error_arg(int argc);

#endif