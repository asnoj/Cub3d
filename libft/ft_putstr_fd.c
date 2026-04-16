/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:55:38 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/21 22:00:26 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int main(int ac, char **av)
// {
// 	if (ac <= 1)
// 		return 1;
// 	ft_putstr_fd(av[1], 1);
// 	write(1, "\n", 1);
// 	return (0);
// }
