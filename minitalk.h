/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 05:34:49 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/24 06:15:50 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	check_args(int argc, char **argv);
void	ft_putstr_fd(char *s, int fd);
void 	ft_putnbr_fd(int n, int fd);
void	*ft_calloc(size_t count, size_t size);
int		ft_recursive_power(int nb, int power);

#endif