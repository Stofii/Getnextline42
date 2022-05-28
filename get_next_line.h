/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:30:53 by dstopfer          #+#    #+#             */
/*   Updated: 2022/05/27 19:08:34 by dstopfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*strjoin(char *str1, char *str2);
size_t		strlen(const char *s);
char		*strchr(const char *str, int c);
size_t		strlcpy(char *dst, const char *src, size_t size);
char		*substr(char *str, unsigned int start, size_t len);
char		*gstrdup(char *str);

#endif