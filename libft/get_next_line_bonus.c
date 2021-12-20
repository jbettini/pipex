/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:21:25 by jbettini          #+#    #+#             */
/*   Updated: 2021/11/19 19:14:01 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rline(char *save, int fd)
{
	int		ret;
	char	*buf;

	ret = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_isin(save, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			buf = 0;
			return (NULL);
		}
		buf[ret] = 0;
		save = ft_strjoin_gnl(save, buf);
	}
	free(buf);
	return (save);
}

static char	*makeline(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (save[++i] && save[i] != '\n')
		line[i] = save[i];
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static char	*nextline(char *save)
{
	char	*newsave;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i])
	{
		newsave = malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
		if (!newsave)
			return (NULL);
		while (save[i])
			newsave[j++] = save[++i];
		newsave[j] = 0;
		free(save);
		return (newsave);
	}
	else
	{
		free(save);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[FD_MAX];

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = rline(save[fd], fd);
	if (!save[fd])
		return (NULL);
	line = makeline(save[fd]);
	save[fd] = nextline(save[fd]);
	return (line);
}
