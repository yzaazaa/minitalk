/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:54:02 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/03 18:17:29 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	check_args(int ac, char **av)
{
	if (ac != 3)
		ft_error("Usage: ./client [PID] [MESSAGE]\n");
	if (ft_atoi(av[1]) <= 0)
		ft_error("Invalid PID\n");
}

static void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c << i & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Couldn't send signal!\n");
		}
		else 
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Couldn't send signal!\n");
		usleep(200);
		i++;
	}
}

static void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_char(pid, (unsigned char)str[i++]);
	send_char(pid, (unsigned char)str[i]);
}

int	main(int ac, char **av)
{
	int	pid_server;

	check_args(ac, av);
	pid_server = ft_atoi(av[1]);
	send_str(pid_server, av[2]);
	return (0);
}
