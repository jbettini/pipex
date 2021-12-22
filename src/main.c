/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:30:09 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/22 06:39:43 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int acces_funct(char *file, int flux)
{
    if (flux == 0)
    {
        if (access(file, F_OK) == -1)
        {
            perror("No such file or directory\n");
            return (0);
        }
        return (open(file, O_RDONLY));
    }
    else
        return (open(file, O_CREAT | O_RDWR | O_TRUNC, 0644));
}
void    ft_close(int fd, int fd1, int fd2, int fd3)
{
    close(fd);
    close(fd1);
    close(fd2);
    close(fd3);
}

void    exec(char **path, char *arg, char **env)
{
    char    **cmd;
    char    *cmd_path;
    
    cmd = ft_split(arg, ' ');
    cmd_path = parse_cmd(path, cmd);
    if (cmd_path)
        execve(cmd_path, cmd, env);
    printf("\n\nPATH: %s\n\n",cmd_path);
    free(cmd_path);
    ft_free_split(cmd);
}

void    pipex(int infile, int outfile, char **path, char **arg, char **env)
{
    int fd[2];
    int pid;

    pipe(fd);
    pid = fork();
    if (pid)
    {
        dup2(fd[1], 1);
        dup2(infile, 0);
        ft_close(infile, outfile, fd[0], fd[1]);
        exec(path, arg[1], env);
        waitpid(pid, NULL, 0);
    }
    if (!pid)
    {
        dup2(fd[0], 0);
        dup2(outfile, 1);
        ft_close(infile, outfile, fd[0], fd[1]);
        exec(path, arg[2], env);
    }
}

void    make_pipex(char **arg, char **env)
{
    int     infd;
    int     outfd;
    char    **path;

    path = parse_path(env);
    infd = acces_funct(arg[0], 0);
    outfd = acces_funct(arg[3], 1);
    pipex(infd, outfd, path, arg, env);
    ft_free_split(path);
}

int main(int ac, char **av, char **env)
{
    char    **arg;

    if (ac >= 5)
    {
        arg = &av[1];
        make_pipex(arg, env);
    }
    else
        perror("Invalid Argument");
    system("leaks pipex");
    return (0);
}