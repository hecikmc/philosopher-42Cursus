/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:58:42 by jmerchan          #+#    #+#             */
/*   Updated: 2023/05/11 12:34:06 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	ft_checklife(t_table *table, int i_philo)
{
	pthread_mutex_lock(&table->to_check);
	if (ft_dif_time(table->start) - table->philo[i_philo].last_eat
		> table->t_die)
	{
		table->dead = 1;
		printf("%lldms for %d to die\n", ft_dif_time(table->start),
			table->philo[i_philo].id);
	}
	pthread_mutex_unlock(&table->to_check);
	usleep(300);
}

static int	ft_all_ate(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philo)
	{
		if (table->philo[i].eat_count < table->n_eat)
			return (0);
	}
	return (1);
}

int	check_dead(t_table *table)
{
	int		dead;

	pthread_mutex_lock(&table->to_check);
	dead = table->dead;
	pthread_mutex_unlock(&table->to_check);
	return (dead);
}

void	*ft_is_death(void *tb)
{
	int		i;
	t_table	*table;

	table = tb;
	usleep(25);
	while (!check_dead(table))
	{
		i = -1;
		while (++i < table->n_philo && !check_dead(table))
			ft_checklife(table, i);
		if (!check_dead(table) && table->n_eat > 0 && ft_all_ate(table) == 1)
		{
			pthread_mutex_lock(&table->to_check);
			table->dead = 1;
			pthread_mutex_unlock(&table->to_check);
			printf("All philos ate %d times \n", table->n_eat);
			break ;
		}
	}
	usleep(300);
	return (0);
}
