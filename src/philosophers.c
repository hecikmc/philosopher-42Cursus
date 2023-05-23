/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:58:45 by jmerchan          #+#    #+#             */
/*   Updated: 2023/05/11 12:36:40 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_inittable(t_table *table, char **argv)
{
	int	i;
	int	data;

	i = 0;
	table->n_eat = -1;
	while (argv[++i] != 0)
	{
		data = ft_atoi(argv[i]);
		if (data < 0)
			ft_msgerror("the data must be a number between 0 and 2147483647.");
		if (i == 1)
		{
			if (data == 0)
				ft_msgerror("Invalid number of philosophers, 1 minimum.");
			table->n_philo = data;
		}
		else if (i == 2)
			table->t_die = data;
		else if (i == 3)
			table->t_eat = data;
		else if (i == 4)
			table->t_sleep = data;
		else if (i == 5)
			table->n_eat = data;
	}
}

void	ft_create_philos(t_table *table)
{
	int	i;

	table->philo = malloc(sizeof(t_philo) * table->n_philo);
	if (!table->philo)
		ft_msgerror("Memory allocated failed (philo)");
	i = -1;
	while (++i < table->n_philo)
	{
		table->philo[i].to_check = &table->to_check;
		pthread_mutex_lock(&table->to_check);
		table->philo[i].table = table;
		table->philo[i].id = i + 1;
		table->philo[i].last_eat = 0;
		table->philo[i].eat_count = 0;
		pthread_mutex_unlock(&table->to_check);
		if (pthread_create(&table->philo[i].soul, NULL,
				ft_to_eat, &table->philo[i]) != 0)
			ft_msgerror("Creating philo");
	}
}

void	ft_create_fork(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->forks)
		ft_msgerror("Memory allocating forks");
	i = -1;
	while (++i < table->n_philo)
	{
		if (pthread_mutex_init(&table->forks[i], 0))
			ft_msgerror("Creating forks");
	}
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	i = -1;
	if (argc < 5 || argc > 6)
		ft_msgerror("Invalid number of arguments.");
	table.dead = 0;
	ft_inittable(&table, argv);
	table.start = ft_get_time();
	if (pthread_mutex_init(&table.to_check, 0) != 0)
		ft_msgerror("Creating mutex");
	ft_create_fork(&table);
	if (pthread_create(&table.checker, 0, ft_is_death, &table) != 0)
		ft_msgerror("Creating checker thread");
	ft_create_philos(&table);
	pthread_join(table.checker, NULL);
	ft_freeall(&table);
	return (0);
}
