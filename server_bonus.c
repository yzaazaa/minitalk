/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:47:32 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/03 18:18:50 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_data
{
	int				ascii;
	int				nb_bytes;
	int				i;
	unsigned char	c[4];
	int				bits;
	pid_t			pid_client;
}	t_data;

static void	restart_args(int *arg1, int *arg2)
{
	*arg1 = 0;
	*arg2 = 0;
}

static void	send_sig_received(pid_t pid_client)
{
	if (kill(pid_client, SIGUSR2) == -1)
		ft_error("Couldn't send signal!\n");
	usleep(200);
}

static void	unicode(t_data *data)
{
	if (!data->i)
	{
		if (data->ascii >= 240)
			data->nb_bytes = 4;
		else if (data->ascii >= 224)
			data->nb_bytes = 3;
		else if (data->ascii >= 192)
			data->nb_bytes = 2;
	}
	if (data->nb_bytes && data->i < data->nb_bytes)
		data->c[data->i++] = data->ascii;
	if (data->nb_bytes && data->nb_bytes == data->i)
	{
		write(1, &data->c, data->nb_bytes);
		while (data->i >= 0)
			data->c[data->i--] = 0;
		restart_args(&data->i, &data->nb_bytes);
	}
}

static void	handler(int signum, siginfo_t *info, void *ucontext)
{
	static t_data	data;

	(void)ucontext;
	if (!data.pid_client)
		data.pid_client = info->si_pid;
	if (info->si_pid != data.pid_client)
	{
		data.pid_client = info->si_pid;
		data.i = 0;
		while (data.i < 4)
			data.c[data.i++] = 0;
		restart_args(&data.i, &data.nb_bytes);
		restart_args(&data.ascii, &data.bits);
	}
	data.ascii = (data.ascii << 1) | (signum == SIGUSR1);
	if (++data.bits == 8)
	{
		if (data.ascii == 0)
			send_sig_received(data.pid_client);
		else if (data.ascii > 127)
			unicode(&data);
		else
			ft_putchar(data.ascii);
		restart_args(&data.ascii, &data.bits);
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
		usleep(1);
	}
	return (0);
}
