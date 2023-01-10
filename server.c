#include "minitalk.h"

static void	receive_len(int *bit, char **str, int *is_alloc, int sig)
{
	static int len;

	len = 0;
	if(sig == SIGUSR1)
		len += ft_recursive_power(2, *bit);
	if(*bit == 31)
	{
		*is_alloc = 1;
		*str = ft_calloc(len + 1, sizeof(char));
		*bit = 0;
		len = 0;
		return ;
	}
	(*bit)++;
}

static void	restart_vars(int *is_alloc, char **str, int *i)
{
	*is_alloc = 0;
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
	static int	char_val = 0;
	static int	bit = 0;
	static int	is_alloc = 0;
	static int	i = 0;
	static char	*str = 0;

	if(!is_alloc)
		receive_len(&bit, &str, &is_alloc, sig);
	else
	{
		if(sig == SIGUSR1)
			char_val += ft_recursive_power(2, bit);
		if(bit == 7)
		{
			str[i++] = char_val;
			bit = 0;
			if(char_val == 0)
				return(restart_vars(&is_alloc, &str, &i));
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
