/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:45:05 by arupert           #+#    #+#             */
/*   Updated: 2022/01/11 19:12:09 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extend_until_find_line_feed(int fd, char *tmp)
{
	char	*buf;
	int		read_piece;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_piece = 1;
	while (read_piece > 0 && !ft_strchr(tmp, (int) '\n'))
	{
		read_piece = read(fd, buf, BUFFER_SIZE);
		if (read_piece < 0)
		{
			free(buf);
			return (tmp);
		}
		if (read_piece >= 0)
		{
			buf[read_piece] = '\0';
			tmp = ft_strjoin(tmp, buf);
		}
	}
	free(buf);
	return (tmp);
}

static char	*extract_the_first_paragraph(char *tmp)
{
	size_t	i;
	char	*line;

	if (!(*tmp))
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line = ft_memcpy(line, tmp, i);
	line[i] = '\0';
	return (line);
}

static char	*trim_before_line_feed(char *tmp)
{
	int		i;
	char	*tmp2;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\0')
	{
		free (tmp);
		return (NULL);
	}
	tmp2 = ft_substr(tmp, i + 1, ft_strlen(tmp) - i - 1);
	if (!tmp2)
		return (NULL);
	free(tmp);
	return (tmp2);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = extend_until_find_line_feed(fd, tmp);
	if (!tmp)
		return (NULL);
	line = extract_the_first_paragraph(tmp);
	tmp = trim_before_line_feed(tmp);
	return (line);
}
