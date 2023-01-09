#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int	ft_isdigit(int c);
void	check_args(int ac, char **av);
void	ft_putstr(const char *s);
void	ft_putnbr(int n);
void	*ft_calloc(size_t nmemb, size_t size);
int	ft_recursive_power(int nb, int power);

#endif
