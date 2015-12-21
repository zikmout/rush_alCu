/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 03:03:33 by abary             #+#    #+#             */
/*   Updated: 2015/12/21 16:40:48 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *first)
{
	t_list *tmp;

	tmp = first;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstdel_zero(t_list *first)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = first;
	tmp2 = NULL;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	tmp = NULL;
	if (tmp2)
		tmp2->next = NULL;
}

int		ft_len_list(t_list *first)
{
	int		nbr;
	t_list	*tmp;

	nbr = 0;
	tmp = NULL;
	tmp = first;
	while (tmp)
	{
		++nbr;
		tmp = tmp->next;
	}
	return (nbr);
}

t_list	*new_node(int bytes)
{
	t_list *node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return ((t_list *)NULL);
	node->content = bytes;
	node->next = (t_list *)NULL;
	return (node);
}
