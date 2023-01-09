#include "minitalk.h"

static void	receive_len(int *bit, char **str, int *received, int sig)
{
	static int len;

	len = 0;
	if(sig == SIGUSR1)
		len += ft_recursive_power(2, *bit);
	if(*bit == 31)
	{
		*received = 1;
		*str = ft_calloc(len + 1, sizeof(char));
		*bit = 0;
		len = 0;
		return ;
	}
	(*bit)++;
}

static void	restart_vars(int *received, char **str, int *i)
{
	*received = 0;
	if(str)
	{
		ft_putstr(*str);
		write(1, "\n", 1);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

static void	receive_info(int sig)
{
	static int	char_val;
	static int	bit;
	static int	len;
	static int	i;
	static char	*str;

	char_val = 0;
	bit = 0;
	len = 0;
	i = 0;
	str = 0;
	if(!len)
		receive_len(&bit, &str, &len, sig);
	else
	{
		if(sig == SIGUSR1)
			char_val += ft_recursive_power(2, bit);
		if(bit == 7)
		{
			str[i++] = char_val;
			bit = 0;
			if(char_val == 0)
				return(restart_vars(&len, &str, &i));
			char_val = 0;
			return ;
		}
		bit++;
	}
}

int	main()
{
	int id;

	id = (int)(getpid());
	ft_putnbr(id);
	write(1, "\n", 1);
	signal(SIGUSR1, receive_info);
	signal(SIGUSR2, receive_info);
	while(1)
		usleep(100);
}
