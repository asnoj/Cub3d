/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:08:51 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/19 20:17:33 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char charset, char c)
{
	if (charset == c)
		return (1);
	return (0);
}

static int	ft_cmpt_word(char *s, char c)
{
	int	i;
	int	nbrword;

	nbrword = 0;
	i = 0;
	while (s[i] && ft_ischarset(c, s[i]))
		i++;
	while (s[i])
	{
		if (!ft_ischarset(s[i], c) && s[i])
		{
			nbrword++;
			while (!ft_ischarset(s[i], c) && s[i])
				i++;
		}
		else
			i++;
	}
	return (nbrword);
}

static char	*ft_splitdup(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_clear_strs(char **strs, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		cmpt;
	int		i;
	char	**strs;

	strs = (char **)malloc((ft_cmpt_word((char *)s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	cmpt = 0;
	while (s[i])
	{
		if (!ft_ischarset(s[i], c))
		{
			strs[cmpt] = ft_splitdup((char *)&s[i], c);
			if (!strs[cmpt])
				return (ft_clear_strs(strs, cmpt), NULL);
			cmpt++;
			while (!ft_ischarset(s[i], c) && s[i])
				i++;
		}
		else
			i++;
	}
	strs[cmpt] = NULL;
	return (strs);
}

// int	main(int ac, char **av)
// {
// 	if (ac < 4)
// 		return (1);
// 	char **strs = ft_split(av[1], av[2][0]);
// 	printf("%s\n", av[1]);
// 	printf("%s\n", strs[ft_atoi(av[3])]);
// 	int i = 0;
// 	while (strs[i])
// 	{
// 		free(strs[i]);
// 		i++;
// 	}
// }

// int main()
// {
//     char **str;
//     str = ft_split("lorem adipiscing elit. Sed non risus. Suspendisse", ' ');
//     printf("%s", str[0]);
//     printf("%s", str[1]);
//     printf("%s", str[2]);
//     printf("%s", str[3]);
// }
