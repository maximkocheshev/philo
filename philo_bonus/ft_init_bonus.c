/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:17:10 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/08 16:51:11 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_init_semaphores(t_data *d)
{
	sem_unlink("fork");
	d->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, d->num_of_philo);
	sem_unlink("print");
	d->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("mutex");
	d->mutex = sem_open("mutex", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("somebody_dead");
	d->somebody_dead = sem_open("somebody_dead", O_CREAT | O_EXCL, 0644, 0);
	if (d->fork < 0 || d->print < 0 || d->mutex < 0 || d->somebody_dead < 0)
		return (1);
	return (0);
}

char	*ft_sem_name(char const *base, char *name, int pos)
{
	int	i;

	i = ft_strcpy(name, base);
	while (pos > 0)
	{
		name[i++] = (pos % 10) + '0';
		pos /= 10;
	}
	name[i] = 0;
	return (name);
}

static int	ft_init_philo(t_data *d)
{
	int		i;
	char	name[250];

	d->philo = malloc(sizeof(t_philo) * d->num_of_philo);
	if (d->philo == NULL)
		return (1);
	i = 0;
	while (i < d->num_of_philo)
	{
		d->philo[i].d = d;
		d->philo[i].pid = i + 1;
		d->philo[i].id = 0;
		d->philo[i].count_eat = 0;
		d->philo[i].last_eat = ft_current_time();
		ft_sem_name("stop_eat", (char *)name, i);
		sem_unlink(name);
		d->philo[i].stop_eat = sem_open(name, O_CREAT | O_EXCL, 0644, 0);
		if (d->philo[i].stop_eat < 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_init(t_data *d)
{
	if (ft_init_semaphores(d) == 1)
		return (1);
	if (ft_init_philo(d) == 1)
		return (1);
	return (0);
}
