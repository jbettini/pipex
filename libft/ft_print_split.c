/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:21:27 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/21 18:21:42 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_print_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        write(1, "str ", 4);
        ft_putnbr(i + 1);
        write(1, " of split\n", 10);
        ft_putstr(split[i]);
        write(1, "\n\n", 2);
        i++;
    }
}