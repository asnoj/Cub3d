/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:48:33 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/20 12:11:40 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void uppercase(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = ft_toupper(*c);
// }

// void add_index(unsigned int i, char *c)
// {
// 	printf("[%u]='%c' ", i, *c);
// }

// void print_info(unsigned int i, char *c)
// {
// 	printf("Index %u: %c\n", i, *c);
// }

// int main(void)
// {
// 	char str1[] = "hello";
// 	char str2[] = "world";

// 	printf("Test 1 - Uppercase:\n");
// 	ft_striteri(str1, uppercase);
// 	printf("Result: %s\n\n", str1);

// 	printf("Test 2 - Print with index:\n");
// 	ft_striteri(str2, add_index);
// 	printf("\n\n");

// 	printf("Test 3 - Print info:\n");
// 	ft_striteri(str2, print_info);

// 	return (0);
// }
