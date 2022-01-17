/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:01:52 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/08 12:53:19 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <unistd.h> // write, usleep
# include <pthread.h> // pthread_t
# include <sys/time.h> // struct timeval, gettimeofday

typedef struct s_philo
{
	int				pid;
	int				count_eat;
	long long		last_eat;
	struct s_data	*d;
	pthread_t		tid;
	pthread_t		wait;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	pthread_mutex_t	mutex;
	pthread_mutex_t	stop_eat;
}	t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	long long		time_start;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	somebody_dead;
}	t_data;

int			ft_parsing(int argc, char **argv, t_data *d);
int			ft_atoi(const char *str);
int			ft_init(t_data *d);
long long	ft_current_time(void);
void		*ft_routine(void *philo_v);
void		ft_print_message(t_data *d, int pid, char *msg);
int			ft_error_arg(int argc);

#endif