/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 02:30:31 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/20 11:35:44 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	all_number(const char *nptr)
{
	int	i;
	int	nb;
	int	signe;

	i = 0;
	nb = 0;
	signe = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (nptr[i] == 48)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb++;
		i++;
		if (nb >= 20)
			return (1);
	}
	return (0);
}

static int	ft_signe(const char *nptr)
{
	int	i;
	int	nb;
	int	signe;

	i = 0;
	nb = 0;
	signe = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = signe * -1;
		i++;
	}
	if (signe == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	signe;

	i = 0;
	nb = 0;
	signe = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = signe * -1;
		i++;
	}
	if (all_number(nptr))
		return (ft_signe(nptr));
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * signe);
}

// int main()
// {
// 	char *str = "     -74484";
// 	printf("%d \n%d", atoi(str), ft_atoi(str));
// }
