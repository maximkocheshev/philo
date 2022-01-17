/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:54:21 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/08 11:28:47 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_arg(int argc)
{
	if (argc > 6)
		write(1, "Too many arguments\n", 19);
	else if (argc < 5)
		write(1, "Too few arguments\n", 18);
	return (1);
}

long long	ft_current_time(void)
{
	struct timeval	current_time;
	long long		ms;

	gettimeofday(&current_time, NULL);
	ms = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (ms);
}

void	ft_print_message(t_data *d, int pid, char *msg)
{
	long long	time_work;

	time_work = ft_current_time() - d->time_start;
	pthread_mutex_lock(&(d->print));
	printf("%lld %d %s\n", time_work, pid, msg);
	pthread_mutex_unlock(&(d->print));
}
