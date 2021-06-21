/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:24:32 by statooin          #+#    #+#             */
/*   Updated: 2020/07/11 12:19:28 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		free_n_return(char **remainder, char **buff, int ret)
{
	if (*buff != NULL)
		free(*buff);
	if (*remainder != NULL)
		free(*remainder);
	*remainder = NULL;
	*buff = NULL;
	return (ret);
}

int		remainder_to_line(char **remainder, char **p_n, char **line)
{
	char	*tmp;

	**p_n = '\0';
	*p_n = *p_n + 1;
	*line = ft_strdup(*remainder);
	tmp = ft_strdup(*p_n);
	if (*remainder != NULL)
		free(*remainder);
	if (tmp == NULL || *line == NULL || *remainder == NULL)
		return (-1);
	*remainder = tmp;
	tmp = NULL;
	*p_n = NULL;
	return (1);
}

int		buff_to_remainder(char *buff, char **remainder, int byte_was_read)
{
	char	*tmp;

	buff[byte_was_read] = '\0';
	if ((tmp = ft_strjoin(*remainder, buff)) == NULL)
		return (-1);
	if (*remainder != NULL)
		free(*remainder);
	*remainder = tmp;
	tmp = NULL;
	return (1);
}

int		read_next_buff(char **remainder, char **line, int fd)
{
	int		byte_was_read;
	char	*p_n;
	char	*buff;

	if ((buff = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
		return (-1);
	byte_was_read = 1;
	while (!(p_n = ft_strchr(*remainder, '\n')) && byte_was_read > 0)
	{
		byte_was_read = read(fd, buff, BUFFER_SIZE);
		if (byte_was_read > 0)
			if (buff_to_remainder(buff, remainder, byte_was_read) == -1)
				return (-1);
	}
	if (byte_was_read < 0)
		return (free_n_return(remainder, &buff, -1));
	if (!(p_n = ft_strchr(*remainder, '\n')))
	{
		if ((*line = ft_strdup(*remainder)) == NULL)
			return (-1);
		return (free_n_return(remainder, &buff, *line ? 0 : -1));
	}
	if (buff != NULL)
		free(buff);
	return (remainder_to_line(remainder, &p_n, line));
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*p_n;
	static char	*fd_remainders[1024];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (fd_remainders[fd] == NULL)
	{
		if ((remainder = ft_strnew(0)) == NULL)
			return (-1);
		fd_remainders[fd] = remainder;
	}
	if ((p_n = ft_strchr(remainder, '\n')))
		return (remainder_to_line(&fd_remainders[fd], &p_n, line));
	return (read_next_buff(&fd_remainders[fd], line, fd));
}
