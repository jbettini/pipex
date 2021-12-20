/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:21:38 by jbettini          #+#    #+#             */
/*   Updated: 2021/11/04 19:21:44 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isin(char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *save, char *buf)
{
	size_t	i;
	size_t	j;
	char	*newsave;

	i = -1;
	j = 0;
	if (!save)
	{
		save = ft_calloc(1, 1);
		if (!save)
			return (NULL);
	}
	if (!buf)
		return (NULL);
	newsave = malloc(sizeof(char) * ft_strlen(save) + ft_strlen(buf) + 1);
	if (!newsave)
		return (NULL);
	if (save)
		while (save[++i])
			newsave[i] = save[i];
	while (buf[j])
		newsave[i++] = buf[j++];
	newsave[i] = 0;
	free(save);
	return (newsave);
}
