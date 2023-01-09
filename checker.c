#include "minitalk.h"

int	isnum(char *num)
{
	int	i;

	i = 0;
	if(num[0] == '-')
		return (0);
	while(num[i])
	{
		if(!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	if(ac != 3)
	{
		write(2, "The program accepts only 2 parameters.\n", 40);
		write(2, "First parameter should be a valid pid.\nSecond parameter should be a string.\n", 76);
		exit(0);
	}
	if(!isnum(av[1]))
	{
		write(2, "First parameter should be a valid pid\n", 39);
		exit(0);
	}
}
