/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:38:36 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/25 14:40:44 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	acces_funct(char *file, int flux)
{
	if (flux == 0)
	{
		if (access(file, F_OK) == -1)
		{
			perror("infile ");
			return (0);
		}
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_CREAT | O_RDWR | O_TRUNC, 0644));
}

void	exec(char **path, char *arg)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(arg, ' ');
	cmd_path = parse_cmd(path, cmd);
	if (cmd_path)
	{
		execve(cmd_path, cmd, NULL);
		free(cmd_path);
	}
	ft_free_split(cmd);
	exit(0);
}

void	ft_pipex(int infile, int outfile, char **path, char **arg)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (!pid)
	{
		dup2(infile, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		if (infile)
			exec(path, arg[1]);
		waitpid(pid, NULL, 0);
	}
	if (pid)
	{
		dup2(outfile, 1);
		dup2(fd[0], 0);
		close(fd[1]);
		exec(path, arg[2]);
	}
}

void	make_pipex(char **arg, char **env)
{
	int		infd;
	int		outfd;
	char	**path;

	path = parse_path(env);
	infd = acces_funct(arg[0], 0);
	outfd = acces_funct(arg[3], 1);
	ft_pipex(infd, outfd, path, arg);
	ft_free_split(path);
}

int	main(int ac, char **av, char **env)
{
	char	**arg;

	if (ac >= 5)
	{
		arg = &av[1];
		make_pipex(arg, env);
	}
	else
		perror("Invalid number of argument");
	return (0);
}
