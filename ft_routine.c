/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:42:36 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/08 18:59:01 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_wait(void *philo_v)
{
	t_philo		*philo;
	long long	time_without_eating;

	philo = (t_philo *)philo_v;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		time_without_eating = ft_current_time() - philo->last_eat;
		if (time_without_eating > philo->d->time_to_die)
		{
			ft_print_message(philo->d, philo->pid, "died");
			pthread_mutex_lock(&(philo->d->print));
			pthread_mutex_unlock(&philo->d->somebody_dead);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
}

static void	ft_take_forks(t_philo *philo)
{
	if ((philo->pid % 2) == 0 && philo->count_eat == 0)
		usleep(philo->d->num_of_philo / 2 * philo->d->time_to_eat);
	pthread_mutex_lock(philo->first_fork);
	ft_print_message(philo->d, philo->pid, "has taken a fork");
	pthread_mutex_lock(philo->second_fork);
	ft_print_message(philo->d, philo->pid, "has taken a fork");
}

static void	ft_eat(t_philo *philo)
{
	ft_print_message(philo->d, philo->pid, "is eating");
	philo->last_eat = ft_current_time();
	usleep(philo->d->time_to_eat * 1000);
	philo->count_eat++;
	if (philo->d->num_of_times_each_philo_must_eat != -1 && \
	philo->count_eat == philo->d->num_of_times_each_philo_must_eat)
		pthread_mutex_unlock(&philo->stop_eat);
}

static void	ft_sleep(t_philo *philo)
{
	ft_print_message(philo->d, philo->pid, "is sleeping");
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	usleep(philo->d->time_to_sleep * 1000);
	ft_print_message(philo->d, philo->pid, "is thinking");
}

void	*ft_routine(void *philo_v)
{
	t_philo		*philo;

	philo = (t_philo *)philo_v;
	if (pthread_create(&philo->wait, NULL, &ft_wait, philo) != 0)
		return (NULL);
	pthread_detach(philo->wait);
	while (1)
	{
		ft_take_forks(philo);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}
