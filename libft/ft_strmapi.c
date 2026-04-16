/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:46:57 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/14 14:00:17 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*dest;

	if (!s || !f)
		return (NULL);
	i = 0;
	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// char capitalize_even(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (char)ft_toupper((int)c);
// 	else
// 		return (char)ft_tolower((int)c);
// }
// int	main(int ac, char **av)
// {
// 	if (ac < 2)
// 		return 1;
// 	ft_putendl(av[1]);
// 	ft_putendl(ft_strmapi(av[1], capitalize_even));
// }
