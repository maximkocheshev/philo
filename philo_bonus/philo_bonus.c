/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:36:19 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/08 19:40:51 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_free(t_data *d)
{
	int		i;
	char	name[255];

	i = 0;
	while (i < d->num_of_philo)
		kill(d->philo[i++].id, SIGKILL);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("mutex");
	sem_unlink("somebody_dead");
	if (d->philo)
	{
		i = 0;
		while (i < d->num_of_philo)
		{
			ft_sem_name("stop_eat", (char *)name, i++);
			sem_unlink(name);
		}
		free(d->philo);
	}
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
		sem_wait(d->philo[i].stop_eat);
		i++;
	}
	sem_wait(d->print);
	printf("%lld All philosophers eat %d times!\n", ft_current_time() \
	- d->time_start, d->num_of_times_each_philo_must_eat);
	sem_post(d->somebody_dead);
	return (NULL);
}

static int	ft_start_process(t_data *d)
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
		d->philo[i].id = fork();
		if (d->philo[i].id < 0)
			return (1);
		else if (d->philo[i].id == 0)
		{
			ft_routine(&d->philo[i]);
			exit(0);
		}
		usleep(100);
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
			return (ft_free(&d));
		}
		if (ft_init(&d) == 1)
		{
			write(1, "Malloc or semaphore error\n", 26);
			return (ft_free(&d));
		}
		if (ft_start_process(&d) == 1)
		{
			write(1, "Process error\n", 22);
			return (ft_free(&d));
		}
		sem_wait(d.somebody_dead);
		ft_free(&d);
	}
	else
		return (ft_error_arg(argc));
	return (0);
}
