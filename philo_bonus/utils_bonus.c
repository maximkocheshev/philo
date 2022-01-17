/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:53:13 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/09 16:26:49 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	ft_usleep(int time_action)
{
	long	start;

	start = ft_current_time();
	while (ft_current_time() < start + time_action)
		usleep(10);
}

void	ft_print_message(t_data *d, int pid, char *msg)
{
	long long	time_work;

	time_work = ft_current_time() - d->time_start;
	sem_wait(d->print);
	printf("%lld %d %s\n", time_work, pid, msg);
	sem_post(d->print);
}
