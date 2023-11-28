/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:06:43 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/27 09:08:32 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;
	long	tmp;

	i = 0;
	res = 0;
	sign = check_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = (res * 10) + (str[i] - '0');
		if (res > tmp && sign == 1)
			return (-1);
		else if (res > tmp && sign == -1)
			return (0);
		res = tmp;
		i++;
	}
	return (res * sign);
}
