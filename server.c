/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:47:32 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/03 18:18:41 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signum, siginfo_t *info, void *ucontext)
{
	static int		ascii;
	static int		bits;
	static pid_t	pid_client;

	(void)ucontext;
	if (!pid_client)
		pid_client = info->si_pid;
	if (info->si_pid != pid_client)
	{
		ascii = 0;
		bits = 0;
		pid_client = info->si_pid;
	}
	ascii = (ascii << 1) | (signum == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		ft_putchar(ascii);
		bits = 0;
		ascii = 0;
	}
}

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	sa;

	sa.sa_handler = NULL;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	pid_server = getpid();
	ft_putstr("SERVER PID : ");
	ft_putpid(pid_server);
	ft_putchar('\n');
	while (420)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_error("SIGACTION ERROR!");
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_error("SIGACTION ERROR!");
	}
	return (0);
}
