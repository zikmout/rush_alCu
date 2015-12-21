/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_matches.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 02:34:05 by abary             #+#    #+#             */
/*   Updated: 2015/12/21 16:44:23 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_solve_even(int nbr)
{
	int result;

	result = (nbr - 4) % 4;
	if (result == 0)
		++result;
	else if (result < 0)
		result += 4;
	return (result);
}

static int		ft_solve_odd(int nbr)
{
	int result;

	result = (nbr - 5) % 4;
	if (result == 0)
		++result;
	else if (result < 0)
		result += 4;
	return (result);
}

int				ft_solve_matches(t_list *line, int nbrline)
{
	int result;

	result = 0;
	if (nbrline % 2 == 0)
		result = ft_solve_even(line->content);
	else
		result = ft_solve_odd(line->content);
	return (result);
}
