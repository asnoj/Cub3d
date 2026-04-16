/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:40:14 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/16 20:40:28 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_v(long nbr, char *str, int *i)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		str[*i] = '-';
		*i = *i + 1;
	}
	if (nbr >= 10)
		ft_itoa_v(nbr / 10, str, i);
	str[(*i)++] = nbr % 10 + '0';
	return (str);
}

static int	ft_cmptint(int n)
{
	int		count;
	long	nbr;

	nbr = n;
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		i;

	i = 0;
	nbr = n;
	str = (char *)malloc((ft_cmptint(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_itoa_v(nbr, str, &i);
	str[i] = '\0';
	return (str);
}

// int	main(int ac, char **av)
// {
// 	if (ac <= 1)
// 		return 1;
// 	char *ptr = ft_itoa(ft_atoi(av[1]));
// 	ft_putendl_fd(ptr, 1);
// 	free(ptr);
// }
