/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:39:45 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/05 14:46:14 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_digits(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	ft_parsing(int argc, char **argv, t_data *d)
{
	if (ft_check_digits(argc, argv) == 1)
		return (1);
	d->num_of_philo = ft_atoi(argv[1]);
	d->time_to_die = ft_atoi(argv[2]);
	d->time_to_eat = ft_atoi(argv[3]);
	d->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		d->num_of_times_each_philo_must_eat = -1;
	if (d->num_of_philo <= 0 || d->time_to_die <= 0 \
	|| d->time_to_eat <= 0 || d->time_to_sleep <= 0 \
	|| (argv[5] && d->num_of_times_each_philo_must_eat <= 0))
		return (1);
	return (0);
}
