/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:41:23 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/08 16:15:15 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_mutex(t_data *d)
{
	int	i;

	d->fork = malloc(sizeof(pthread_mutex_t) * d->num_of_philo);
	if (d->fork == NULL)
		return (1);
	i = 0;
	while (i < d->num_of_philo)
	{
		pthread_mutex_init(&d->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&d->print, NULL);
	pthread_mutex_init(&d->somebody_dead, NULL);
	pthread_mutex_lock(&d->somebody_dead);
	return (0);
}

static int	ft_init_philo(t_data *d)
{
	int	i;

	d->philo = (t_philo *)malloc(sizeof(t_philo) * d->num_of_philo);
	if (d->philo == NULL)
		return (1);
	i = 0;
	while (i < d->num_of_philo)
	{
		d->philo[i].d = d;
		d->philo[i].pid = i + 1;
		d->philo[i].count_eat = 0;
		d->philo[i].last_eat = ft_current_time();
		d->philo[i].first_fork = &d->fork[i];
		d->philo[i].second_fork = &d->fork[(i + 1) % d->num_of_philo];
		pthread_mutex_init(&d->philo[i].mutex, NULL);
		pthread_mutex_init(&d->philo[i].stop_eat, NULL);
		pthread_mutex_lock(&d->philo[i].stop_eat);
		i++;
	}
	return (0);
}

int	ft_init(t_data *d)
{
	if (ft_init_mutex(d) == 1)
		return (1);
	if (ft_init_philo(d) == 1)
		return (1);
	return (0);
}
