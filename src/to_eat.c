/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:57:02 by jmerchan          #+#    #+#             */
/*   Updated: 2023/05/11 12:28:36 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	to_wait(t_table *table, int time)
{
	int	wait_init;

	wait_init = ft_dif_time(table->start);
	while (ft_dif_time(table->start) - wait_init < time)
		usleep(10);
}

static void	ft_chew(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->forks[philo->right_f]);
	msg(table, philo->id, "has taken his rigth fork");
	pthread_mutex_lock(&table->forks[philo->left_f]);
	msg(table, philo->id, "has taken his left fork");
	if (!check_dead(table))
	{
		pthread_mutex_lock(&table->to_check);
		philo->last_eat = ft_dif_time(table->start);
		philo->eat_count++;
		pthread_mutex_unlock(&table->to_check);
		msg(table, philo->id, "is eating");
		to_wait(table, table->t_eat);
	}
	pthread_mutex_unlock(&table->forks[philo->right_f]);
	pthread_mutex_unlock(&table->forks[philo->left_f]);
}

void	*ft_to_eat(void *ph)
{
	t_table	*table;
	t_philo	*philo;

	philo = ph;
	table = philo->table;
	usleep(25);
	philo->right_f = philo->id - 1;
	if (philo->id == table->n_philo)
		philo->left_f = 0;
	else
		philo->left_f = philo->id;
	if (philo->id % 2 != 0)
		usleep(250);
	while (!check_dead(table))
	{
		ft_chew(philo, table);
		if (!check_dead(table))
		{
			msg(table, philo->id, "is sleeping");
			usleep(table->t_sleep * 1000);
		}
		if (!check_dead(table))
			msg(table, philo->id, "is thinking");
	}
	return (0);
}

/* void	ft_check_meals(t_table *table)
{
	int		meals;

	pthread_mutex_lock(&table->to_check);
	meals = table->dead;
	pthread_mutex_unlock(&table->to_check);
	return (dead);
} */

/* if (check_dead(table))
			break ; */