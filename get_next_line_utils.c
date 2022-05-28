/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:31:09 by dstopfer          #+#    #+#             */
/*   Updated: 2022/05/23 18:45:25 by dstopfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin(char *str1, char *str2)
{
	char	*out;
	size_t	str1len;
	size_t	str2len;

	if (!str1 || !str2)
		return (0);
	str1len = strlen(str1);
	str2len = strlen(str2);
	out = malloc((str1len + str2len + 1) * sizeof(char));
	if (!out)
		return (0);
	strlcpy(out, str1, str1len + 1);
	free(str1);
	strlcpy(out + str1len, str2, str2len + 1);
	return (out);
}

char	*strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((*s) == (char)c)
		return ((char *)(s));
	return (NULL);
}

size_t	strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*substr(char *str, unsigned int start, size_t len)
{
	char	*out;
	size_t	slen;

	slen = strlen(str);
	if (!str)
		return (NULL);
	if (start >= slen)
		return (gstrdup(""));
	if (len > slen - start)
		return (gstrdup(str + start));
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	strlcpy(out, str + start, len);
	free (str);
	out[len] = '\0';
	return (out);
}

char *gstrdup(char *str)
{
	size_t	len;
	char	*out;

	len = strlen((char *)str) + 1;
	out = malloc(len * sizeof(char));
	if (!out)
		return (NULL);
	strlcpy (out, str, len + 1);
	free (str);
	return (out);
}