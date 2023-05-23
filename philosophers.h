/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:02:10 by jmerchan          #+#    #+#             */
/*   Updated: 2023/05/11 10:59:12 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	void			*table;
	pthread_t		soul;
	int				id;
	int				left_f;
	int				right_f;
	int				last_eat;
	int				eat_count;
	pthread_mutex_t	*to_check;
}	t_philo;

typedef struct s_table
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	long long		start;
	int				dead;
	t_philo			*philo;
	pthread_mutex_t	to_check;
	pthread_mutex_t	*forks;
	pthread_t		checker;
}	t_table;

//philosopphers.c
void		ft_create_philos(t_table *table);
void		ft_inittable(t_table *table, char **argv);

//error.c
void		ft_msgerror(char *error);
void		ft_freeall(t_table *table);

//utils.c
int			ft_atoi(const char *str);
long long	ft_get_time(void);
long long	ft_dif_time(long long now);
void		msg(t_table *table, int id, char *str);

//to_death.c
void		*ft_is_death(void *tb);
int			check_dead(t_table *table);

//to_eat.c
void		*ft_to_eat(void *ph);
#endif