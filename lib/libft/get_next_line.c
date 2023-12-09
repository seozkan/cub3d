/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:56:37 by seozkan           #+#    #+#             */
/*   Updated: 2023/12/07 16:51:04 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 4

static char	*new_str(char *str)
{
	char	*newstr;
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (!str[len])
	{
		free(str);
		return (NULL);
	}
	newstr = ft_substr(str, len + 1, ft_strlen(str));
	free(str);
	return (newstr);
}

static char	*new_line(char *str)
{
	char	*newline;
	size_t	len;

	len = 0;
	if (!str[len])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	newline = ft_substr(str, 0, len);
	return (newline);
}

static char	*read_file(int fd, char *str, char *buff)
{
	char	*tmp;
	ssize_t	rd_bytes;

	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!str)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	str = read_file(fd, str, buff);
	if (!str)
		return (NULL);
	line = new_line(str);
	str = new_str(str);
	return (line);
}
