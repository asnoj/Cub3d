/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 23:14:15 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/07 19:35:25 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define MAX_FD 1024

char	*get_next_line(int fd);
//size_t	ft_strlen(char *str);
//char	*ft_strdup(char *s);
//char	*ft_strchr(char *str, int c);
//char	*ft_strjoin(char *s1, char *s2);
//char	*ft_substr(char *s, unsigned int start, size_t len);

#endif