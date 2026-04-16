/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:01:18 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/14 13:08:33 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	result;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(fd, "-", 1);
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	result = nbr % 10 + '0';
	write(fd, &result, 1);
}

// int	ft_atoi(char *str)
// {
// 	int	result;
// 	int	sign;
// 	int	i;

// 	sign = 1;
// 	result = 0;
// 	i = 0;
// 	if (str[i] == '-')
// 	{
// 		sign *= -1;
// 		i++;
// 	}
// 	while(str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (result * sign);
// }

// int main(int ac, char **av)
// {
// 	if (ac <= 2)
// 		return (1);
// 	ft_putnbr_fd(ft_atoi(av[1]), ft_atoi(av[2]));
// 	write(1, "\n", 1);
// }
