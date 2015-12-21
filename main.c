/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:03:20 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/21 16:32:05 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define BUFF_SIZE 1

int	main(int ac, char **av)
{
	if (ac > 2)
		ft_putstr_fd("ERROR\n", 2);
	else
	{
		if (!ft_open(av[1]))
			ft_putstr_fd("ERROR\n", 2);
	}
	return (0);
}
