/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:44:57 by arupert           #+#    #+#             */
/*   Updated: 2022/01/11 19:42:37 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == (char)c)
			return (str + i);
		i++;
	}
	if (c == 0)
		return (str + i);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	if (!s)
		return (0);
	while (*(s + l) != '\0')
		l++;
	return (l);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	j;
	size_t	i;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		*s1 = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (s == NULL)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i] != '\0')
			s[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i] = '\0';
	free(s1);
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!dest || !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	act_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		len = 0;
	act_len = ft_strlen(s + start);
	if (act_len > len)
		act_len = len;
	str = malloc(sizeof(char) * (act_len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < act_len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
