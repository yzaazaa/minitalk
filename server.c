/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 05:34:00 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/25 06:12:55 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_len(int *bit, char **str, int *is_alloc, int sig)
{
	static int	len;

	if (sig == SIGUSR1)
		len += ft_recursive_power(2, *bit);
	if (*bit == 31)
	{
		*is_alloc = 2;
		*str = malloc(len + 1);
		*bit = 0;
		len = 0;
		return ;
	}
	(*bit)++;
}

static void	ft_pid(int *bit, int *is_calloc, int sig, int *pid)
{
	if (sig == SIGUSR1)
		*pid += ft_recursive_power(2, *bit);
	if (*bit == 31)
	{
		*is_calloc = 1;
		*bit = 0;
		return ;
	}
	(*bit)++;
}

static void	restart_vars(int *is_alloc, char **str, int *i, int *pid)
{
	*is_alloc = 0;
	if (str)
	{
		kill(*pid, SIGUSR1);
		usleep(100);
		ft_putstr_fd(*str, 1);
		ft_putstr_fd("\n", 1);
		free(*str);
		*str = NULL;
	}
	*pid = 0;
	*i = 0;
}

static void	handler(int sig)
{
	static t_data	data;
	static int		i;

	if (!data.is_alloc)
		ft_pid(&data.bit, &data.is_alloc, sig, &data.pid);
	else if (data.is_alloc == 1)
		ft_len(&data.bit, &data.str, &data.is_alloc, sig);
	else
	{
		if (sig == SIGUSR1)
			data.ascii += ft_recursive_power(2, data.bit);
		if (data.bit == 7)
		{
			data.str[i++] = data.ascii;
			data.bit = 0;
			if (data.ascii == 0)
			{
				restart_vars(&data.is_alloc, &data.str, &i, &data.pid);
				return ;
			}
			data.ascii = 0;
			return ;
		}
		data.bit++;
	}
}

int	main(void)
{
	int	id;

	id = (int)getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(id, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		usleep(100);
}
