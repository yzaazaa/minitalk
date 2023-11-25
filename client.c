/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 05:33:53 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/25 05:58:13 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received = 0;

static void	send_char(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(100);
		i++;
	}
}

static void	send_num(int num, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (num & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		num = num >> 1;
		usleep(100);
		i++;
	}
}

static void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Message received by server\n", 1);
		g_received = 1;
	}
}

static void	init_vars(int *pid, char **str, char **av)
{
	*pid = ft_atoi(av[1]);
	if (*pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		exit(1);
	}
	*str = av[2];
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;
	int		len;
	int		i;
	int		id;

	signal(SIGUSR1, handler);
	check_args(ac, av);
	init_vars(&pid, &str, av);
	len = ft_strlen(str);
	id = (int)getpid();
	send_num(id, pid);
	send_num(len, pid);
	i = 0;
	while (str[i])
		send_char(str[i++], pid);
	send_char(str[i], pid);
	while (!g_received)
		usleep(100);
	g_received = 0;
	return (0);
}
