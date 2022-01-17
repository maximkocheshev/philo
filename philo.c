/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:16:40 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/08 18:39:36 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_free(t_data *d)
{
	int	i;

	if (d->fork)
	{
		i = 0;
		while (i < d->num_of_philo)
			pthread_mutex_destroy(&d->fork[i++]);
		free(d->fork);
	}
	if (d->philo)
	{
		i = 0;
		while (i < d->num_of_philo)
		{
			pthread_mutex_destroy(&d->philo[i].mutex);
			pthread_mutex_destroy(&d->philo[i++].stop_eat);
		}
		free(d->philo);
	}
	pthread_mutex_destroy(&d->print);
	pthread_mutex_destroy(&d->somebody_dead);
	return (1);
}

static void	*ft_monitor(void *d_v)
{
	t_data	*d;
	int		i;

	d = (t_data *)d_v;
	i = 0;
	while (i < d->num_of_philo)
	{
		pthread_mutex_lock(&d->philo[i].stop_eat);
		i++;
	}
	pthread_mutex_lock(&(d->print));
	printf("%lld All philosophers eat at least %d times!\n", \
	ft_current_time() - d->time_start, d->num_of_times_each_philo_must_eat);
	pthread_mutex_unlock(&d->somebody_dead);
	return (NULL);
}

static int	ft_pthread_create(t_data *d)
{
	pthread_t	tid;
	int			i;

	if (d->num_of_times_each_philo_must_eat > -1)
	{
		if (pthread_create(&tid, NULL, &ft_monitor, (void *)d) != 0)
			return (1);
		pthread_detach(tid);
	}
	d->time_start = ft_current_time();
	i = 0;
	while (i < d->num_of_philo)
	{
		if (pthread_create(\
		&d->philo[i].tid, NULL, &ft_routine, &d->philo[i]) != 0)
			return (1);
		pthread_detach(d->philo[i].tid);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc == 5 || argc == 6)
	{
		if (ft_parsing(argc, argv, &d) == 1)
		{
			write(1, "Invalid arguments\n", 18);
			return (1);
		}
		if (ft_init(&d) == 1)
		{
			write(1, "Malloc error\n", 22);
			return (ft_free(&d));
		}
		if (ft_pthread_create(&d) == 1)
		{
			write(1, "Pthread error\n", 22);
			return (ft_free(&d));
		}
		pthread_mutex_lock(&d.somebody_dead);
		ft_free(&d);
	}
	else
		return (ft_error_arg(argc));
	return (0);
}
