#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;
	char 	*ptr;

	ret = 0;
	sign = 1;
	ptr = (char *)nptr;
	if(!ptr)
		return (0);
	while(*ptr >= 0 && *ptr <= 32)
		ptr++;
	if(*ptr == '-' || *ptr == '+')
	{
		if(*ptr == '-')
			sign = -1;
		ptr++;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		ret = ret * 10 + (*ptr - '0');
		ptr++;
	}
	return (sign * ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while(s[i++]);
	return (i - 1);
}

int	ft_isdigit(int c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if(s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	if(n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if(n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if(n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t		i;

	i = 0;
	str = (unsigned char *)s;
	while(i++ < n)
	{
		*str = (char)c;
		str++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if(!ptr)
		exit(0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int     ft_recursive_power(int nb, int power)
{
    if(power < 0)
        return (0);
    else if(power == 0)
        return (1);
    else if(power == 1)
        return (nb);
    else
        return (nb * ft_recursive_power(nb, power - 1));
}
