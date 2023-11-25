/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 05:34:00 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/25 03:49:33 by yzaazaa          ###   ########.fr       */
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
		*str = ft_calloc(len + 1, sizeof(char));
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

static void	restart_vars(int *is_alloc, char **str, int *i, int pid)
{
	*is_alloc = 0;
	if (str)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		ft_putstr_fd(*str, 1);
		ft_putstr_fd("\n", 1);
		free(*str);
		*str = NULL;
	}
	*i = 0;
}

static void	handler(int sig)
{
	static int	ascii;
	static int 	bit;
	static int  is_alloc;
	static int	i;
	static char	*str;
	static int	pid;

	if (!is_alloc)
		ft_pid(&bit, &is_alloc, sig, &pid);
	else if (is_alloc == 1)
		ft_len(&bit, &str, &is_alloc, sig);
	else
	{
		if (sig == SIGUSR1)
			ascii += ft_recursive_power(2, bit);
		if (bit == 7)
		{
			str[i++] = ascii;
			bit = 0;
			if (ascii == 0)
			{
				restart_vars(&is_alloc, &str, &i, pid);
				pid = 0;
				return ;
			}
			ascii = 0;
			return ;
		}
		bit++;
	}
}

int	main()
{
	int	id;

	id = (int)getpid();
	ft_putnbr_fd(id, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		usleep(100);
}