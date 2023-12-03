/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:06:02 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/03 18:14:49 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putpid(pid_t pid)
{
	long	n;

	n = (long)pid;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
		ft_putpid(n / 10);
	ft_putchar((n % 10) + '0');
}