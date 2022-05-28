/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:30:28 by dstopfer          #+#    #+#             */
/*   Updated: 2022/05/27 19:14:20 by dstopfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

static char	*trim_line(char *line, char *remainder)
{
	ssize_t	remlen;
	size_t	linelen;

	linelen = 0;
	while (line[linelen] != '\n' && line[linelen])
		linelen++;
	if (line[linelen] == '\n')
		linelen++;
	remlen = (strlen(line) - linelen);
	if (remlen != 0)
		strlcpy(remainder, line + linelen, remlen + 1);
	else
		remainder[0] = '\0';
	return (substr(line, 0, linelen + 1));
}

static char	*read_line(char *line, char *buf, int fd)
{
	ssize_t	buflen;

	buflen = BUFFER_SIZE;
	while (!(strchr(buf, '\n')) && buflen == BUFFER_SIZE)
	{
		buflen = read(fd, buf, BUFFER_SIZE);
		buf[buflen] = '\0';
		if (buflen <= 0 && !line[0])
		{
			free (line);
			return (NULL);
		}
		line = strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (buf[0] != '\0')
		line = strjoin(line, buf);
	line = read_line(line, buf, fd);
	if (!line)
		return (NULL);
	line = trim_line(line, buf);
	if (buf <= 0 && !line[0])
	{
		free (line);
		return (NULL);
	}
	return (line);
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("aaaa.txt", O_RDONLY);
	if (!fd)
		return (0);
	while (1 == 1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break ;
	}
	close(fd);
	perror("Error: ");
	return (0);
}
