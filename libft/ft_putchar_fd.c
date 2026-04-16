/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:50:51 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/14 13:08:26 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(int ac, char**av)
// {
// 	if (ac <= 1)
// 		return 1;
// 	ft_putchar_fd(av[1][0], 1);
// 	write(1, "\n", 1);
// }