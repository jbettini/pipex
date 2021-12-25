/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:38:01 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/25 14:38:18 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_path(char **env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", ft_strlen(env[i])))
		i++;
	while (ft_isin("PATH=", env[i][j]) && env[i])
		j++;
	return (ft_split(env[i] + j, ':'));
}

char	*parse_cmd(char **path, char **cmd)
{
	char	*cmd_path;
	char	*tmp;
	size_t	i;

	tmp = ft_strjoin("/", cmd[0]);
	i = -1;
	while (path[++i])
	{
		cmd_path = ft_strjoin(path[i], tmp);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free(tmp);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free(tmp);
	perror("command not found ");
	return (NULL);
}
