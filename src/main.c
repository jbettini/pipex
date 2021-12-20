/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:30:09 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/20 02:01:56 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int acces_funct(char *file, int mode)
{
    if (mode == 1)
    {
        if (access(file, F_OK))
        {
            perror("No such file or directory\n");
            return (0);
        }
        return (open(file, O_RDONLY));
    }
    else
        return (open(file, O_CREAT | O_RDWR | O_TRUNC, 0644));
}

void    pipex(char **arg, char **env)
{
    int infd;
    int outfd;

    infd = acces_funct(arg[1], 1);
    outfd = acces_funct(arg[4], 0);
}

int main(int ac, char **av, char **env)
{
    if (ac == 5)
    {
        char    **arg;

        arg = &av[1];
        pipex(arg, env);
    }
    else
        perror("Invalid Argument/n");
    return (0);
}