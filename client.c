#include "minitalk.h"

static void	send_char(unsigned char c, int pid)
{
	int	j;

	j = 0;
while(j < 8)
	{
		if(c & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(100);
		j++;
	}
}

static void	send_len(int len, int pid)
{
	int	i;

	i = 0;
	while(i < 32)
	{
		if(len & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len = len >> 1;
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	char	*str;
	int	len;
	int	i;

	check_args(ac, av);
	pid = ft_atoi(av[1]);
	if(pid <= 0)
		return (-1);
	str = av[2];
	len = ft_strlen(str);
	send_len(len, pid);
	i = 0;
	while(str[i])
	{
		send_char(str[i], pid);
		i++;
	}
	send_char(str[i], pid);
	return (0);
}
