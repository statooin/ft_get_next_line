/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 08:20:48 by statooin          #+#    #+#             */
/*   Updated: 2020/07/12 08:21:01 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(char *str)
{
	char	*dest;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!temp)
		return (0);
	dest = temp;
	while (*str)
	{
		*temp = *str;
		temp++;
		str++;
	}
	*temp = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*str;

	if (s1 || s2)
	{
		len1 = (s1) ? ft_strlen(s1) : 0;
		len2 = (s2) ? ft_strlen(s2) : 0;
		if (!(str = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
			return (NULL);
		i = -1;
		if (s1)
			while (s1[++i])
				str[i] = s1[i];
		i = -1;
		if (s2)
			while (s2[++i])
				str[len1++] = s2[i];
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

char		*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size)
		str[size--] = '\0';
	return (str);
}

char		*ft_strchr(const char *s, int cchar)
{
	if (!*s)
		return (NULL);
	while (*s != (char)cchar)
		if (!*s++)
			return (0);
	return ((char *)s);
}
