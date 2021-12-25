/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:31:00 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/25 14:45:27 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	**parse_path(char **env);
char	*parse_cmd(char **path, char **cmd);
int		acces_funct(char *file, int flux);
void	exec(char **path, char *arg);
void	ft_pipex(int infile, int outfile, char **path, char **arg);
void	make_pipex(char **arg, char **env);
#endif
