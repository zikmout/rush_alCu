/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matches.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:45:49 by abary             #+#    #+#             */
/*   Updated: 2015/12/21 06:58:23 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_matches(t_list *first)
{
	t_list	*tmp;
	int		pipe;

	pipe = 0;
	tmp = first;
	while (tmp)
	{
		pipe = tmp->content;
		while (pipe > 0)
		{
			ft_putchar('|');
			if (pipe != 1)
				ft_putchar(' ');
			--pipe;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
