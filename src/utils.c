/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:41:32 by jmerchan          #+#    #+#             */
/*   Updated: 2023/05/11 12:28:20 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	ft_isdigit(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	r;

	i = 0;
	sign = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || sign == -1)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	if (r > INT_MAX || ft_isdigit(str) == 0)
		return (-1);
	return (sign * r);
}

long long	ft_get_time(void)
{
	struct timeval	time;
	long long		now;

	gettimeofday(&time, NULL);
	now = (long long)time.tv_sec * 1000 + time.tv_usec / 1000;
	return (now);
}

long long	ft_dif_time(long long time)
{
	return (ft_get_time() - time);
}

void	msg(t_table *table, int id, char *str)
{
	printf("%lld %d %s\n", ft_dif_time(table->start), id, str);
}
